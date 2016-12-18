// task-03
#include <fstream>
#include <iostream>
#include <math.h>

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
            cout << floorf(matrix[y][x] * 100) / 100 << "  ";
        }
        cout << '\n';
    }
}

int* countPositives(float** matrix) {
    int* vector = new int[M];
    for (int i = 0; i < M; i++) 
        vector[i] = 0;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            vector[y] += matrix[y][x] > 0 ? 1 : 0;
    return vector;
}

int* countNegatives(float** matrix) {
    int* vector = new int[M];
    for (int i = 0; i < M; i++) 
        vector[i] = 0;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            vector[y] += matrix[y][x] < 0 ? 1 : 0;
    return vector;
}

void printVector(int* vector) {
    cout << "(" << vector[0];
    for (int i = 1; i < M; i++)
        cout << ", " << vector[i];
    cout << ")";
}

int sum(int* vector) {
    int sum = 0;
    for (int i = 1; i < M; i++) 
        sum += vector[i];
    return sum;   
}

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input (matrix A):" << endl;
    printMatrix(input);
    int* B = countPositives(input);
    int* C = countNegatives(input);

    cout << "B = ";
    printVector(B);
    cout << endl; 

    cout << "C = ";
    printVector(C);
    cout << endl; 

    int sumB = sum(B);
    int sumC = sum(C);

    if (sumB > sumC) {
        cout << "The matrix A has more positive elements." << endl;
    } else if (sumB < sumC) {
        cout << "The matrix A has more negative elements." << endl;
    } else {
        cout << "The matrix A has as many positive as negative elements." << endl;
    }

    return 0;
}
