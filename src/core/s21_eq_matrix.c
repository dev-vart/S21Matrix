#include <math.h>

#include "../s21_matrix.h"

#define SUCCESS 1
#define FAILURE 0
#define EPSILON 1e-7

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int exit_code = SUCCESS;
  if (!A || !A->matrix || A->rows < 1 || A->columns < 1 || !B || !B->matrix ||
      B->rows < 1 || B->columns < 1) {
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
