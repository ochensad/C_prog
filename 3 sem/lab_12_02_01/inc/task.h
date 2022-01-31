#ifndef MY_TASK
#define MY_TASK

#include "errors.h"
#include <stdio.h>

int check_argv(int argc, char **argv, int *filter);
int filter(int **pstart, size_t *f_size);
int greater(const void *a, const void *b);
#endif