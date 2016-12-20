// task-2.23-2.24
#include <fstream>
#include <iostream>

using namespace std;

int M = 0;
int N = 0;

float** loadMatrix(const char* filename) {
    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file.\n";
        return NULL;
    }
    
    in >> M;
    in >> N;

    float** matrix = new float*[M];
    for(int i = 0; i < M; i++)
        matrix[i] = new float[N];
    
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            in >> matrix[y][x];

    in.close();
    return matrix;
}

void printMatrix(float** matrix) {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cout << matrix[y][x] << "  ";
        }
        cout << '\n';
    }
}

void printMatrixAdd(float** matrix, float add) {
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (x == y || y == N - x - 1) {
                cout << matrix[y][x] + add << "  ";
            } else {
                cout << matrix[y][x] << "  ";
            }
        }
        cout << '\n';
    }
}

float getMaximum(float** matrix) {
    float max = matrix[0][0];
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            max = (matrix[y][x] < max) ? max : matrix[y][x];
    return max;
}

float getMinimum(float** matrix) {
    float min = matrix[0][0];
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            min = (matrix[y][x] > min) ? min : matrix[y][x];
    return min;
}

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input (matrix A):" << '\n';
    printMatrix(input);

    cout << "The matrix is a " << (M == N ? "square" : "rectangle") << "."  << '\n';
 
    if (M == N) {
        float min = getMinimum(input);
        cout << "Minimum = " << min << '\n';
        printMatrixAdd(input, min);

        float max = getMaximum(input);
        cout << "Maximum = " << max << '\n';
        printMatrixAdd(input, -max);
    }
    return 0;
}
