#ifndef MY_FILE
#define MY_FILE

#include <stdio.h>
#include <string.h>
#define MAX_LEN 255
#define EXIT_INVALID_ARGV -1
#define EXIT_NO_FILE -2
#define EMPTY_STR -3
#define YES -4
#define NO -5
#define OK 1

int get_char_dict(char *str, char *dict);
int a_i(char *s_src, char *s_dst);
int find_pol(char *s);
#endif