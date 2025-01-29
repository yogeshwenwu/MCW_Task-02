#include <iostream>
#include <chrono>
#include "matrixTranspose.h"
#include "matrixTransposeAvx.h"
using namespace std;

int main() {
    // Initialization
    float matrix[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    // Scalar transpose the matrix
    auto start_scalar = chrono::high_resolution_clock::now();
    MatrixTranspose(matrix);
    auto end_scalar = chrono::high_resolution_clock::now();
    auto scalar_duration = chrono::duration_cast<chrono::nanoseconds>(end_scalar - start_scalar).count();
    

    // Display the transposed matrix
    cout << "Transposed Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // Vector transpose the matrix
    auto start_vector = chrono::high_resolution_clock::now();
    MatrixTranspose(matrix);
    auto end_vector = chrono::high_resolution_clock::now();
    auto vector_duration = chrono::duration_cast<chrono::nanoseconds>(end_vector - start_vector).count();
    

    // Display the transposed matrix
    cout << "Transposed Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix transposition took: " << scalar_duration << " nanoseconds" << endl;
    cout << "Vector Matrix transposition took: " << vector_duration << " nanoseconds" << endl;

    return 0;
}
