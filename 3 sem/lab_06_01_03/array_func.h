#ifndef ARRAY
#define ARRAY

#include <stdio.h>
#include "product.h"

#define LESS 1
#define MORE 2
#define ARRAY_LEN 15

int get_array(FILE *f, product_t products[], size_t *j);
void print_array(product_t products[], size_t *j, price_t p);
#endif