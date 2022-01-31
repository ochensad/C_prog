#include <stdio.h>
#include <stdlib.h>

#include "my_func.h"

int create_f(FILE *f, int num, const int begin, const int end)
{
    int x;
    for (int i = 0; i < num; i++)
    {
        x = begin + rand() % (end - begin);
        if (fwrite(&x, sizeof (int), 1, f) != 1)
            return ERROR_INVALID_NUMBERS;
    }
    return PROCESS_SUCCESS;
}

int size_f(FILE *f, size_t *size)
{
    long size_of_st;

    if (fseek(f, 0, SEEK_END))
        return ERROR_CANT_READ_FILE;

    size_of_st = ftell(f);
    if (size_of_st <= 0)
        return ERROR_EMPTY_FILE;
    
    *size = size_of_st;
    return PROCESS_SUCCESS;
}

int size_check(FILE *f, size_t *len)
{
    size_t size;

    if (size_f(f, &size) != PROCESS_SUCCESS)
        return ERROR_CANT_READ_FILE;

    if (size % sizeof(int))
        return ERROR_CANT_READ_FILE;
    
    *len = size / sizeof(int);
    return PROCESS_SUCCESS;
}

int print_f(FILE *f)
{
    size_t len;
    int buf;

    if (size_check(f, &len))
        return ERROR_CANT_READ_FILE;

    get_number_by_pos(f, 0, &buf);
    printf("%d", buf);
    for (size_t i = 1; i < len; i++)
    {
        get_number_by_pos(f, i, &buf);
        printf(" %d", buf);
    }
    
    return PROCESS_SUCCESS;
}

int get_number_by_pos(FILE *f, int pos, int *num)
{
    long int j = ftell(f);

    if (fseek(f, pos * sizeof (int), SEEK_SET))
        return ERROR_INVALID_NUMBERS;
    if (fread(num, sizeof (int), 1, f) != 1)
        return ERROR_INVALID_NUMBERS;
    fseek(f, j, SEEK_SET);
    return PROCESS_SUCCESS;
}
int put_number_by_pos(FILE *f, int pos, int num)
{
    long int j = ftell(f);

    if (fseek(f, pos * sizeof (int), SEEK_SET))
        return ERROR_INVALID_NUMBERS;
    if (fwrite(&num, sizeof (int), 1, f) != 1)
        return ERROR_INVALID_NUMBERS;
    fseek(f, j, SEEK_SET);
    return PROCESS_SUCCESS;
}

int sort_f(FILE *f)
{
    size_t len;
    int left, right;
    
    if (size_check(f, &len))
        return ERROR_CANT_READ_FILE;
    
    for (size_t i = 0; i < len; i++)
        for (size_t j = 0; j < len - i - 1; j++)
        {
            get_number_by_pos(f, j, &left);
            get_number_by_pos(f, j + 1, &right);
            if (left > right)
            {
                put_number_by_pos(f, j + 1, left);
                put_number_by_pos(f, j, right);
            }
        }
    
    return PROCESS_SUCCESS;
}
