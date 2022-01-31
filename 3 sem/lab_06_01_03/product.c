#include "product.h"

int check_name(char *str, char *str_dst)
{
    int flag = 0;
    int flag_1 = 0;

    for (size_t i = 0; str[i] != '\0' && flag == 0; i++)
    {
        if (str[i] == '\n' && i == 25)
            flag = 1;

        if (isalpha((int)str[i]) != 0)
            flag_1 = 1;
    }

    if (!flag_1 || flag)
        return ERROR_STR;
    
    strcpy(str_dst, str);
    return OK;
}

int check_price(char *str, price_t *price)
{
    int flag = 0;
    for (size_t i = 0; str[i + 1] != '\0' && flag == 0; i++)
    {
        if (isspace((int)str[i]) == 0)
            if (isdigit((int)str[i]) == 0)
                flag = 1;
    }
    if (flag)
        return ERROR_STR;

    int buf = atoi(str);
    *price = buf;
    return OK;
}

int read_struc(FILE *f, product_t *product)
{
    char buf_name[MAX_LEN + 2];
    char tmp_name[MAX_LEN + 1];

    if (fgets(buf_name, MAX_LEN + 2, f) == NULL)
        return ERROR_READING_FILE;
    if (check_name(buf_name, tmp_name) != OK)
        return ERROR_READING_FILE;
    
    char buf_price[MAX_LEN];
    if (fgets(buf_price, MAX_LEN, f) == NULL)
        return ERROR_READING_FILE;

    price_t price_new;
    if (check_price(buf_price, &price_new) != OK)
        return ERROR_READING_FILE;

    strcpy(product->name, tmp_name);
    product->price = price_new;

    return OK;
} 

void print_struct(product_t product)
{
    printf("%s", product.name);
    printf("%u\n", product.price);
}

