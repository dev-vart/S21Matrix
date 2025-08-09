#include "../s21_matrix.h"
#include "../tests/fake_alloc.h"

void s21_free_rows(matrix_t *A, int rows);

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int exit_code = OK;
  if (!result || rows < 1 || columns < 1) {
    return INVALID_MATRIX;
  }
  result->rows = rows;
  result->columns = columns;
  result->matrix = (double **)malloc(rows * sizeof(double *));
  if (result->matrix == S21_NULL) {
    exit_code = INVALID_MATRIX;
  }
  for (int i = 0; i < rows && exit_code == OK; ++i) {
    result->matrix[i] = (double *)calloc(columns, sizeof(double));
    if (result->matrix[i] == S21_NULL) {
      s21_free_rows(result, i);
      exit_code = INVALID_MATRIX;
    }
  }
  return exit_code;
}

void s21_free_rows(matrix_t *A, int rows) {
  for (int j = 0; j < rows; ++j) {
    free(A->matrix[j]);
  }
  free(A->matrix);
  A->matrix = S21_NULL;
}
