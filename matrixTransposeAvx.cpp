#include "matrixTransposeAvx.h"
#include <immintrin.h>

void MtAvx128(float matrix[5][5]) {
    __m128 row0 = _mm_loadu_ps(&matrix[0][0]);   
    __m128 row1 = _mm_loadu_ps(&matrix[1][0]);   
    __m128 row2 = _mm_loadu_ps(&matrix[2][0]);   
    __m128 row3 = _mm_loadu_ps(&matrix[3][0]);   

    // Transpose the martix
    __m128 t0 = _mm_unpacklo_ps(row0, row1); 
    __m128 t1 = _mm_unpackhi_ps(row0, row1); 
    __m128 t2 = _mm_unpacklo_ps(row2, row3);
    __m128 t3 = _mm_unpackhi_ps(row2, row3);
    __m128 temp0 = _mm_shuffle_ps(t0, t2, _MM_SHUFFLE(1, 0, 1, 0)); 
    __m128 temp1 = _mm_shuffle_ps(t0, t2, _MM_SHUFFLE(3, 2, 3, 2)); 
    __m128 temp2 = _mm_shuffle_ps(t1, t3, _MM_SHUFFLE(1, 0, 1, 0)); 
    __m128 temp3 = _mm_shuffle_ps(t1, t3, _MM_SHUFFLE(3, 2, 3, 2)); 
    _mm_storeu_ps(&matrix[0][0], temp0); 
    _mm_storeu_ps(&matrix[1][0], temp1); 
    _mm_storeu_ps(&matrix[2][0], temp2); 
    _mm_storeu_ps(&matrix[3][0], temp3); 

    // Transpose remaining elements
    for (int i = 0; i < 4; i++) {
        float temp = matrix[i][4];
        matrix[i][4] = matrix[4][i];
        matrix[4][i] = temp;
    }
}
