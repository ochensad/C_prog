#include <stdio.h>
#include <string.h>

#include "product.h"

int get_struct_by_pos(FILE *f, size_t pos, product_t *product)
{
    long int j = ftell(f);
    if (fseek(f, pos * sizeof(product_t), SEEK_SET))
        return ERROR_POS;
    if (fread(product, sizeof(product_t), 1, f) != 1)
        return ERROR_INPUT_STRUCT;
    if (fseek(f, j, SEEK_SET))
        return ERROR_POS;
    return SUCCESS;
}

int put_struct_by_pos(FILE *f_src, size_t pos, product_t product)
{
    long int j = ftell(f_src);
    if (fseek(f_src, pos * sizeof(product_t), SEEK_SET))
        return ERROR_POS;
    if (fwrite(&product, sizeof(product_t), 1, f_src) != 1)
        return ERROR_OUTPUT_STRUC;
    if (fseek(f_src, j, SEEK_SET))
        return ERROR_POS;
    return SUCCESS;
}

int read_struct(product_t *product)
{
    if (scanf("%s", (product->name)) != 1 || strlen(product->name) > NAME_LEN)
        return ERROR_INPUT_STRUCT;
    if (scanf("%s", (product->produser)) != 1 || strlen(product->produser) > PRODUCER_LEN)
        return ERROR_INPUT_STRUCT;
    if (scanf("%u", &product->price) != 1)
        return ERROR_INPUT_STRUCT;
    if (scanf("%u", &product->amount) != 1)
        return ERROR_INPUT_STRUCT;
    return SUCCESS;
}
void print_struct(product_t product)
{
    printf("%s\n", product.name);
    printf("%s\n", product.produser);
    printf("%u\n", product.price);
    printf("%u\n", product.amount);
}

int check_end_of_str(product_t *product, char *str)
{
    if (strlen(str) > strlen(product->name))
        return NO;
      
    size_t k = strlen(product->name) - 1;
    for (size_t i = strlen(str); i != 0; i--)
    {
        if ((product->name[k]) != str[i - 1])
            return NO;
        k--;
    }

    return YES;
}

int greater(product_t *left, product_t *right)
{
    if (left->price < right->price)
        return YES;
    if (left->price > right->price)
        return NO;
    if (left->amount < right->amount)
        return YES;
    return NO;
}