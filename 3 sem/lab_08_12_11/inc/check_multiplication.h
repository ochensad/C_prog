#ifndef CHECK_M
#define CHECK_M

#include "multiplication.h"
#include <check.h>
#include "matrix.h"

#define FAIL 1
#define OK 0
#define EPS 10e-8

int comp_matrix(matrix_t *mat_1, matrix_t *mat_2);
void write_mat(matrix_t *mat, int a[]);

Suite* mult_test_suite(Suite *s);
#endif