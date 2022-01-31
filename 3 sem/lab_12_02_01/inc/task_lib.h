#ifndef MY_LIB
#define MY_LIB
#include <stdio.h>

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void mysort(void *arr, size_t count, size_t size, int (*greater)(const void*, const void*));
#endif