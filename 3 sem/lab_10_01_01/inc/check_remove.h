#ifndef CHECK_REMOVE
#define CHECK_REMOVE

#include "list_func.h"
#include <check.h>

#define FAIL 9

int comp_lists(node_t *head_1, node_t *head_2);
Suite *remove_test_suite(Suite *s);

#endif