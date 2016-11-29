#include <istream>
#include <string>
#include <fstream>
#include <iostream>

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
            in >> matrix[x][y];

    in.close();
    return matrix;
}

void printMatrix(float** matrix) {
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

float** buildMatrix(float** source) {
    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new float[N];
    
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            if ((i + j) % 2 == 0)
                matrix[i][j] = source[i][j] + source[i][j];
            else
                matrix[i][j] = source[i][j] - source[i][j];
            
    return matrix;
}

int main() {
    float ** input = loadMatrix("input.txt");
    printMatrix(input);
    float ** result = buildMatrix(input);
    printMatrix(result);
}
