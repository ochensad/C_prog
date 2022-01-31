#ifndef CHECK_A
#define CHECK_A

#include "add.h"
#include "check_multiplication.h"
#include "matrix.h"

#include <check.h>

#define OK 0
#define FAIL 1

int comp_matrix(matrix_t *mat_1, matrix_t *mat_2);
void write_mat(matrix_t *mat, int a[]);

Suite *add_test_suite(Suite *s);

#endif