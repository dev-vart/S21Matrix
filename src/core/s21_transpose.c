#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !result) {
    return INVALID_MATRIX;
  }
  exit_code = s21_create_matrix(A->columns, A->rows, result);
  for (int i = 0; i < A->rows && exit_code == OK; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
  return exit_code;
}
