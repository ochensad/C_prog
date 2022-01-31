#include "add.h"
#include <math.h>
#include <string.h>

int new_row_elem(matrix_t *matrix, int j)
{
    double arifm_mean;
    double num = 0.0;
    double sum = 0.0;
    for (int i = 0; i < matrix->rows; i++)
    {
        num++;
        sum += matrix->matrix[i][j];
    }

    arifm_mean = floor(sum / num);
    return (int)arifm_mean;
}

int new_column_elem(matrix_t *matrix, int i)
{
    int min = matrix->matrix[i][0];
    for (int j = 0; j < matrix->columns; j++)
        if (matrix->matrix[i][j] < min)
        {
            min = matrix->matrix[i][j];
        }
    return min;
}

int add_column(matrix_t *matrix, int n)
{
    void *ptmp;
    for (int i = 0; i < matrix->rows; i++)
    {
        ptmp = realloc(matrix->matrix[i], (n) * sizeof(int));
        if (ptmp)
            matrix->matrix[i] = ptmp;
        else
        {
            free_matrix(matrix->matrix, matrix->rows);
            return ERROR_MEMORY;
        }
    }
    for (int j = matrix->columns; j < n; j++)
        for (int i = 0; i < matrix->rows; i++)
            matrix->matrix[i][j] = new_column_elem(matrix, i);
    matrix->columns = n;
    return OK;
}

int add_row(matrix_t *matrix, int n)
{
    void *ptmp = realloc(matrix->matrix, n * sizeof(int*));
    if (ptmp)
        matrix->matrix = ptmp;
    else
    {
        free_matrix(matrix->matrix, matrix->rows);
        return ERROR_MEMORY;
    }
    
    for (int i = matrix->rows; i < n; i++)
    {
        matrix->matrix[i] = malloc(matrix->columns * sizeof(int));

        if (!matrix->matrix[i])
        {
            free_matrix(matrix->matrix, matrix->rows);
            return ERROR_MEMORY;
        }
        int buf;
        for (int j = 0; j < matrix->columns; j++)
        {
            buf = new_row_elem(matrix, j);
            memcpy(matrix->matrix[i] + j, &buf, sizeof(int));
        }
    }

    matrix->rows = n;
    return OK;
}

int add_line(matrix_t *matrix, int n)
{
    int error_code = OK;

    error_code = add_row(matrix, n);
    if (error_code)
        return error_code;

    error_code = add_column(matrix, n);
    if (error_code)
        return error_code;
    
    return error_code;
}