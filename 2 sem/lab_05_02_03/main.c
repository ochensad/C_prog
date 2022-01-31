#include <stdio.h>

#include "my_func.h"

int main(int argc, char **argv)
{
    FILE *f;
    double sigma_expr, sum = 0.0, avg_x;
    size_t n = 0;

    if (argc != 2)
        return ERROR_NO_NUMBERS;
    
    f = fopen(argv[1], "r");

    if (f == NULL)
        return ERROR_NO_FILE;
    
    if (avg(f, &n, &sum) != PROCESS_SUCCESS)
    {
        fclose(f);
        return ERROR_NO_NUMBERS;
    }
    if (n == 0)
    {
        fclose(f);
        return ERROR_NO_NUMBERS;
    }

    avg_x = sum;
    
    if (sigma(f, &n, &sum, &sigma_expr) != PROCESS_SUCCESS)
        return ERROR_CANT_READ_FILE;
    
    if (empirical_rule(f, sigma_expr, avg_x) == NO)
    {
        fclose(f);
        printf("0");
        return PROCESS_SUCCESS;
    }
    fclose(f);
    printf("1");
    return PROCESS_SUCCESS;
}