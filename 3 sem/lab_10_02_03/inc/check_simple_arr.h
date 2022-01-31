#ifndef CHECK_SIMPLE
#define CHECK_SIMPLE

#include "list_func.h"
#include <check.h>
#include <stdlib.h>

#define FAIL 9

int comp_arr(num_t *a, num_t *b);
Suite *simple_arr_test_suite(Suite *s);

#endif