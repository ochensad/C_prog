#include "multiplication.h"
#include <string.h>
void multiplication_matrix(matrix_t *res_matrix, matrix_t *matrix, matrix_t *matrix_2)
{
    int buf;
    for (int i = 0; i < res_matrix->rows; i++)
        for (int j = 0; j < res_matrix->columns; j++)
        {
            buf = 0;
            for (int k = 0; k < matrix_2->rows; k++)
                buf += (matrix->matrix[i][k] * matrix_2->matrix[k][j]);
            res_matrix->matrix[i][j] = buf;
        }
}

void copy_matrix(matrix_t *a_dst, matrix_t *b_src)
{
    for (int i = 0; i < a_dst->rows; i++)
        for (int j = 0; j < a_dst->columns; j++)
            memcpy(a_dst->matrix[i] + j, b_src->matrix[i] + j, sizeof(int));
}

int power_matrix(matrix_t *mat, int p)
{
    matrix_t buf_1;
    buf_1.rows = mat->rows;
    buf_1.columns = mat->columns;
    int error_code = create_matrix(&buf_1);
    if (error_code)
        return ERROR_BUF;

    matrix_t buf_2;
    buf_2.rows = mat->rows;
    buf_2.columns = mat->columns;
    error_code = create_matrix(&buf_2);
    if (error_code)
    {
        free_matrix(buf_1.matrix, buf_1.rows);
        return ERROR_BUF;
    }

    copy_matrix(&buf_1, mat);
    p--;
    for (int i = 0; i < p; i++)
    {
        multiplication_matrix(&buf_2, &buf_1, mat);
        copy_matrix(&buf_1, &buf_2);
    }
    if (p != 0)
        copy_matrix(mat, &buf_2);
    free_matrix(buf_1.matrix, buf_1.rows);
    free_matrix(buf_2.matrix, buf_2.rows);
    return OK;
}

void get_identity_mat(matrix_t *mat)
{
    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->columns; j++)
        {
            if (i == j)
                mat->matrix[i][j] = 1;
            else
                mat->matrix[i][j] = 0;
        }
}

int multiplication(matrix_t *a, matrix_t *b, matrix_t *res)
{
    int p, g;

    if (scanf("%d", &p) != 1)
        return ERROR_READING;
    
    if (scanf("%d", &g) != 1)
        return ERROR_READING;
    
    if (p < 0 || g < 0)
        return ERROR_READING;
    
    if (p == 0 && g == 0)
    {
        get_identity_mat(res);
        return OK;
    }
    int error_code;

    if (p == 0)
        get_identity_mat(a);
    if (g == 0)
        get_identity_mat(b);
    
    if (p != 0)
    {
        error_code = power_matrix(a, p);
        if (error_code)
            return error_code;
    }
    if (g != 0)
    {
        error_code = power_matrix(b, g);
        if (error_code)
            return error_code;
    }

    multiplication_matrix(res, a, b);
    
    return OK;
}