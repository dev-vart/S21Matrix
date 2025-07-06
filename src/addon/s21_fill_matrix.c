#include "../s21_matrix.h"

int s21_fill_matrix(matrix_t *A, double num, matrix_t *result) {
  int exit_code = OK;
  if (!A || !A->matrix || !result || A->rows < 1 || A->columns < 1) {
    return INVALID_MATRIX;
  }
  if (A != result) {
    exit_code = s21_create_matrix(A->rows, A->columns, result);
  }
  if (exit_code == OK) {
    for (int i = 0; i < A->rows; ++i) {
      for (int j = 0; j < A->columns; ++j) {
        result->matrix[i][j] = num;
      }
    }
  }
  return exit_code;
}
