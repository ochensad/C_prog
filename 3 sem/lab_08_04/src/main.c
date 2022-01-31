#include "matrix.h"
#include "delite.h"
#include "add.h"
#include "multiplication.h"

int main(void)
{
    int error_code;

    matrix_t matrix_a;
    error_code = read_matrix(&matrix_a);

    if (error_code)
        return error_code;
    
    error_code = delite_line(&matrix_a);

    if (error_code)
    {
        free_matrix(matrix_a.matrix, matrix_a.rows);
        return error_code;
    }

    matrix_t matrix_b;
    error_code = read_matrix(&matrix_b);

    if (error_code)
    {
        free_matrix(matrix_a.matrix, matrix_a.rows);
        return error_code;
    }
    error_code = delite_line(&matrix_b);

    if (error_code)
    {
        free_matrix(matrix_a.matrix, matrix_a.rows);
        free_matrix(matrix_b.matrix, matrix_b.rows);
        return error_code;
    }

    if (matrix_a.rows > matrix_b.rows)
        error_code = add_line(&matrix_b, matrix_a.rows);
    else if (matrix_a.rows < matrix_b.rows)
        error_code = add_line(&matrix_a, matrix_b.rows);

    if (error_code)
    {
        free_matrix(matrix_a.matrix, matrix_a.rows);
        free_matrix(matrix_b.matrix, matrix_b.rows);
        return error_code;
    }
    
    matrix_t res_mat;
    res_mat.rows = matrix_a.rows;
    res_mat.columns = matrix_a.columns;

    error_code = create_matrix(&res_mat);
    if (error_code)
    {
        free_matrix(matrix_a.matrix, matrix_a.rows);
        free_matrix(matrix_b.matrix, matrix_b.rows);
        return error_code;
    }

    error_code = multiplication(&matrix_a, &matrix_b, &res_mat);

    if (error_code)
    {
        free_matrix(matrix_a.matrix, matrix_a.rows);
        free_matrix(matrix_b.matrix, matrix_b.rows);
        free_matrix(res_mat.matrix, res_mat.rows);
        return error_code;
    }

    print_matrix(&res_mat);

    free_matrix(matrix_a.matrix, matrix_a.rows);
    free_matrix(matrix_b.matrix, matrix_b.rows);
    free_matrix(res_mat.matrix, res_mat.rows);
    return OK;
}