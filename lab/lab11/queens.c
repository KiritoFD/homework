#include <stdio.h>
#include <assert.h>
// 检查在指定位置放置皇后是否安全
int is_safe(int row, int col, int num_cols, int used_col[], int used_diag1[], int used_diag2[]) {
    // 检查列是否安全
    if (used_col[col]) return 0;
    // 检查对角线1是否安全
    if (used_diag1[row + col]) return 0;
    // 检查对角线2是否安全
    if (used_diag2[row - col + num_cols]) return 0;
    return 1;
}

// 递归放置皇后
int place_queens_util(int row, int num_rows, int num_cols, int num_queens, int used_col[], int used_diag1[], int used_diag2[]) {
    // 如果所有皇后都已成功放置，返回1
    if (num_queens == 0) return 1;
    // 如果没有行可以放置皇后，返回0
    if (row >= num_rows) return 0;

    int count = 0;
    // 尝试在当前行的每一列放置皇后
    for (int i = 0; i < num_cols; i++) {
        // 检查在(row, i)位置放置皇后是否安全
        if (is_safe(row, i, num_cols, used_col, used_diag1, used_diag2)) {
            // 放置皇后并标记列和对角线为已占用
            used_col[i] = 1;
            used_diag1[row + i] = 1;
            used_diag2[row - i + num_cols] = 1;

            // 递归处理下一行
            count += place_queens_util(row + 1, num_rows, num_cols, num_queens - 1, used_col, used_diag1, used_diag2);

            // 回溯，取消标记
            used_col[i] = 0;
            used_diag1[row + i] = 0;
            used_diag2[row - i + num_cols] = 0;
        }
    }
    return count;
}

// 计算在num_rows行和num_cols列的棋盘上放置num_queens个皇后的方法
int place_queens(int num_rows, int num_cols, int num_queens) {
    int used_col[num_cols];
    int used_diag1[num_rows + num_cols];
    int used_diag2[num_cols + num_cols];

    // 初始化数组
    for (int i = 0; i < num_cols; i++) {
        used_col[i] = 0;
    }
    for (int i = 0; i < num_rows + num_cols; i++) {
        used_diag1[i] = 0;
    }
    for (int i = 0; i < num_cols + num_cols; i++) {
        used_diag2[i] = 0;
    }

    // 从第0行开始放置皇后
    return place_queens_util(0, num_rows, num_cols, num_queens, used_col, used_diag1, used_diag2);
}




void TestCase(){
  // Test Case : 1
  assert(place_queens(1,1,1) == 1);
  printf("Passed TestCase1\n");
  
  // Test Case : 2
  assert(place_queens(2,2,2) == 0);
  printf("Passed TestCase2\n");
  
  // Test Case : 3
  assert(place_queens(3,3,3) == 0);
  printf("Passed TestCase3\n");
  
  // Test Case : 4
  assert(place_queens(4,4,4) == 2);
  printf("Passed TestCase4\n");
  
  // Test Case : 5
  assert(place_queens(5,5,5) == 10);
  printf("Passed TestCase5\n");

  // Test Case : 6
  assert(place_queens(6,6,6) == 4);
  printf("Passed TestCase6\n");

  // Test Case : 7
  assert(place_queens(7,7,7) == 40);
  printf("Passed TestCase7\n");

  // Test Case : 8
  assert(place_queens(8,8,8) == 92);
  printf("Passed TestCase8\n");

  // Test Case : 9
  assert(place_queens(9,9,9) == 352);
  printf("Passed TestCase9\n");

  // Test Case : 10
  assert(place_queens(10,10,10) == 724);
  printf("Passed TestCase10\n");
  
  // Test Case : 11
  assert(place_queens(3,8,3) == 140);
  printf("Passed TestCase11\n");
  
  // Test Case : 12
  assert(place_queens(4,5,4) == 12);
  printf("Passed TestCase12\n");
  
  // Test Case : 13
  assert(place_queens(5,9,4) == 732);
  printf("Passed TestCase13\n");

  // Test Case : 14
  assert(place_queens(5,10,5) == 3916);
  printf("Passed TestCase14\n");
  
  printf("All Test Cases Passed!\n");
}

int main()
 {
  TestCase();
  return 0;
}