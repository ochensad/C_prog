#include <stdio.h>
#include <stdlib.h>

#include "array_func.h"

int main(int argc, char **argv)
{
    int error_code = ERROR_ARGV;

    if (argc != 3)
        return error_code;

    FILE *f;

    f = fopen(argv[1], "r");

    if (f == NULL)
    {
        error_code = ERROR_OPEN_FILE;
        return error_code;
    }

    product_t products[15];
    size_t j = 0;
    
    int p = atoi(argv[2]);

    if (p != 0)
        error_code = get_array(f, products, &j);

    if (error_code == OK)
        print_array(products, &j, p);
    fclose(f);
    return error_code;
}