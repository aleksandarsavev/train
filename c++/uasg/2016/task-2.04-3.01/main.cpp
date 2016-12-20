// task-2.13-2.08
#include <fstream>
#include <iostream>

using namespace std;

int M = 0;
int N = 0;

float** X,Y;

float** loadMatrix(const char* filename) {
    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file.\n";
        return NULL;
    }
    
    in >> M;
    in >> N;

    X = new float*[M];
    Y = new float*[M];
    
    for(int i = 0; i < M; i++) {
        X[i] = new float[N];
        Y[i] = new float[N];
    }
    
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            in >> X[y][x];
        }
    }
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            in >> Y[y][x];
        }
    }

    in.close();
    return X;
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
    loadMatrix("input.txt");
    cout << "Input (matrix X):" << '\n';
    printMatrix(X);

    cout << "Input (matrix Y):" << '\n';
    printMatrix(Y);
    cout << "The matrix X is a " << (M == N ? "square" : "rectangle") << "."  << '\n';
 
    if (M == N) {
        
    }

    cout << "X - Z = \n";
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cout << X[y][x] - Y[y][x] << "  ";
        }
        cout << '\n';
    }

    return 0;
}
