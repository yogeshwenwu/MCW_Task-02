#include <iostream>
#include <chrono>
#include "matrixTranspose.h"
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

    auto start_scalar = chrono::high_resolution_clock::now();
    // Scalar transpose the matrix
    MatrixTranspose(matrix);

    auto end_scalar = chrono::high_resolution_clock::now();
    auto scalar_duration = chrono::duration_cast<chrono::nanoseconds>(end_scalar - start_scalar).count();
    
    cout << "Matrix transposition took: " << scalar_duration << " nanoseconds" << endl;

    // Display the transposed matrix
    cout << "Transposed Matrix:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
