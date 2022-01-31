#ifndef MY_ST
#define MY_ST

#include <stdio.h>
#include <string.h>
#include "struct.h"

#define SUCCESS 1
#define ERROR_INPUT_STRUCT -3

student_t get_struct_by_pos(FILE *f, int i);
int put_struct_by_pos(FILE *f, student_t student, int i);
int compare(student_t comp);
#endif