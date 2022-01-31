#ifndef MY_MATRIX
#define MY_MATRIX

#include <stdio.h>

#include "struct.h"
#include "errors.h"

int read_matrix(FILE *f, matrix_t *matrix);
int create_matrix(matrix_t *matrix);
void free_matrix(double **arr, int n);
void print_matrix(FILE *f, matrix_t *matrix);
#endif