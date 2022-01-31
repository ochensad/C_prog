#ifndef MULT
#define MULT

#include "matrix.h"

void multiplication_matrix(matrix_t *res_matrix, matrix_t *matrix, matrix_t *matrix_2);
void copy_matrix(matrix_t *a, matrix_t *b);
int multiplication(matrix_t *a, matrix_t *b, matrix_t *res);
#endif