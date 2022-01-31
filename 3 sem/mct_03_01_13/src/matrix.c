#include "matrix.h"
#include <stdio.h>
#include <string.h>

void print_matrix(matrix_t *mat)
{
    printf("\n");
    for (size_t i = 0; i < mat->row; i++)
    {
        for (size_t j = 0; j < mat->column; j++)
        printf("%d ", mat->matrix[i][j]);
        printf("\n");
    }
}

void free_matrix(int **arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

void free_array(matrix_t *mat_arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        free_matrix(mat_arr[i].matrix, mat_arr[i].row);
    }
    free(mat_arr);
}

int **allocate_matrix(size_t row, size_t column)
{
    int **arr = calloc(row, sizeof(int*));
    if (arr == NULL)
        return NULL;
    
    for (size_t i = 0; i < row; i++)
    {
        arr[i] = malloc(column * sizeof(int));
        
        if (arr[i] == NULL)
        {
            free_matrix(arr, row);
            return NULL;
        }
    }
    return arr;
}

int read_matrix(matrix_t *mat)
{
    if (scanf("%zu", &mat->row) != 1)
        return ERROR_READING;
    if (scanf("%zu", &mat->column) != 1)
        return ERROR_READING;
    mat->matrix = allocate_matrix(mat->row, mat->column);
    
    if (mat->matrix == NULL)
        return ERROR_MEMORY;

    for (size_t i = 0; i < mat->row; i++)
        for (size_t j = 0; j < mat->column; j++)
            {
                if (scanf("%d", mat->matrix[i] + j) != 1)
                {
                    free_matrix(mat->matrix, mat->row);
                    return ERROR_READING;
                }
            }
    return OK;
}

size_t find_min(matrix_t *mat)
{
    int min = mat->matrix[0][0];
    size_t j_min = 0;
    for (size_t i = 0; i < mat->row; i++)
        for (size_t j = 0; j < mat->column; j++)
            if (mat->matrix[i][j] < min)
            {
                min = mat->matrix[i][j];
                j_min = j;
            }
    return j_min;
}

size_t find_max(matrix_t *mat)
{
    int max = mat->matrix[0][0];
    size_t j_max = 0;
    for (size_t i = 0; i < mat->row; i++)
        for (size_t j = 0; j < mat->column; j++)
            if (mat->matrix[i][j] > max)
            {
                max = mat->matrix[i][j];
                j_max = j;
            }
    return j_max;
}

void mat_copy(matrix_t *new, matrix_t *old)
{
    for (size_t i = 0; i < old->row; i++)
        memcpy(new->matrix[i], old->matrix[i], sizeof(int) * old->column);
    
    size_t j_min = find_min(old);
    size_t j_max = find_max(old);
    char buf[200];

    for (size_t i = 0; i < old->row; i++)
    {
        memcpy(buf, new->matrix[i] + j_min, sizeof(int));
        memcpy(new->matrix[i] + j_min, new->matrix[i] + j_max, sizeof(int));
        memcpy(new->matrix[i] + j_max, buf, sizeof(int));
    }
}

void print_array(matrix_t *arr, int n)
{
    for (int i = 0; i < n; i++)
        print_matrix(&arr[i]);
}