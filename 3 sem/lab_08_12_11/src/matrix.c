#include "matrix.h"
#include <stdlib.h>
void free_matrix(double **arr, int n)
{
    for (int i = 0; i < n; i++)
        free(arr[i]);

    free(arr);
}

double **allocate_matrix(int row, int colunm)
{
    double **arr = calloc(row, sizeof(double*));
    if (!arr)
        return NULL;
    
    for (int i = 0; i < row; i++)
    {
        arr[i] = malloc(colunm * sizeof(double));

        if (!arr[i])
        {
            free_matrix(arr, row);
            return NULL;
        }
    }
    return arr;
}

int create_matrix(matrix_t *matrix)
{
    matrix->matrix = allocate_matrix(matrix->rows, matrix->columns);

    if (matrix->matrix == NULL)
        return ERROR_MEMORY;

    return OK;
}

int read_matrix(FILE *f, matrix_t *matrix)
{
    int error_code = OK;

    error_code = fscanf(f, "%d", &matrix->rows);
    if (error_code != 1)
        return ERROR_READING;
    
    error_code = fscanf(f, "%d", &matrix->columns);
    if (error_code != 1)
        return ERROR_READING;
    if (matrix->rows <= 0 || matrix->columns <= 0)
        return ERROR_SIZE;
    
    error_code = create_matrix(matrix);

    if (error_code)
        return error_code;
    
    for (int i = 0; i < matrix->rows; i++)
        for (int j = 0; j < matrix->columns; j++)
        {
            error_code = fscanf(f, "%lf", matrix->matrix[i] + j);
            
            if (error_code != 1)
            {
                free_matrix(matrix->matrix, matrix->rows);
                return ERROR_READING;
            }

            if (error_code == EOF && i != matrix->rows - 1 && j != matrix->columns - 1)
            {
                free_matrix(matrix->matrix, matrix->rows);
                return ERROR_READING;
            }
        }
    return OK;
}

void print_matrix(FILE *f, matrix_t *matrix)
{
    fprintf(f, "%d %d\n", matrix->rows, matrix->columns);
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
            fprintf(f, "%.6lf ", matrix->matrix[i][j]);
        fprintf(f, "\n");
    }
}

