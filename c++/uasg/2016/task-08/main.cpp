#include <istream>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

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
        for (int x = 0; x < N; x++)
            cout << setw(7) <<  setprecision(3) << matrix[y][x] << ' ';
        cout << endl;
    }
}

float** buildMatrix(float** source) {
    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new float[N];
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            if ((x + y) % 2 == 0)
                matrix[y][x] = source[y][x] + source[x][y];
            else
                matrix[y][x] = source[y][x] - source[x][y];
            
    return matrix;
}

int positivesOverMainDiagonal(float** matrix) {
    int counter = 0;
    for (int y = 0; y < N; y++)
        for (int x = y + 1; x < N; x++)
            if (matrix[y][x] > 0)
                counter++;
    return counter;
}

int main() {
    float ** input = loadMatrix("input.txt");
    cout << "Input:" << endl;
    printMatrix(input);
    float ** result = buildMatrix(input);
    cout << endl << "Matrix B:" << endl;
    printMatrix(result);
    cout << endl << "Positive numbers (greater than 0) over the main diagonal of matrix B: " << positivesOverMainDiagonal(result) << endl;
}
