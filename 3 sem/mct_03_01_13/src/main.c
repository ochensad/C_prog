#include "matrix.h"
#include <stdio.h>

int main(void)
{
    int error_code;
    int arr_len;

    if (scanf("%d", &arr_len) != 1)
        return ERROR_READING;
    if (arr_len <= 0)
        return ERROR_SIZE;
    arr_len *= 2;

    matrix_t *mat_arr = malloc(arr_len * sizeof(matrix_t));

    if (mat_arr == NULL)
        return ERROR_MEMORY;
    int i = 0;
    while (i < arr_len)
    {
        error_code = read_matrix(mat_arr + i);
        if (error_code)
        {
            free_array(mat_arr, arr_len);
            return error_code;
        }
        matrix_t new_mat;
        new_mat.row = mat_arr[i].row;
        new_mat.column = mat_arr[i].column;

        new_mat.matrix = allocate_matrix(new_mat.row, new_mat.column);
        if (new_mat.matrix == NULL)
        {
            free_array(mat_arr, arr_len);
            return ERROR_MEMORY;
        }
        mat_copy(&new_mat, mat_arr + i);
        i++;
        mat_arr[i] = new_mat;
        i++;
    }

    print_array(mat_arr, arr_len);
    free_array(mat_arr, arr_len);
    return OK;
}