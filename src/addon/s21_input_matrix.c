#include <stdio.h>

#include "../s21_matrix.h"

int s21_input_matrix(matrix_t *A, matrix_t *result) {
  int exit_code = OK;
  if (!s21_is_valid_matrix(A) || !result) {
    return INVALID_MATRIX;
  }
  if (A != result) {
    exit_code = s21_create_matrix(A->rows, A->columns, result);
  }
  double num;
  char c;
  int check;
  for (int i = 0; i < A->rows && exit_code == OK; ++i) {
    for (int j = 0; j < A->columns; ++j) {
      check = scanf("%le%c", &num, &c);
      while (check != 2 || (c != '\n' && c != ' ')) {
        while (getchar() != '\n' && !feof(stdin)) {
        }
        printf("Wrong input. Try again.\n");
        check = scanf("%le%c", &num, &c);
      }
      result->matrix[i][j] = num;
    }
  }
  return exit_code;
}
