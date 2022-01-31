#include "array_func.h"

int check_task(price_t p, product_t *product)
{
    if ((product->price) < p)
        return LESS;
    return MORE;
}

int get_array(FILE *f, product_t products[], size_t *j)
{
    int file_len;

    if (fscanf(f, "%d\n", &file_len) != 1)
        return ERROR_READING_FILE;
    
    if (file_len <= 0)
        return ERROR_LEN;
    
    for (int i = 0; i < file_len; i++)
    {
        product_t product;
        if (read_struc(f, &product) != OK)
        {
            return ERROR_READING_FILE;
        }
        if (*j < 15)
        {
            products[*j] = product;
            *j += 1;
        }
        else
            return ERROR_LEN;
    }
    return OK;
}

void print_array(product_t products[], size_t *j, price_t p)
{
    for (size_t i = 0; i < *j; i++)
        if (check_task(p, &products[i]) == LESS)
            print_struct(products[i]);
}