#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

#define STR_MAX 256
#define WORD_MAX 16
#define NWORD_MAX 127

#define EXIT_INVALID_LEN 2
#define EXIT_ZERO_LEN 3
#define NO_WORDS_ERROR 4

typedef char str_t[STR_MAX + 1];
typedef char str_arr_t[NWORD_MAX][WORD_MAX + 1];
typedef char word_t[WORD_MAX + 1];

int read_str(str_t s);
int split(str_t s, word_t punct_marks, str_arr_t s_arr, size_t *num_of_word);
int bubble_sort(str_arr_t s_arr, size_t num_of_word);
int join(str_t str, str_arr_t words, size_t n);

#endif