#ifndef MY_FILE 
#define MY_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_key.h"

int check_argv(int argc, char **argv, int *filter);
int get_array_to_sort(char *f_name, int filter, int **pstart, size_t *f_size);
int file_write(char *file_name, int *pstart, int *pend);
#endif