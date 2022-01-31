#include <stdio.h>
#include <stdlib.h>

#include "array_func.h"

int main(int argc, char **argv)
{
    int error_code = OK;

    if (argc != 3)
        return ERROR_ARGV;

    int p = atoi(argv[2]);
    if (p == 0)
        return ERROR_ARGV;

    FILE *f;

    f = fopen(argv[1], "r");

    if (f == NULL)
        return ERROR_OPEN_FILE;
    
    size_t file_len;

    if (fscanf(f, "%zu\n", &file_len) != 1 || file_len == 0)
    {
        fclose(f);
        return ERROR_READING_FILE;
    }

    product_t *products = calloc(file_len, sizeof(product_t));

    if (products == NULL)
    {
        fclose(f);
        return ERROR_MEMORY;
    }

    error_code = get_array(f, products, file_len);
    fclose(f);
    if (error_code)
        return error_code;
    

    error_code = filt_array(products, &file_len, p);

    if (error_code == ERROR_EMPTY_ARRAY)
    {
        free_array(products, file_len);
        return OK;
    }

    product_t *tmp = realloc(products, file_len * sizeof(product_t));

    if (tmp == NULL)
        return ERROR_MEMORY;
    
    products = tmp;
    
    if (error_code == OK)
    {
        print_array(products, file_len);
        free_array(products, file_len);
    }
    return error_code;
}