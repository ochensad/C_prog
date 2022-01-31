#ifndef MY_MATRIX
#define MY_MATRIX

#include "sturct.h"
#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

int read_matrix(matrix_t *matrix);
void print_matrix(matrix_t *matrix);
void free_matrix(int **arr, int n);
int create_matrix(matrix_t *matrix);
#endif