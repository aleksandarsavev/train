// task-2.13-2.08
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

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input (matrix A):" << '\n';
    printMatrix(input);

    cout << "The matrix is a " << (M == N ? "square" : "rectangle") << "."  << '\n';
 
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

    // Sums rows
    for (int y = 0; y < M; y++) {
        int result = 0;
        for (int x = 0; x < N; x++) {
            result += input[y][x];
        }
        cout << "Sum of row [" << y << "] = " << result << '\n'; 
    }

    // Sums columns
    for (int x = 0; x < N; x++) {
        int result = 0;
        for (int y = 0; y < M; y++) {
            result += input[y][x];
        }
        cout << "Sum of column [" << x << "] = " << result << '\n'; 
    }

    // Product rows
    for (int y = 0; y < M; y++) {
        int result = 1;
        for (int x = 0; x < N; x++) {
            result *= input[y][x];
        }
        cout << "Product of row [" << y << "] = " << result << '\n'; 
    }

    // Product columns
    for (int x = 0; x < N; x++) {
        int result = 1;
        for (int y = 0; y < M; y++) {
            result *= input[y][x];
        }
        cout << "Product of column [" << x << "] = " << result << '\n'; 
    }

    // Minimum rows
    for (int y = 0; y < M; y++) {
        int result = input[y][0];
        for (int x = 1; x < N; x++) {
            result = result < input[y][x] ? result : input[y][x];
        }
        cout << "Minimum of row [" << y << "] = " << result << '\n'; 
    }

    // Minimum columns
    for (int x = 0; x < N; x++) {
        int result = input[0][x];
        for (int y = 0; y < M; y++) {
            result = result < input[y][x] ? result : input[y][x];
        }
        cout << "Minimum of column [" << x << "] = " << result << '\n'; 
    }

    // Maximum rows
    for (int y = 0; y < M; y++) {
        int result = input[y][0];
        for (int x = 1; x < N; x++) {
            result = result > input[y][x] ? result : input[y][x];
        }
        cout << "Maximum of row [" << y << "] = " << result << '\n'; 
    }

    // Maximum columns
    for (int x = 0; x < N; x++) {
        int result = input[0][x];
        for (int y = 0; y < M; y++) {
            result = result > input[y][x] ? result : input[y][x];
        }
        cout << "Maximum of column [" << x << "] = " << result << '\n'; 
    }

    return 0;
}
