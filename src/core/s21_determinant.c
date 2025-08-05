#include "../s21_matrix.h"

double s21_determinant_recursive(matrix_t *A, int *exit_code);

int s21_determinant(matrix_t *A, double *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !result) {
    return INVALID_MATRIX;
  } else if (A->rows != A->columns) {
    exit_code = CALC_ERROR;
  } else {
    double det = s21_determinant_recursive(A, &exit_code);
    if (exit_code == OK) {
      *result = det;
    }
  }
  return exit_code;
}

double s21_determinant_recursive(matrix_t *A, int *exit_code) {
  if (*exit_code != OK) {
    return 0.0;
  }

  int matrix_size = A->rows;
  double det = 0.0;

  if (matrix_size == 1) {
    det = A->matrix[0][0];
  } else if (matrix_size == 2) {
    det = A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (matrix_size == 3) {
    det = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +
          A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +
          A->matrix[1][0] * A->matrix[2][1] * A->matrix[0][2] -
          A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
          A->matrix[1][2] * A->matrix[2][1] * A->matrix[0][0] -
          A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2];
  } else {
    for (int j = 0; j < matrix_size && *exit_code == OK; ++j) {
      matrix_t minor_matrix = {0};
      *exit_code = s21_minor_matrix(A, 1, j + 1, &minor_matrix);
      if (*exit_code == OK) {
        double minor_det = s21_determinant_recursive(&minor_matrix, exit_code);
        if (*exit_code == OK) {
          double minor_sign = (j % 2 == 0) ? 1 : -1;
          det += minor_sign * A->matrix[0][j] * minor_det;
        }
      }
      s21_remove_matrix(&minor_matrix);
    }
  }
  return det;
}
