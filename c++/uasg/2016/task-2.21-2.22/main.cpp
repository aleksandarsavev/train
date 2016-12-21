// task-2.10-2.22
#include <fstream>
#include <iostream>
#include <algorithm>

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

float average(float** matrix) {
    float sum = 0;
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            sum += matrix[y][x];
    return sum / N / M;
}

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input:" << '\n';
    printMatrix(input);
    float aver = average(input);
    cout << "Average: " << aver << '\n';
 
    cout << "Multiply positives by average:" << '\n';
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (input[y][x] > 0) {
                cout << input[y][x] * aver << ' ';
            } else {
                cout << input[y][x] << ' ';
            }
        }
        cout << '\n';
    }

    cout << "Multiply negatives by average:" << '\n';
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (input[y][x] < 0) {
                cout << input[y][x] * aver << ' ';
            } else {
                cout << input[y][x] << ' ';
            }
        }
        cout << '\n';
    }

    cout << "Multiplied diagonals(of input matrix) by average:" << '\n';
    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            if (y == x || y + x == N - 1) {
                cout << input[y][x] * aver << ' ';
            } else {
                cout << input[y][x] << ' ';
            }
        }
        cout << '\n';
    }

    cout << endl;

    return 0;
}
