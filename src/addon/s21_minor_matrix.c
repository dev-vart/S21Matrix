#include "../s21_matrix.h"

int s21_minor_matrix(matrix_t *A, int row, int column, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !result) {
    return INVALID_MATRIX;
  }
  if (A->rows != A->columns || A->rows < 2 || row < 1 || row > A->rows ||
      column < 1 || column > A->columns) {
    exit_code = CALC_ERROR;
  } else {
    exit_code = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  }
  for (int i = 0, minor_i = 0; i < A->rows && exit_code == OK; ++i) {
    if (i == row - 1) continue;
    for (int j = 0, minor_j = 0; j < A->columns; ++j) {
      if (j == column - 1) continue;
      result->matrix[minor_i][minor_j] = A->matrix[i][j];
      ++minor_j;
    }
    ++minor_i;
  }
  return exit_code;
}
