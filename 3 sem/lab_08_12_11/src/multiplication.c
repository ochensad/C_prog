#include "multiplication.h"

void multiplication_matrix(matrix_t *res_matrix, matrix_t *matrix, matrix_t *matrix_2)
{
    for (int i = 0; i < res_matrix->rows; i++)
        for (int j = 0; j < res_matrix->columns; j++)
        {
            res_matrix->matrix[i][j] = 0;
            for (int k = 0; k < matrix_2->rows; k++)
                res_matrix->matrix[i][j] += (matrix->matrix[i][k] * matrix_2->matrix[k][j]);
        }
}

int multiplication(char *file_1, char *file_2, char *res)
{
    int error_code = OK;

    FILE *f_1;

    f_1 = fopen(file_1, "r");

    if (f_1 == NULL)
        return ERROR_OPEN_FILE;
    
    matrix_t matrix_1;

    error_code = read_matrix(f_1, &matrix_1);

    fclose(f_1);
    if (error_code)
        return error_code;
    

    FILE *f_2;

    f_2 = fopen(file_2, "r");

    if (f_2 == NULL)
    {
        free_matrix(matrix_1.matrix, matrix_1.rows);
        return ERROR_OPEN_FILE;
    }

    matrix_t matrix_2;

    error_code = read_matrix(f_2, &matrix_2);
    
    fclose(f_2);
    if (error_code)
    {
        free_matrix(matrix_1.matrix, matrix_1.rows);
        return error_code;
    }

    if (matrix_1.columns != matrix_2.rows)
    {
        free_matrix(matrix_1.matrix, matrix_1.rows);
        free_matrix(matrix_2.matrix, matrix_2.rows);
        return ERROR_SIZE;
    }

    matrix_t res_matrix;

    res_matrix.rows = matrix_1.rows;
    res_matrix.columns = matrix_2.columns;

    error_code = create_matrix(&res_matrix);

    if (error_code)
    {
        free_matrix(matrix_1.matrix, matrix_1.rows);
        free_matrix(matrix_2.matrix, matrix_2.rows);
        return error_code;
    }

    multiplication_matrix(&res_matrix, &matrix_1, &matrix_2);

    FILE *f_out;

    f_out = fopen(res, "w");

    if (f_out == NULL)
    {
        free_matrix(matrix_1.matrix, matrix_1.rows);
        free_matrix(matrix_2.matrix, matrix_2.rows);
        free_matrix(res_matrix.matrix, res_matrix.rows);
        return ERROR_OPEN_FILE;
    }

    print_matrix(f_out, &res_matrix);

    free_matrix(matrix_1.matrix, matrix_1.rows);
    free_matrix(matrix_2.matrix, matrix_2.rows);
    free_matrix(res_matrix.matrix, res_matrix.rows);
    fclose(f_out);
    return OK;
}