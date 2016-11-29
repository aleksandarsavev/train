#include <istream>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

float** loadMatrix(const char* filename) {
    int N;
    ifstream in(filename);

    if (!in) {
        cout << "Cannot open file.\n";
        return NULL;
    }
    
    in >> N;

    // Alocate memory for the input matrix
    float** matrix = new float*[N];
    for(int i = 0; i < N; i++)
        matrix[i] = new float[N];
    
    // Read matrix from input file stream
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            in >> matrix[x][y];

    in.close();
    return matrix;
}

int main() {
    float ** matrix = loadMatrix("input.txt");
    cout << matrix[0][0];
}
