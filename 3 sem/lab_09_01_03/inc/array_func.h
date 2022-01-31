#ifndef ARRAY
#define ARRAY

#include <stdio.h>
#include "product.h"

#define LESS 1
#define MORE 2
#define ARRAY_LEN 15

int get_array(FILE *f, product_t products[], size_t file_len);
int filt_array(product_t *products, size_t *file_len, price_t p);
void print_array(product_t products[], size_t size);
void free_array(product_t *arr, size_t n);
#endif