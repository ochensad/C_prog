#ifndef ERROR_SORT
#define ERROR_SORT

#include <stdio.h>
#include <check.h>
#include "my_sort.h"

#define OK 0
#define FAIL 1



int comp_arrays(int *array_one, int len_one, int *array_two, int len_two);
void check_sort(int *arr_1, size_t len_1, int *arr_2, size_t len_2);

Suite *sort_test_suite(Suite *s);

#endif