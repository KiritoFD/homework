#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

struct Matrix {
  int num_rows;
  int num_cols;
  int** M;
};

void init_matrix(int num_rows, int num_cols, int a[][num_cols],
    struct Matrix* pmatrix) {
  pmatrix->num_rows = num_rows;
  pmatrix->num_cols = num_cols;
  // Initialize 2d array pmatrix->M
  pmatrix->M = (int**) malloc(num_rows * sizeof(int*));
  int i;
  for (i = 0; i < num_rows; i ++) {
    pmatrix->M[i] = (int*) malloc(num_cols * sizeof(int));
  }
  // Copy the entries from a.
  int j;
  for (i = 0; i < num_rows; i ++) {
    for (j = 0; j < num_cols; j ++) {
      pmatrix->M[i][j] = a[i][j];
    }
  }
}

void print_matrix(struct Matrix *pm) {
  int i, j;
  for (i = 0; i < pm->num_rows; i ++) {
    for (j = 0; j < pm->num_cols; j ++) {
      printf("%d", pm->M[i][j]);
      if (j < pm->num_cols-1) {
        printf(" ");
      }
    }
  printf("\n");
  }
}

void free_matrix(struct Matrix* pm) {
  int i;
  for (i = 0; i < pm->num_rows; i ++) {
    free(pm->M[i]);
  }
  free(pm->M);
  pm->num_cols = 0;
  pm->num_rows = 0;
}

// If two matrices are equal, return 1.
// Otherwise, return 0
int are_matrices_equal(struct Matrix* first, struct Matrix* second) {
  if (first->num_rows != second->num_rows) return 0;
  if (first->num_cols != second->num_cols) return 0;

  int i, j;
  for (i = 0; i < first->num_rows; i++) {
    for (j = 0; j < second->num_cols; j++) {
      if (first->M[i][j] != second->M[i][j]) return 0;
    }
  }

  return 1;
}

// Matrix multiplication
// result = first * second.
// If matrix sizes do not match, return 0.
// Otherwise, return 1.
int matrix_mult(struct Matrix* first, struct Matrix* second,
    struct Matrix* result) {
    if (first->num_cols != second->num_rows) return 0;

    result->num_rows = first->num_rows;
    result->num_cols = second->num_cols;
    result->M = (int **) malloc(sizeof(int *) * result->num_rows);

    int i, j, k;
    for (i = 0; i < result->num_rows; i++) {
      result->M[i] = (int *) malloc(sizeof(int) * result->num_cols);
      for (j = 0; j < result->num_cols; j++) {
        result->M[i][j] = 0;
        for (k = 0; k < first->num_cols; k++) {
          result->M[i][j] += first->M[i][k] * second->M[k][j];
        }
      }
    }

    return 1;
}

// Matrix addition
// result = first + second.
// If matrix sizes do not match, return 0.
// Otherwise, return 1.
int matrix_add(struct Matrix* first, struct Matrix* second,
    struct Matrix* result) {
    if (first->num_cols != second->num_cols) return 0;
    if (first->num_rows != second->num_rows) return 0;

    result->num_rows = first->num_rows;
    result->num_cols = second->num_cols;
    result->M = (int **) malloc(sizeof(int *) * result->num_rows);

    int i, j;
    for (i = 0; i < result->num_rows; i++) {
      result->M[i] = (int *) malloc(sizeof(int) * result->num_cols);
      for (j = 0; j < result->num_cols; j++) {
        result->M[i][j] = first->M[i][j] + second->M[i][j];
      }
    }

    return 1;
}


void TestMatrixMultCase1() {
  struct Matrix first, second, expected, result;
  
  int m_first[3][4] = {
    {1, 0, 2, 0},
    {0, 1, 1, -2},
    {2, 0, 0, -1}
  };
  init_matrix(3, 4, m_first, &first);

  int m_second[4][2] = {
    {1, 0},
    {2, 3},
    {-1, 2},
    {0, -2}
  };
  init_matrix(4, 2, m_second, &second);

  int m_expected[3][2] = {
    {-1, 4},
    {1, 9},
    {2, 2}
  };
  init_matrix(3, 2, m_expected, &expected);

  int is_match = matrix_mult(&first, &second, &result);
  assert(is_match == 1);
  
  int is_correct = are_matrices_equal(&result, &expected);
  printf("The first matrix is:\n");
  print_matrix(&first);
  printf("The second matrix is:\n");
  print_matrix(&second);
  printf("The expected result should be:\n");
  print_matrix(&expected);
  printf("Your result is:\n");
  print_matrix(&result);
  assert(is_correct == 1);
  
  free_matrix(&first);
  free_matrix(&second);
  free_matrix(&expected);
  free_matrix(&result);

  printf("TestCase1 for matrix_mult passed!\n");
}

