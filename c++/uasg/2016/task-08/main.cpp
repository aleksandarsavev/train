// task-08
#include <fstream>
#include <iostream>

using namespace std;

int N = 0;

float** loadMatrix(const char* filename) {
    // opening an input file stream
    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file.\n";
        return NULL;
    }
    
    // reading the count of rows
    in >> N;

    // initialize an empty matrix N x N
    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new float[N];
    
    // reading the matrix from file
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            in >> matrix[y][x];

    in.close();
    return matrix;
}

void printMatrix(float** matrix) {
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            // print the values of matrix rounded up to the
            // second digit after the decimal point
            cout << (int)(matrix[y][x] * 100) / 100.0 << "  ";
        }
        cout << '\n';
    }
}

float** buildMatrix(float** source) {
    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new float[N];
    
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            // if the sum x + y is even
            if ((x + y) % 2 == 0)
                matrix[y][x] = source[y][x] + source[x][y];
            // if the sum x + y is odd
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
