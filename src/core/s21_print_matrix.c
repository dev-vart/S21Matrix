#include "../s21_matrix.h"

int s21_print_matrix(matrix_t *A) {
  if (!A || !A->matrix || A->rows < 1 || A->columns < 1) {
    // printf("print returns 1\n");
    return 1;
  }
  // printf("i nailed it!");
  for (int i = 0; i < A->rows; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      // printf("GH");
      // A->matrix[i][j] = i*i + j;
      printf("%f", A->matrix[i][j]);
      if (j != A->columns - 1) printf(" ");
    }
    // if (i != A->rows - 1)
    printf("\n");
  }
  return 0;
}
