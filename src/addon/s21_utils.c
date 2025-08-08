#include "../s21_matrix.h"

int s21_is_valid_matrix(matrix_t *A) {
  return (A && A->matrix && A->rows > 0 && A->columns > 0);
}
