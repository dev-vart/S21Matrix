#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int exit_code = 0;
  if (!result || rows < 1 || columns < 1) {
    return 1;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (result->matrix == S21_NULL) {
    exit_code = 1;
  } else {
    for (int i = 0; i < rows; ++i) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (result->matrix[i] == S21_NULL) {
        for (int j = 0; j < i; ++j) {
          free(result->matrix[j]);
        }
        free(result->matrix);
        exit_code = 1;
      }
    }
  }
  return exit_code;
}
