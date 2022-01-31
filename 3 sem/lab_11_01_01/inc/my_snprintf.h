#ifndef MY_SNP
#define MY_SNP

#include "errors.h"

#include <stdio.h>
#include <stdarg.h>

#define BUF_SIZE 100
#define MAX_ARR_OCT_LEN 20
#define MAX_ARR_HEX_LEN 20
#define MAX_ARR_OCT_LONG_LEN 20

int my_snprintf(char *stream, size_t n, const char *format, ...);
#endif