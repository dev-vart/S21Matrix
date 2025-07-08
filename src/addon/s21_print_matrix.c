#include "../s21_matrix.h"

int s21_print_matrix(matrix_t *A) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A)) {
    return INVALID_MATRIX;
  }
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      printf("%f", A->matrix[i][j]);
      if (j != A->columns - 1) printf(" ");
    }
    printf("\n");
  }
  return exit_code;
}
