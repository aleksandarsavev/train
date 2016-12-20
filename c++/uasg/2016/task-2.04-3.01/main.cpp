// task-2.04-3.01
#include <fstream>
#include <iostream>

using namespace std;

int M = 0;
int N = 0;

float **X;
float **Y;

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
        int positives = 0;
        float sump = 0;
        int negatives = 0;
        float sumn = 0;

        for (int y = 0; y < M; y++) {
            for (int x = y + 1; x < N; x++) {
                if(X[y][x] > 0) {
                    positives++;
                    sump += X[y][x];
                } else if (X[y][x] < 0){
                    negatives++;
                    sumn += X[y][x];
                }
            }
        }

        cout << "Average of the positive numbers over the main diagonal: " << sump / positives << '\n';
        cout << "Average of the negative numbers over the main diagonal: " << sumn / negatives << '\n';
    }

    cout << "X + Y = \n";
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cout << X[y][x] + Y[y][x] << "  ";
        }
        cout << '\n';
    }
    cout << "X - Y = \n";
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            cout << X[y][x] - Y[y][x] << "  ";
        }
        cout << '\n';
    }

    return 0;
}
