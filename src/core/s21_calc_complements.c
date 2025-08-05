#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !result) {
    return INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    exit_code = CALC_ERROR;
  } else if (A->rows == 1) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1;
  } else if (A != result) {
    exit_code = s21_create_matrix(A->rows, A->columns, result);
  }
  for (int i = 0; i < A->rows && exit_code == OK; ++i) {
    for (int j = 0; j < A->columns && exit_code == OK; ++j) {
      matrix_t minor_matrix = {0};
      if (exit_code == OK) {
        exit_code = s21_minor_matrix(A, i + 1, j + 1, &minor_matrix);
        if (exit_code == OK) {
          double det = 0.0;
          exit_code = s21_determinant(&minor_matrix, &det);
          if (exit_code == OK) {
            result->matrix[i][j] = det;
            if ((i + j) % 2 != 0) result->matrix[i][j] *= -1;
          }
        }
      }
      s21_remove_matrix(&minor_matrix);
    }
  }
  return exit_code;
}
