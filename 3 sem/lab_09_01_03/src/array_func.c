#include "array_func.h"

int check_task(price_t p, product_t *product)
{
    if ((product->price) < p)
        return LESS;
    return MORE;
}

int get_array(FILE *f, product_t *products, size_t file_len)
{
    for (size_t i = 0; i < file_len; i++)
    {
        product_t product;
        if (read_struc(f, &product) != OK)
        {
            free_array(products, i);
            return ERROR_READING_FILE;
        }
        products[i] = product;
    }
    return OK;
}

void shift_el(product_t *products, size_t k, size_t len)
{
    for (size_t j = k; j < len - 1; j++)
        products[j] = products[j + 1];
}

int filt_array(product_t *products, size_t *file_len, price_t p)
{
    size_t count_del = 0;
    for (size_t i = 0; i < *file_len; i++)
        if (check_task(p, products + i) == MORE)
            count_del++;
    if (count_del == *file_len)
        return ERROR_EMPTY_ARRAY;
    
    for (size_t k = 0; k < count_del; k++)
        for (size_t j = 0; j < *file_len; j++)
            if (check_task(p, products + j) == MORE)
                shift_el(products, j, *file_len);
    
    *file_len -= count_del;
    return OK;
}

void print_array(product_t products[], size_t size)
{
    for (size_t i = 0; i < size; i++)
        print_struct(products[i]);
}

void free_array(product_t *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        free(arr[i].name);
    }

    free(arr);
}