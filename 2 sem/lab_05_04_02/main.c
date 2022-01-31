#include <stdio.h>
#include <string.h>

#include "product.h"
#include "my_func.h"
#include "struct.h"

int main(int argc, char **argv)
{
    FILE *f_in;
    FILE *f_out;

    if (argc == 3 && strcmp(argv[1], "cr") == 0)
    {
        f_in = fopen(argv[2], "wb");

        if (f_in == NULL)
            return ERROR_FILE_OPEN;
        if (create_file(f_in) != SUCCESS)
        {
            fclose(f_in);
            return CR_ERROR;
        }
        fclose(f_in);
    }
    else if (argc == 4 && strcmp(argv[1], "fb") == 0)
    {
        f_in = fopen(argv[2], "rb");

        if (f_in == NULL)
            return ERROR_FILE_OPEN;

        if (print_product_filter(f_in, argv[3]) != SUCCESS)
            return FB_ERROR;
            
        fclose(f_in);
    }
    else if (argc == 4 && strcmp(argv[1], "sb") == 0)
    {
        f_in = fopen(argv[2], "rb");
        f_out = fopen(argv[3], "wb+");

        if (f_in == NULL || f_out == NULL)
            return ERROR_FILE_OPEN;
        
        if (copy_file(f_in, f_out) != SUCCESS)
        {
            fclose(f_in);
            fclose(f_out);
            return SB_ERROR;
        }
        fclose(f_in);
        if (file_sort(f_out) != SUCCESS)
        {
            fclose(f_out);
            return SB_ERROR;
        }

        fclose(f_out);
    }
    else if (argc == 3 && strcmp(argv[1], "ab") == 0)
    {
        f_in = fopen(argv[2], "rb+");

        if (f_in == NULL)
            return ERROR_FILE_OPEN;
        
        if (file_add(f_in) != SUCCESS)
        {
            fclose(f_in);
            return AB_ERROR;
        }
        fclose(f_in);
    }
    else if (argc == 3 && strcmp(argv[1], "rb") == 0)
    {
        f_in = fopen(argv[2], "rb");

        if (f_in == NULL)
            return ERROR_FILE_OPEN;
        
        print_file(f_in);
        fclose(f_in);
    }
    else
        return ERROR_ARGV;
    return SUCCESS;
}