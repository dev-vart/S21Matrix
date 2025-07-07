#include "../s21_matrix.h"

int main() {
  matrix_t matrix;
  matrix_t matrixR;

  s21_create_matrix(3, 2, &matrix);
  // s21_create_matrix(3, 2, &matrixR);
  printf("--- created ---\n");
  // matrix.matrix[0][0]
  s21_print_matrix(&matrix);
  // printf("\n");
  // s21_print_matrix(&matrixR);
  // // printf("\n");
  // s21_remove_matrix(&matrix);

  // s21_print_matrix(&matrix);  // работает так как при remove matrix указатель на
  //                             // matrix обнуляется
  // printf("\n");
  // printf("--- filling 34 ---\n");
  // s21_fill_matrix(&matrix, 34, &matrixR);
  // s21_print_matrix(&matrix);
  // printf("\n");
  // s21_print_matrix(&matrixR);
  // printf("\n");

  // printf("--- filling 54 ---\n");
  // s21_print_matrix(&matrixR);
  // s21_fill_matrix(&matrixR, 54, &matrixR);
  // printf("\n");
  // s21_print_matrix(&matrixR);

  // printf("--- filling 17 ---\n");
  // s21_remove_matrix(&matrix);
  // printf("a");
  // s21_print_matrix(&matrix);
  // printf("b");
  // s21_fill_matrix(&matrixR, 17, &matrix);
  // printf("\n");
  // s21_print_matrix(&matrix);
  // printf("\n");

  // printf("--- end ---\n");
  // s21_print_matrix(&matrix);
  // printf("\n");
  // s21_print_matrix(&matrixR);
  // printf("\n");

  // s21_remove_matrix(&matrix);
  // s21_remove_matrix(&matrixR);
  return 0;
}

// #include "../s21_matrix.h"

// int main() {
//   matrix_t matrix;
//   matrix_t matrixR;
//   s21_create_matrix(3, 2, &matrix);
//   // s21_create_matrix(3, 2, &matrixR);
//   s21_fill_matrix(&matrix, 34, &matrixR);
//   s21_remove_matrix(&matrix);
//   s21_remove_matrix(&matrixR);
//   return 0;
// }
