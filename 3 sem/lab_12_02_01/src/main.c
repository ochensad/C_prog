#include "task.h"
#include "io_lib.h"
#include "task_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char **argv)
{
    int filter_mode = 0;
    int error_code = check_argv(argc, argv, &filter_mode);

    if (error_code)
        return error_code;
    
    FILE *f;
    f = fopen(argv[1], "r");
    if (f == NULL)
        return ERROR_OPEN_FILE;
    
    size_t f_size = 0;
    error_code = file_size(f, &f_size);
    if (error_code || f_size == 0)
    {
        fclose(f);
        return ERROR_EMPTY_FILE;
    }

    int *pstart = NULL;
    pstart = malloc(f_size * sizeof(int));
    if (pstart == NULL)
    {
        fclose(f);
        return ERROR_MEMORY;
    }

    error_code = file_read(f, pstart, pstart + f_size);

    fclose(f);
    if (error_code)
    {
        free(pstart);
        return ERROR_READING;
    }

    if (filter_mode)
    {
        error_code = filter(&pstart, &f_size);
        if (error_code == ERROR_MEMORY)
        {
            free(pstart);
            return error_code;
        }
    }

    mysort(pstart, f_size, sizeof(int), greater);

    FILE *f_out;
    f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        free(pstart);
        return ERROR_OPEN_FILE;
    }

    file_write(f, pstart, pstart + f_size);
    free(pstart);
    return OK;
}