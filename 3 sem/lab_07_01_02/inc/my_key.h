#ifndef MY_FILT
#define MY_FILT

#include "errors.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GET_NEG 1
#define NO_NEG 0

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
#endif