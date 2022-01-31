#include <stdio.h>
#include <math.h>

#include "my_func.h"

int avg(FILE *f, size_t *n, double *sum)
{
    if (fseek(f, 0, SEEK_SET))
        return ERROR_CANT_READ_FILE;
    double x = 0.0;
    size_t count = 0;
    while (fscanf(f, "%lf", &x) == 1)
    {
        *sum += x;
        count++;
    }
    if (count == 0)
        return ERROR_NO_NUMBERS;
    *n = count;
    *sum /= *n;
    return PROCESS_SUCCESS;
}

int sigma(FILE *f, size_t *n, double *sum, double *expr)
{
    if (fseek(f, 0, SEEK_SET))
        return ERROR_CANT_READ_FILE;
    double sum_of_sqrt = 0;
    double x = 0.0;
    while (fscanf(f, "%lf", &x) == 1)
    {
        sum_of_sqrt += ((x - *sum) * (x - *sum));
    }
    sum_of_sqrt /= *n;
  
    *expr = sqrt(sum_of_sqrt);
    return PROCESS_SUCCESS;
}

int empirical_rule(FILE *f, double expr, double a)
{
    if (fseek(f, 0, SEEK_SET))
        return ERROR_CANT_READ_FILE;
    double x = 0.0;
    while (fscanf(f, "%lf", &x) == 1)
        if (x <= a - 3.0 * expr && x >= a + 3.0 * expr)
            return NO;
    return YES;
}
