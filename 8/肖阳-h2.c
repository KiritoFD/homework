#include <stdbool.h>

bool isToeplitzMatrix(int** matrix, int matrixSize, int* matrixColSize) {
    // 遍历矩阵的每个元素（除了最后一行和最后一列）
    for (int i = 0; i < matrixSize - 1; i++) {
        for (int j = 0; j < matrixColSize[i] - 1; j++) {
            // 检查当前元素是否与右下方的元素相等
            if (matrix[i][j] != matrix[i + 1][j + 1]) {
                return false;
            }
        }
    }
    return true;
}
