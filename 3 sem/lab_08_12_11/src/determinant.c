#include "determinant.h"
#include <string.h>
#include <math.h>

double det(matrix_t *mat, int i_cur)
{
    int error_code;
    double a = 0;
    int k = 0, new_i = 0, new_j;

    matrix_t new_mat;
    new_mat.rows = mat->rows - 1;
    new_mat.columns = mat->columns - 1;

    error_code = create_matrix(&new_mat);
    if (error_code)
    {
        free_matrix(mat->matrix, mat->rows);
        return ERROR_MEMORY;
    }

    for (int i = 0; i < mat->rows; i++)
    {
        new_j = 0;
        for (int j = 0; j < mat->columns; j++)
            if (!((i == k) || (j == i_cur)))
            {
                memcpy(new_mat.matrix[new_i] + new_j, mat->matrix[i] + j, sizeof(double));
                new_j++;
            }
        if (i != k)
            new_i++;
    }

    if (new_mat.rows == 2 && new_mat.columns == 2)
    {
        a = *(new_mat.matrix[0] + 0) * *(new_mat.matrix[1] + 1) - *(new_mat.matrix[1] + 0) * *(new_mat.matrix[0] + 1);
        free_matrix(new_mat.matrix, new_mat.rows);
        return a;
    }

    for (int i = 0; i < new_mat.rows; i++)
        a += new_mat.matrix[k][i] * pow(-1.0, (k + i + 2.0)) * det(&new_mat, i);

    free_matrix(new_mat.matrix, new_mat.rows);
    return a;
}

int determinant(char *file_1, char *res)
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
    
    if (matrix_1.rows != matrix_1.columns)
    {
        free_matrix(matrix_1.matrix, matrix_1.rows);
        return ERROR_SIZE;
    }

    FILE *f_out;

    f_out = fopen(res, "w");

    if (f_out == NULL)
    {
        free_matrix(matrix_1.matrix, matrix_1.rows);
        return ERROR_OPEN_FILE;
    }

    double a = 0;
    if (matrix_1.rows == 1 && matrix_1.columns == 1)
    {
        a = matrix_1.matrix[0][0];
        free_matrix(matrix_1.matrix, matrix_1.columns);
        fprintf(f_out, "%.6lf", a);
        fclose(f_out);
        return OK;
    }
    if (matrix_1.rows == 2 && matrix_1.columns == 2)
    {
        a = *(matrix_1.matrix[0] + 0) * *(matrix_1.matrix[1] + 1) - *(matrix_1.matrix[1] + 0) * *(matrix_1.matrix[0] + 1);
        free_matrix(matrix_1.matrix, matrix_1.columns);
        fprintf(f_out, "%.6lf", a);
        fclose(f_out);
        return OK;
    }

    for (int i = 0; i < matrix_1.rows; i++)
        a += matrix_1.matrix[0][i] * pow(-1.0, (i + 2.0)) * det(&matrix_1, i);

    fprintf(f_out, "%.6lf", a);
    free_matrix(matrix_1.matrix, matrix_1.rows);
    fclose(f_out);

    return OK;
}