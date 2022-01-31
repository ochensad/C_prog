#ifndef MY_SORT
#define MY_SORT

#include <string.h>
#include "errors.h"

#define GREATER 1
#define SMALLER 0


int mysort(void *arr, size_t count, size_t size, int (*greater)(const void*, const void*));
int greater(const void *a, const void *b);
#endif