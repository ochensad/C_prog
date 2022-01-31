#include "product.h"

int check_name(const char *str)
{
    int flag_1 = 0;

    for (size_t i = 0; str[i] != '\0'; i++)
        if (isalpha((int)str[i]) != 0)
            flag_1 = 1;

    if (flag_1 == 0)
        return ERROR_STR;
    
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

int read_name(FILE *f, product_t *product)
{
    size_t size = 1;
    size_t step = 2;

    product->name = NULL;
    product->name = malloc(size * sizeof(char));
    if (product->name == NULL)
        return ERROR_MEMORY;
    
    char smb;
    size_t i = 0;

    while ((smb = getc(f)) != '\n' && smb != EOF)
    {
        if (i < size)
        {
            product->name[i] = smb;
        }
        else
        {
            char *p = realloc(product->name, size * step * sizeof(char));
            if (p == NULL)
                return ERROR_MEMORY;
            product->name = p;
            size *= step;
            product->name[i] = smb;
        }
        i++;
    }
    if (size == i)
    {
        char *p = realloc(product->name, (size + 1) * sizeof(char));
        if (p == NULL)
            return ERROR_MEMORY;
        product->name = p;
        size++;
        product->name[i] = '\0';
    }
    else
        product->name[i] = '\0';
    
    if (check_name(product->name) != OK)
    {
        free(product->name);
        return ERROR_STR;
    }
    return OK;
}

int read_price(FILE *f, product_t *product)
{
    char buf_price[MAX_PRICE_LEN];
    if (fgets(buf_price, MAX_PRICE_LEN, f) == NULL)
        return ERROR_READING_FILE;

    price_t price_new;
    if (check_price(buf_price, &price_new) != OK)
        return ERROR_READING_FILE;
    product->price = price_new;

    return OK;
} 

int read_struc(FILE *f, product_t *product)
{
    if (read_name(f, product) != OK)
        return ERROR_STR;
    if (read_price(f, product) != OK)
    {
        free(product->name);
        return ERROR_STR;
    }
    return OK;
}

void print_struct(product_t product)
{
    printf("%s\n", product.name);
    printf("%u\n", product.price);
}

