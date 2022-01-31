#ifndef ERROR_KEY
#define ERROR_KEY

#include "check_my_sort.h"
#include "my_key.h"
#include "file_func.h"
#include "errors.h"


int check_key(int *arr_1, size_t len_1, int *arr_2, size_t len_2);
Suite *key_test_suite(Suite *s);
#endif