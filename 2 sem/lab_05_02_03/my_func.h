#ifndef MY_FILE
#define MY_FILE

#define ERROR_NO_NUMBERS -1
#define ERROR_NO_FILE -2
#define ERROR_EMPTY_FILE -3
#define ERROR_CANT_READ_FILE -4
#define NO -5
#define YES -6

#define PROCESS_SUCCESS 0


int avg(FILE *f, size_t *n, double *sum);
int sigma(FILE *f, size_t *n, double *sum, double *expr);
int empirical_rule(FILE *f, double expr, double a);
int size_check(FILE *f, size_t *len);
#endif