void TestMatrixMultCase2() {
  struct Matrix first, second, expected, result;
  
  int m_first[1][INT16_MAX]; 
  int i;
  for (i = 0; i < INT16_MAX; i++) {
    if (i % 2 == 0) m_first[0][i] = 1;
    else m_first[0][i] = -1;
  }
  init_matrix(1, INT16_MAX, m_first, &first);

  int m_second[INT16_MAX][1];
  for (i = 0; i < INT16_MAX; i++) {
    m_second[i][0] = 1;
  }
  init_matrix(INT16_MAX, 1, m_second, &second);

  int m_expected[1][1] = {
    {1},
  };
  init_matrix(1, 1, m_expected, &expected);

  int is_match = matrix_mult(&first, &second, &result);
  assert(is_match == 1);

  int is_correct = are_matrices_equal(&result, &expected);
  printf("The first matrix is:\n");
  print_matrix(&first);
  printf("The second matrix is:\n");
  print_matrix(&second);
  printf("The expected result should be:\n");
  print_matrix(&expected);
  printf("Your result is:\n");
  print_matrix(&result);
  assert(is_correct == 1);

  free_matrix(&first);
  free_matrix(&second);
  free_matrix(&expected);
  free_matrix(&result);

  printf("TestCase2 for matrix_mult passed!\n");
}

void TestMatrixMultCase3() {
  struct Matrix first, second, result;
  
  int m_first[3][4] = {
    {1, 0, 2, 0},
    {0, 1, 1, -2},
    {2, 0, 0, -1}
  };
  init_matrix(3, 4, m_first, &first);

  int m_second[2][2] = {
    {1, 0},
    {2, 3}
  };
  init_matrix(2, 2, m_second, &second);

  int is_match = matrix_mult(&first, &second, &result);
  assert(is_match == 0);

  printf("The first matrix is:\n");
  print_matrix(&first);
  printf("The second matrix is:\n");
  print_matrix(&second);
  printf("The two matrices size for matrix_mult do not match!\n");
  
  free_matrix(&first);
  free_matrix(&second);

  printf("TestCase3 for matrix_mult passed!\n");
}

void TestMatrixAddCase1() {
  struct Matrix first, second, expected, result;

  int m_first[3][3] = {
    {1, 0, 2},
    {0, 1, 1},
    {2, 0, 0}
  };
  init_matrix(3, 3, m_first, &first);

  int m_second[3][3] = {
    {1, 0, -4},
    {2, 3, 1},
    {-1, 2, 0}
  };
  init_matrix(3, 3, m_second, &second);

  int m_expected[3][3] = {
    {2, 0, -2},
    {2, 4, 2},
    {1, 2, 0}
  };
  init_matrix(3, 3, m_expected, &expected);

  int is_match = matrix_add(&first, &second, &result);
  assert(is_match == 1);

  int is_correct = are_matrices_equal(&result, &expected);
  printf("The first matrix is:\n");
  print_matrix(&first);
  printf("The second matrix is:\n");
  print_matrix(&second);
  printf("The expected result should be:\n");
  print_matrix(&expected);
  printf("Your result is:\n");
  print_matrix(&result);
  assert(is_correct == 1);

  free_matrix(&first);
  free_matrix(&second);
  free_matrix(&expected);
  free_matrix(&result);

  printf("TestCase1 for matrix_add passed!\n");
}

void TestMatrixAddCase2() {
  struct Matrix first, second, expected, result;
  
  int m_first[1][INT16_MAX]; 
  int i;
  for (i = 0; i < INT16_MAX; i++) {
    if (i % 2 == 0) m_first[0][i] = 1;
    else m_first[0][i] = -1;
  }
  init_matrix(1, INT16_MAX, m_first, &first);

  int m_second[1][INT16_MAX];
  for (i = 0; i < INT16_MAX; i++) {
    m_second[0][i] = 1;
  }
  init_matrix(1, INT16_MAX, m_second, &second);

  int m_expected[1][INT16_MAX]; 
  for (i = 0; i < INT16_MAX; i++) {
    if (i % 2 == 0) m_expected[0][i] = 2;
    else m_expected[0][i] = 0;
  }
  init_matrix(1, INT16_MAX, m_expected, &expected);

  int is_match = matrix_add(&first, &second, &result);
  assert(is_match == 1);
  int is_correct = are_matrices_equal(&result, &expected);

  printf("The first matrix is:\n");
  print_matrix(&first);
  printf("The second matrix is:\n");
  print_matrix(&second);
  printf("The expected result should be:\n");
  print_matrix(&expected);
  printf("Your result is:\n");
  print_matrix(&result);
  assert(is_correct == 1);

  free_matrix(&first);
  free_matrix(&second);
  free_matrix(&expected);
  free_matrix(&result);

  printf("TestCase2 for matrix_add passed!\n");
}

void TestMatrixAddCase3() {
  struct Matrix first, second, result;
  
  int m_first[3][4] = {
    {1, 0, 2, 0},
    {0, 1, 1, -2},
    {2, 0, 0, -1}
  };
  init_matrix(3, 4, m_first, &first);

  int m_second[2][2] = {
    {1, 0},
    {2, 3}
  };
  init_matrix(2, 2, m_second, &second);

  int is_match = matrix_add(&first, &second, &result);
  assert(is_match == 0);

  printf("The first matrix is:\n");
  print_matrix(&first);
  printf("The second matrix is:\n");
  print_matrix(&second);
  printf("The two matrices size for matrix_add do not match!\n");
  
  free_matrix(&first);
  free_matrix(&second);

  printf("TestCase3 for matrix_add passed!\n");
}

int main() {
  TestMatrixAddCase1();
  TestMatrixAddCase2();
  TestMatrixAddCase3();
  TestMatrixMultCase1();
  TestMatrixMultCase2();
  TestMatrixMultCase3();
  printf("Thank you for your hard work; all tests have passed. Congratulations!\n");
  return 0;
}
