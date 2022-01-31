#ifndef MY_FILE
#define MY_FILE

#include <stdio.h>
#include <string.h>

#define EXIT_INVALID_ARGV -1
#define EXIT_NO_FILE -2
#define OK 0
#define ERROR_SIZE_OF_FILE -3
#define ERROR_READING_FILE -4

int delete_st(FILE *f);
int print_file(FILE *f);
#endif