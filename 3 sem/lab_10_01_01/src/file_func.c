#include "file_func.h"
#include <stdlib.h>

int read_file(set_t *arr, FILE *f)
{
    arr->arr = NULL;
    arr->size = 0;
    size_t step = 1;
    int *tmp;

    while (feof(f) == 0)
    {
        tmp = realloc(arr->arr, (arr->size + step) * sizeof(int));
        if (tmp == NULL)
        {
            free(arr->arr);
            return ERROR_MEMORY;
        }

        arr->arr = tmp;
        if (fscanf(f, "%d", arr->arr + arr->size) != 1)
        {
            free(arr->arr);
            return ERROR_READING;
        }
        arr->size++;
    }
    return OK;
}