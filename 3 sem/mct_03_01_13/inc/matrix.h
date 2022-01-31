#ifndef MY_MATRIX
#define MY_MATRIX

#include "struct.h"
#include "errors.h"

void free_array(matrix_t *mat_arr, int n);
int read_matrix(matrix_t *mat);
void free_array(matrix_t *mat_arr, int n);
int **allocate_matrix(size_t row, size_t column);
void mat_copy(matrix_t *new, matrix_t *old);
void print_array(matrix_t *arr, int n);
#endif