#include "task.h"
#include "task_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_argv(int argc, char **argv, int *filter)
{
    if (argc == 4 && strcmp(argv[3], "f") == 0)
    {
        *filter = 1;
        return OK;
    }
    if (argc == 3)
        return OK;
    return ERROR_ARGV;
}

int filter(int **pstart, size_t *f_size)
{
    int error_code;

    int *pstart_new = NULL;
    pstart_new = malloc(*f_size * sizeof(int));
    if (pstart_new == NULL)
        return ERROR_MEMORY;
    int *pend_new = NULL;

    error_code = key(*pstart, *pstart + *f_size, &pstart_new, &pend_new);
    if (error_code)
    {
        free(*pstart);
        free(pstart_new);
        return error_code;
    }

    free(*pstart);
    *pstart = pstart_new;
    *f_size = pend_new - pstart_new;
    return OK;
}

int greater(const void *a, const void *b)
{
    const int *left = a;
    const int *right = b;
    
    return *left - *right;
}




