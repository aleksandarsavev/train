// task-2.13-2.20
#include <istream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

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
        for (int x = 0; x < N; x++)
            cout << setw(7) << setprecision(3) << matrix[y][x] << ' ';
        cout << endl;
    }
}

float getMaximum(float** matrix) {
    float max = matrix[0][0];
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            max = (matrix[y][x] < max) ? max : matrix[y][x];
    return max;
}

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input (matrix A):" << endl;
    printMatrix(input);

    cout << "The matrix is a " << (M == N ? "square" : "rectangle") << "."  << endl;
 
    if (M == N) {
        int K = -1;
        while (K < 0){
            cout << "Enter a column K [1-" << M << "]: ";
            cin >> K;
            if (K < 1 || K > M) K = -1;
        }

        float result = 0;
        for (int i = 0; i < M; i++)
            result += input[i][i] * input[i][K - 1];
        cout << "Dot product (K = " << K << "): " << result << endl;
    }

    float maximum = getMaximum(input);
    cout << "Maximum of matrix A = " << maximum << endl;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            if (input[y][x] < 0)
                cout << "A[" << y << "]" << "[" << x << "] * " << input[y][x] << " = " << input[y][x] * maximum << endl;

    return 0;
}
