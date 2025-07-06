#include "../s21_matrix.h"

int s21_print_matrix(matrix_t *A) {
  int exit_code = OK;
  if (!A || !A->matrix || A->rows < 1 || A->columns < 1) {
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
