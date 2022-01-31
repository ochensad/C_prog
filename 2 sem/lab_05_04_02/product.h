#ifndef MY_FILE
#define MY_FILE

#include "struct.h"

#define SUCCESS 0
#define ERROR_INPUT_STRUCT 1
#define ERROR_OUTPUT_STRUC 2
#define ERROR_POS 3
#define NO 4
#define YES 5

int get_struct_by_pos(FILE *f, size_t pos, product_t *product);
int put_struct_by_pos(FILE *f_src, size_t pos, product_t product);
int read_struct(product_t *product);
void print_struct(product_t product);
int check_end_of_str(product_t *product, char *str);
int greater(product_t *left, product_t *right);

#endif