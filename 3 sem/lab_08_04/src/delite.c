#include "delite.h"
#include "matrix.h"
#include <string.h>
void find_last_max(matrix_t *matrix, int *i_m, int *j_m)
{
    int max = matrix->matrix[0][0];

    for (int j = 0; j < matrix->columns; j++)
        for (int i = 0; i < matrix->rows; i++)
            if (matrix->matrix[i][j] >= max)
            {
                max = matrix->matrix[i][j];
                *i_m = i;
                *j_m = j;
            }
}

int delite_column(matrix_t *matrix, int del_j)
{
    void *ptmp;
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = del_j; j < matrix->columns - 1; j++)
            memcpy(matrix->matrix[i] + j, matrix->matrix[i] + j + 1, sizeof(int));
        ptmp = realloc(matrix->matrix[i], (matrix->columns - 1) * sizeof(int));
        if (ptmp)
            matrix->matrix[i] = ptmp;
        else
            return ERROR_MEMORY;
    }
    return OK;
}

void delite_row(matrix_t *matrix, int del_i)
{
    for (int i = del_i; i < matrix->rows - 1; i++)
        memcpy(matrix->matrix[i], matrix->matrix[i + 1], sizeof(int) * matrix->columns);
    free(matrix->matrix[matrix->rows - 1]);
}

int delite_line(matrix_t *matrix)
{
    int er_code;
    int del_flag = 0;

    if (matrix->rows < matrix->columns)
        del_flag = 1;
    else if (matrix->rows > matrix->columns)
        del_flag = 0;
    else
        return OK;
    int del_i;
    int del_j;

    if (del_flag)
    {
        while (matrix->rows < matrix->columns)
        {
            find_last_max(matrix, &del_i, &del_j);
            er_code = delite_column(matrix, del_j);
            if (er_code)
            {
                free_matrix(matrix->matrix, matrix->rows);
                return er_code;
            }
            (matrix->columns)--;
        }
    }
    else if (del_flag == 0)
    {
        while (matrix->rows > matrix->columns)
        {
            find_last_max(matrix, &del_i, &del_j);
            delite_row(matrix, del_i);
            (matrix->rows)--;
        }
    }
    return OK;
}