#ifndef PRODUCT
#define PRODUCT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct.h"
#include "errors.h"

int read_struc(FILE *f, product_t *product);
void print_struct(product_t product);
#endif