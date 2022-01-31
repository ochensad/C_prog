#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "my_func.h"
/*
Целочисленный тип int
Сортировка пузырьком
По убыванию
*/

int main(int argc, char **argv)
{
    FILE *f;
    const int begin = -1000;
    const int end = 1000;
    if (argc < 2)
        return ERROR_INVALID_KEY;

    if (strcmp(argv[1], "c") == 0 && argc == 4)
    {
        f = fopen(argv[3], "wb");

        if (f == NULL)
            return ERROR_NO_FILE;

        int count = atoi(argv[2]);
        if (count <= 0)
        {
            fclose(f);
            return ERROR_INVALID_NUMBERS;
        }
        if (create_f(f, count, begin, end) == ERROR_INVALID_NUMBERS)
        {
            fclose(f);
            return ERROR_INVALID_NUMBERS;
        }
        fclose(f);
    }
    else if (strcmp(argv[1], "p") == 0 && argc == 3)
    {
        f = fopen(argv[2], "rb");

        if (f == NULL)
        {
            fclose(f);
            return ERROR_NO_FILE;
        }
        if (print_f(f) != PROCESS_SUCCESS)
        {
            fclose(f);
            return ERROR_CANT_READ_FILE;
        }
        fclose(f);
    }
    else if (strcmp(argv[1], "s") == 0 && argc == 3)
    {
        f = fopen(argv[2], "rb+");
        if (f == NULL)
        {
            fclose(f);
            return ERROR_NO_FILE;
        }
        if (sort_f(f) != PROCESS_SUCCESS)
        {
            fclose(f);
            return ERROR_CANT_READ_FILE;
        }
        fclose(f);
    }
    else
        return ERROR_INVALID_KEY;
    return PROCESS_SUCCESS;
}