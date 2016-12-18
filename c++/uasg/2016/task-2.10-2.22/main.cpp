// task-2.10-2.22
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int N = 0;

float** loadMatrix(const char* filename) {
    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file.\n";
        return NULL;
    }
    
    in >> N;

    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new float[N];
    
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            in >> matrix[y][x];

    in.close();
    return matrix;
}

void printMatrix(float** matrix) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << matrix[y][x] << "  ";
        }
        cout << '\n';
    }
}

bool descending(float a, float b) { return a > b; }

float** sortMatrix(float** source) {
    // copying the matrix
    float** matrix = new float*[N];
    for (int y = 0; y < N; y++) {
        matrix[y] = new float[N];
        for (int x = 0; x < N; x++) {
            matrix[y][x] = source[y][x];
        }
    }

    // sorting
    for (int y = 0; y < N; y++) {
        if (y % 2 == 0) {
            // ascending
            sort(matrix[y], matrix[y] + N);
        } else {
            // descending
            sort(matrix[y], matrix[y] + N, descending);
        }
    }
    return matrix;
}

void multiplyDiagonals(float** source, float coeff) {    
    for (int y = 0; y < N; y++) {
        source[y][y] *= coeff;
        if (2 * y - N + 1 == 0)
            // if N is odd we should not multiply the
            // center twice
            continue;
        source[y][N - y - 1] *= coeff;
    }
}

float average(float** matrix) {
    float sum = 0;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            sum += matrix[y][x];
    return sum / N / N;
}

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input:" << '\n';
    printMatrix(input);
    float** sorted = sortMatrix(input);
    cout << "Sorted:" << '\n';
    printMatrix(sorted);
    float aver = average(input);
    cout << "Average: " << aver << '\n';
    multiplyDiagonals(input, aver);
    cout << "Multiplied diagonals(of input matrix) by average:" << '\n';
    printMatrix(input);
    cout << endl;

    return 0;
}
