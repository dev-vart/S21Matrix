#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B) || !result) {
    return INVALID_MATRIX;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    exit_code = CALC_ERROR;
  } else if (A != result && B != result) {
    exit_code = s21_create_matrix(A->rows, A->columns, result);
  }
  for (int i = 0; i < A->rows && exit_code == OK; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }
  return exit_code;
}
