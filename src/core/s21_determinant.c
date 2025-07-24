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

int main() {
  matrix_t m = {0};//, m2 = {0}, mr = {0};
  double r = 0;
  printf("working... \n");

  int i = 11;
  printf("error code: %d\n", s21_create_matrix(i, i, &m));
  // s21_create_matrix(2, 3, &m2);
  // s21_create_matrix(3, 3, &mr); ТАК НЕЛЬЗЯ ПИСАТЬ!
  // В ФУНКЦИЮ ПОДАЕТСЯ ПУСТОЙ УКАЗАТЕЛЬ

  s21_input_matrix(&m, &m);
  s21_print_matrix(&m);
  // s21_input_matrix(&m2, &m2);
  // s21_print_matrix(&m2);
  // s21_print_matrix(&mr);

  printf("second... \n");
  printf("error code: %d\n", s21_determinant(&m, &r));
  s21_print_matrix(&m);
  printf("\n%lf\n", r);
  // s21_print_matrix(&m2);
  // s21_print_matrix(&mr);

  s21_remove_matrix(&m);
  // s21_remove_matrix(&m2);
  // s21_remove_matrix(&mr);
  return 0;
}

// 9 2 3 1 5 6 7 8 2 10 11 12 90 14 15 -1 17 18 190 20 20.1 22 23 204 25 9 2 3 1 5 6 7 8 2 10 11 12 90 14 15 -1 17 18 190 20 20.1 22 23 204 25 12 90 14 15 -1 17 18 190 20 20.1 22 23 204 25 12 90 14 15 -1 17 18 190 20 20.1 22 23 204 25 12 90 14 15 -1 17 18 190 20 20.1 22 23 204 250
//  |     |         |                    |                              |                       |

// for (int j = 0; j < matrix_size && *exit_code == OK; ++j) {
//   matrix_t minor_matrix = {0};
//   *exit_code = s21_minor_matrix(A, 1, j + 1, &minor_matrix);
//   if (*exit_code != OK) continue;
//   double minor_det = s21_determinant_recursive(&minor_matrix, exit_code);
//   if (*exit_code != OK) continue;
//   double minor_sign = (j % 2 == 0) ? 1 : -1;
//   det += minor_sign * A->matrix[0][j] * minor_det;
//   s21_remove_matrix(&minor_matrix);
// }

// int s21_determinant(matrix_t *A, double *result) {
//   int exit_code = OK;
//   if (!s21_is_valid_matrix(A) || !result) {
//     return INVALID_MATRIX;
//   } else if (A->rows != A->columns) {
//     exit_code = CALC_ERROR;
//   } else {
//     int matrix_size = A->rows;
//     double det = 0.0;
//     if (matrix_size == 1) {
//       det = A->matrix[0][0];
//     } else if (matrix_size == 2) {
//       det =
//           A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] *
//           A->matrix[1][0];
//     } else if (matrix_size == 3) {
//       det = A->matrix[0][0] * A->matrix[1][1] * A->matrix[2][2] +  // 1 2 3
//             A->matrix[0][1] * A->matrix[1][2] * A->matrix[2][0] +  // 4 5 6
//             A->matrix[1][0] * A->matrix[2][1] * A->matrix[0][2] -  // 7 8 9
//             A->matrix[0][2] * A->matrix[1][1] * A->matrix[2][0] -
//             A->matrix[1][2] * A->matrix[2][1] * A->matrix[0][0] -
//             A->matrix[0][1] * A->matrix[1][0] * A->matrix[2][2];
//     } else {
//       for (int j = 0; j < matrix_size; ++j) {
//         matrix_t minor_matrix = {0};
//         s21_minor_matrix(A, 1, j + 1, &minor_matrix);
//         double minor_det = 0.0;
//         s21_determinant(&minor_matrix, &minor_det);
//         double minor_sign = (j % 2 == 0) ? 1 : -1;
//         det += minor_sign * A->matrix[0][j] * minor_det;
//         s21_remove_matrix(&minor_matrix);
//       }
//     }
//     *result = det;
//   }
//   return exit_code;
// }
