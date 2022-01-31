#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

#define STR_MAX 256
#define WORD_MAX 16

#define EXIT_INVALID_LEN 2
#define EXIT_ZERO_LEN 3
#define YES 4
#define NO 6

typedef char str_t[STR_MAX + 1];
typedef char word_t[WORD_MAX + 1];

int read_str(str_t s);
int add_letter(str_t word, size_t *num_of_letter, str_t s, size_t i);
int find_num(str_t s);
int is_num(str_t e);
int count_numbers(str_t e, size_t *k);
int compare(word_t str1, int ch);
#endif
