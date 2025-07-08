#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) || !result) {
    return INVALID_MATRIX;
  }
  if ((A == result) != (B == result)) {
    exit_code = INVALID_MATRIX;
    // if user tries to write res matrix in A or B
    // except A == B == result
  } else if (A->columns != B->rows) {
    exit_code = CALC_ERROR;
  } else if (!(A == B && A == result)) {
    exit_code = s21_create_matrix(A->rows, B->columns, result);
    // if A == B == result: A^2 -> A
    // no need to create a new matrix
  }
  for (int i = 0; i < A->rows && exit_code == OK; ++i) {
    for (int j = 0; j < B->columns; ++j) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < B->rows; ++k) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
  return exit_code;
}

// A == B == res - pass - A**2 -> A; 0 0 0
// A == B != res - create - A**2 -> res; 0 0 1
// A != B != res - create - A*B -> res; 0 1 2
// A != B == res - INVALID_MATRIX - A*B -> B; 0 1 1
// A == res != B - INVALID_MATRIX - A*B -> A; 0 1 0

int main() {
  matrix_t m;
  printf("working... \n");
  s21_create_matrix(2, 3, &m);
  s21_input_matrix(&m, &m);
  printf("second... \n");
  s21_input_matrix(&m, &m);
  s21_print_matrix(&m);
  s21_mult_number(&m, 1.5, &m);
  s21_print_matrix(&m);
  s21_remove_matrix(&m);
  return 0;
}