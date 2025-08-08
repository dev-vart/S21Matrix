#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !result) {
    return INVALID_MATRIX;
  }
  double det = 0.0;
  s21_determinant(A, &det);
  if (A->rows != A->columns || det == 0.0) {
    exit_code = CALC_ERROR;
  } else {
    matrix_t calc_comp_A = {0};
    s21_calc_complements(A, &calc_comp_A);
    s21_transpose(&calc_comp_A, result);
    s21_remove_matrix(&calc_comp_A);
    s21_mult_number(result, 1 / det, result);
  }
  return exit_code;
}
