// task-04
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

    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
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
            cout << (int)(matrix[y][x] * 100) / 100.0 << "  ";
        }
        cout << '\n';
    }
}

float** buildMatrix(float** source) {
    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new float[N];
    
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            matrix[y][x] = 0;
            for (int i = 0; i < N; i++) {
                matrix[y][x] += source[y][i] * source[i][x];
            }
        }
    }
    return matrix;
}

int countPositiveNumbers(float** matrix) {
    int counter = 0;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            if (matrix[y][x] > 0)
                counter++;
    return counter;
}

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input (matrix A):" << endl;
    printMatrix(input);

    if (M != N) {
        cout << "The matrix must be a square to perform the operation." << endl;
        return 0;
    }

    float ** result = buildMatrix(input);
    cout << endl << "Scalar product matrix (matrix B):" << endl;
    printMatrix(result);
    cout << endl << "Positive numbers in matrix A: " << countPositiveNumbers(input);
    cout << endl << "Positive numbers in matrix B: " << countPositiveNumbers(result) << endl;
    return 0;
}
