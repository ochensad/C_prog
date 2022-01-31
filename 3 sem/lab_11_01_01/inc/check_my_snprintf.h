#ifndef CHECK_SNPRINTF
#define CHECK_SNPRINTF

#include "my_snprintf.h"
#include <check.h>

#define FAIL_N 1
#define FAIL_BUF 2

Suite *char_test_suite(Suite *s);
Suite *num_test_suite(Suite *s);
Suite *int_test_suite(Suite *s);

#endif