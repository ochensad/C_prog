#include "file_func.h"

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

int file_size(FILE *f, size_t *size)
{
    int buf;
    int er_flag = 1;
    while (er_flag == 1)
    {
        er_flag = fscanf(f, "%d", &buf);
        if (er_flag == 0)
            return ERROR_READING_FILE;
        if (er_flag != EOF)
            *size += 1;
    }
    if (*size == 0)
        return ERROR_EMPTY_FILE;
    return OK;
}



int file_read(FILE *f, int *pstart, int *pend)
{
    if (fseek(f, 0, SEEK_SET))
        return ERROR_READING_FILE;

    int er_flag = 1;

    while (pstart < pend)
    {
        er_flag = fscanf(f, "%d", pstart);
        if (er_flag == 0)
            return ERROR_READING_FILE;
        
        pstart++;
    }
    return OK;
}

int get_array_to_filt(FILE *f, int **pstart, size_t *f_size)
{
    int error_code = OK;

    error_code = file_size(f, f_size);

    if (error_code)
        return error_code;
    
    *pstart = malloc(*f_size * sizeof(int));

    if (*pstart == NULL)
        return ERROR_MEMORY;
    
    error_code = file_read(f, *pstart, *pstart + *f_size);

    return error_code;
}

int get_array_to_sort(char *f_name, int filter, int **pstart, size_t *f_size)
{
    FILE *f;

    f = fopen(f_name, "r");

    if (f == NULL)
        return ERROR_OPEN_FILE;
    
    int error_code = OK;

    error_code = get_array_to_filt(f, pstart, f_size);

    fclose(f);

    if (error_code)
    {
        free(*pstart);
        return error_code;
    }
    if (filter)
    {
        int *pstart_new = NULL;
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
    }
    return OK;
}

int file_write(char *file_name, int *pstart, int *pend)
{
    FILE *f;
    f = fopen(file_name, "w");

    if (f == NULL)
        return ERROR_OPEN_FILE;
    
    int *ps = pstart;
    int *pe = pend;

    while (ps < pe)
        fprintf(f, "%d ", *(ps++));
    
    fclose(f);
    return OK;
}