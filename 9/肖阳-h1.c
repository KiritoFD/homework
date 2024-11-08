int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int top = 0, bottom = matrixSize - 1;
    int left = 0, right = *matrixColSize - 1;
    int direction = 0; // 0: right, 1: down, 2: left, 3: up
    int count = *matrixColSize * matrixSize, num = 0;
    int* ans = (int*)malloc(sizeof(int) * count);
    *returnSize = count;

    while (count > 0) {
        if (direction == 0) { // Move right
            for (int j = left; j <= right; j++) {
                ans[num++] = matrix[top][j];
                count--;
            }
            top++; // move the top boundary down after processing the row
        } else if (direction == 1) { // Move down
            for (int i = top; i <= bottom; i++) {
                ans[num++] = matrix[i][right];
                count--;
            }
            right--; // move the right boundary left after processing the column
        } else if (direction == 2) { // Move left
            for (int j = right; j >= left; j--) {
                ans[num++] = matrix[bottom][j];
                count--;
            }
            bottom--; // move the bottom boundary up after processing the row
        } else if (direction == 3) { // Move up
            for (int i = bottom; i >= top; i--) {
                ans[num++] = matrix[i][left];
                count--;
            }
            left++; // move the left boundary right after processing the column
        }

        direction = (direction + 1) % 4; // Cycle direction: 0 -> 1 -> 2 -> 3 -> 0
    }

    return ans;
}
