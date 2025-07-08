#include "../s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !result) {
    return INVALID_MATRIX;
  }
  if (A != result) {
    exit_code = s21_create_matrix(A->rows, A->columns, result);
  }
  for (int i = 0; i < A->rows && exit_code == OK; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }
  return exit_code;
}

// int main() {
//   matrix_t m;
//   printf("working... \n");
//   s21_create_matrix(2, 3, &m);
//   s21_input_matrix(&m, &m);
//   printf("second... \n");
//   s21_input_matrix(&m, &m);
//   s21_print_matrix(&m);
//   s21_mult_number(&m, 1.5, &m);
//   s21_print_matrix(&m);
//   s21_remove_matrix(&m);
//   return 0;
// }