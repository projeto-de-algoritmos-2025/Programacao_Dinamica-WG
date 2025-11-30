#include <stddef.h>

int min(int a, int b, int c) {
    int temp = (a < b) ? a : b;
    return (temp < c) ? temp : c;
}

int countSquares(int** matrix, int matrixSize, int* matrixColSize) {
    if (matrixSize == 0 || matrixColSize == NULL || matrixColSize[0] == 0) return 0;

    int numCols = matrixColSize[0];
    int totalSquares = 0;

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < numCols; ++j) {
            if (matrix[i][j] == 1 && i > 0 && j > 0) {
                matrix[i][j] += min(matrix[i - 1][j - 1], 
                                    matrix[i - 1][j], 
                                    matrix[i][j - 1]);
            }
        }
    }

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < numCols; ++j) {
            totalSquares += matrix[i][j];
        }
    }

    return totalSquares;
}