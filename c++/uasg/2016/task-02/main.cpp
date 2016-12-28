// task-02
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int M = 0;
int N = 2;

float **loadMatrix(const char *filename)
{
    // open an input file stream
    ifstream in(filename);

    if (!in)
    {
        // if the stream is empty,
        // that means the file cannot be opened
        cout << "Cannot open file.\n";
        return NULL;
    }
    // read the number of points
    in >> M;
    // create empty matrix with size M x 2
    float **matrix = new float *[M];
    for (int i = 0; i < M; i++)
        matrix[i] = new float[N];

    // read matrix from input file stream
    for (int y = 0; y < M; y++)
        for (int x = 0; x < N; x++)
            in >> matrix[y][x];

    // close the input file stream
    // this way we release the resource
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

float **buildMatrix(float **source)
{
    // create new matrix where the distancies will be stored
    float **matrix = new float *[M];
    for (int i = 0; i < M; i++)
        matrix[i] = new float[N];

    for (int y = 0; y < M; y++)
    {
        float x1 = source[y][0];
        float y1 = source[y][1];
        // calculate only the half of the matrix
        // from x = 0 to x <= y
        for (int x = 0; x <= y; x++)
        {
            float x2 = source[x][0];
            float y2 = source[x][1];
            float distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
            // the matrix is symmetrix, so we store the same value twice
            // because the distance between A and B is the same as the distance between B and A
            matrix[y][x] = distance;
            matrix[x][y] = distance;
        }
    }
    return matrix;
}

void printSimmilar(float **source)
{
    for (int y = 0; y < M; y++)
    {
        for (int x = y + 1; x < M; x++)
        {
            // if the coordinates of two point are the same,
            // we print the indexes on the standart output
            if (source[y][0] == source[x][0] && source[y][1] == source[x][1])
            {
                cout << "Point[" << y << "] == Point[" << x << "]\n";
            }
        }
    }
}

int main()
{
    float **input = loadMatrix("input.txt");
    cout << "Input (matrix A):\n";
    printMatrix(input);

    N = M;
    float **distances = buildMatrix(input);
    cout << "Distancies (matrix A):\n";
    printMatrix(distances);

    cout << "Simmiliarities (matrix A):\n";
    printSimmilar(input);
    return 0;
}
