// task-12
#include <fstream>
#include <iostream>
#include <math.h>

using namespace std;

int M = 0;
int N = 2;
float **loadMatrix(const char *filename)
{
    ifstream in(filename);

    if (!in)
    {
        cout << "Cannot open file.\n";
        return NULL;
    }

    in >> M;

    float **matrix = new float *[M];
    for (int i = 0; i < M; i++)
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

float **buildMatrix(float **source)
{
    float **matrix = new float *[M];
    for (int i = 0; i < M; i++)
        matrix[i] = new float[M];

    for (int y = 0; y < M; y++)
    {
        float x1 = source[y][0];
        float y1 = source[y][1];
        for (int x = 0; x < y; x++)
        {
            float x2 = source[x][0];
            float y2 = source[x][1];
            float dot = x1 * x2 + y1 * y2; // dot product
            float det = x1 * y2 - y1 * x2; // determinant
            float angle = atan2(det, dot) / 3.1415 * 180;
            // the matrix is symmetric
            matrix[y][x] = angle;
            matrix[x][y] = -angle;
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
    float **angles = buildMatrix(input);
    cout << "Angles (matrix A):\n";
    printMatrix(angles);

    cout << "Simmiliarities (matrix A):\n";
    printSimmilar(input);
    return 0;
}
