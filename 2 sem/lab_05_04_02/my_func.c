#include <stdio.h>
#include "product.h"
#include "my_func.h"
#include "struct.h"

int size_of_file(FILE *f, size_t *size)
{
    long size_of_st;

    if (fseek(f, 0, SEEK_END))
        return ERROR_READING_FILE;

    size_of_st = ftell(f);
    if (size_of_st < 0)
        return ERROR_SIZE_OF_FILE;
  
    *size = size_of_st;
    return SUCCESS;
}

int create_file(FILE *f)
{
    product_t product = { 0 };
    while (read_struct(&product) == SUCCESS)
        if (fwrite(&product, sizeof (product_t), 1, f) != 1)
            return ERROR_INVALID_STRUCT;
    return SUCCESS;
}

int size_check(FILE *f, size_t *len)
{
    size_t size;

    if (size_of_file(f, &size) == ERROR_READING_FILE)
        return ERROR_READING_FILE;

    if (size % sizeof(product_t))
        return ERROR_SIZE_OF_FILE;
    
    *len = size / sizeof(product_t);
    return SUCCESS;
}

int print_product_filter(FILE *f_in, name_t str)
{
    product_t product = { 0 };
    size_t len, count = 0;

    if (str[0] == '\0')
        return ERROR_ZERO_LEN;

    if (size_check(f_in, &len))
        return ERROR_READING_FILE;


    for (size_t i = 0; i < len; i++)
    {
        if (get_struct_by_pos(f_in, i, &product))
            return ERROR_INVALID_STRUCT;
        if (check_end_of_str(&product, str) == YES)
        {
            print_struct(product);
            count++;
        }
    }

    if (count == 0)
        return FB_ERROR;
    return SUCCESS;
}

int copy_file(FILE *f_in, FILE *f_out)
{
    product_t product = { 0 };

    size_t len;

    if (size_check(f_in, &len))
        return ERROR_READING_FILE;

    for (size_t i = 0; i < len; i++)
    {
        if (get_struct_by_pos(f_in, i, &product))
            return ERROR_INVALID_STRUCT;
        if (fwrite(&product, sizeof (product_t), 1, f_out) != 1)
            return ERROR_READING_FILE;
    }
    return SUCCESS;
}

int file_sort(FILE *f)
{
    product_t left = { 0 }, right = { 0 };

    size_t len;

    if (size_check(f, &len))
        return ERROR_READING_FILE;

    for (size_t i = 0; i < len; i++)
        for (size_t j = 0; j < len - i - 1; j++)
        {
            if (get_struct_by_pos(f, j, &left))
                return ERROR_INVALID_STRUCT;
            if (get_struct_by_pos(f, j + 1, &right))
                return ERROR_INVALID_STRUCT;

            if (greater(&left, &right) == YES)
            {
                put_struct_by_pos(f, j + 1, left);
                put_struct_by_pos(f, j, right);
            }
        }
    return SUCCESS;
}

int find_pos(FILE *f, product_t *new_product, size_t *new_pos, size_t len)
{
    size_t i;
    product_t product = { 0 };
    *new_pos = len;
    for (i = 0; i < len && *new_pos == len; i++)
    {
        if (get_struct_by_pos(f, i, &product))
            return ERROR_INVALID_STRUCT;
        if (greater(&product, new_product) == YES)
            *new_pos = i;
    }

    return SUCCESS;
}

int insert_by_pos(FILE *f, size_t new_pos, product_t *new_product)
{
    product_t product = { 0 };
    size_t len;

    if (fseek(f, 0, SEEK_END))
        return ERROR_READING_FILE;
    if (fwrite(new_product, sizeof (product_t), 1, f) != 1)
        return ERROR_INPUT_STRUCT;
    if (fseek(f, 0, SEEK_SET))
        return ERROR_READING_FILE;
    
    if (size_check(f, &len))
        return ERROR_READING_FILE;

    for (size_t i = len - 1; i > new_pos; i--)
    {
        if (get_struct_by_pos(f, i - 1, &product))
            return ERROR_INVALID_STRUCT;
        if (put_struct_by_pos(f, i, product))
            return ERROR_INVALID_STRUCT;
    }
    if (put_struct_by_pos(f, new_pos, *new_product))
        return ERROR_INVALID_STRUCT;

    return SUCCESS; 
}

int file_add(FILE *f)
{
    product_t new_product = { 0 };

    size_t len;

    if (size_check(f, &len))
        return ERROR_READING_FILE;

    size_t new_pos;
    if (read_struct(&new_product) != SUCCESS)
        return ERROR_INPUT_STRUCT;

    if (find_pos(f, &new_product, &new_pos, len) != SUCCESS)
        return ERROR_INVALID_STRUCT;
    
    if (insert_by_pos(f, new_pos, &new_product) != SUCCESS)
        return ERROR_INVALID_STRUCT;

    return SUCCESS;
}

int print_file(FILE *f)
{
    product_t product = { 0 };

    size_t len;

    if (size_check(f, &len))
        return ERROR_READING_FILE;

    for (size_t i = 0; i < len; i++)
    {
        get_struct_by_pos(f, i, &product);
        print_struct(product);
    }
    return SUCCESS;
}