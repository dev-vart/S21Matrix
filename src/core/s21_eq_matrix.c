#include <math.h>

#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int exit_code = SUCCESS;
  if (!s21_is_valid_matrix(A) || !s21_is_valid_matrix(B)) {
    return FAILURE;
  }
  if (A->rows != B->rows || A->columns != B->columns) {
    exit_code = FAILURE;
  }
  for (int i = 0; i < A->rows && exit_code == SUCCESS; ++i) {
    for (int j = 0; j < A->columns && exit_code == SUCCESS; ++j) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        exit_code = FAILURE;
      }
    }
  }
  return exit_code;
}
