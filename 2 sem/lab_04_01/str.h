#ifndef STRING_H
#define STRING_H


#define STR_MAX 255
#define EXIT_INVALID_LEN 2
#define TEST_NUM 6

#include <stdlib.h>

typedef char str_t;

const char *my_strrchr(const str_t *string, int symbol);
const char *my_strchr(const str_t *string, int symbol);
const char *my_strpbrk(const str_t *str_1, const str_t *str_2);
size_t my_strspn(const str_t *str_1, const str_t *str_2);
size_t my_strcspn(const str_t *str_1, const str_t *str_2);

#endif