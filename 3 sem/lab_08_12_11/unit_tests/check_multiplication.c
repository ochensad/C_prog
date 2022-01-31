#include "check_multiplication.h"
#include <math.h>
int comp_matrix(matrix_t *mat_1, matrix_t *mat_2)
{
    if (mat_1->rows != mat_2->rows || mat_1->columns != mat_2->columns)
        return FAIL;

    for (int i = 0; i < mat_1->rows; i++)
        for (int j = 0; j < mat_1->columns; j++)
            if (fabs(mat_1->matrix[i][j] - mat_2->matrix[i][j]) > EPS)
                return FAIL;

    return OK;
}

void write_mat(matrix_t *mat, int a[])
{
    int l = 0;
    for (int i = 0; i < mat->rows; i++)
        for (int j = 0; j < mat->columns; j++)
        {
            mat->matrix[i][j] = a[l];
            l++;
        }
}

int check_mult(matrix_t *mat_1_in, matrix_t *mat_2_in, matrix_t *res_in_mat, matrix_t *res_out_mat)
{
    multiplication_matrix(res_in_mat, mat_1_in, mat_2_in);
    if (comp_matrix(res_in_mat, res_out_mat) == FAIL)
        return FAIL;
    return OK;
}

START_TEST(normal_sqare_mult)
{
    matrix_t mat_1;
    mat_1.rows = 3;
    mat_1.columns = 3;
    create_matrix(&mat_1);
    int a_1[9] = {1, 2, 3, 4, 5 ,6 ,7 ,8 , 9};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 3;
    mat_2.columns = 3;
    create_matrix(&mat_2);
    int a_2[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    write_mat(&mat_2, a_2);

    matrix_t res_check;
    res_check.rows = 3;
    res_check.columns = 3;
    create_matrix(&res_check);
    int a_res[9] = {30, 24, 18, 84, 69, 54, 138, 114, 90};
    write_mat(&res_check, a_res);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_2.columns;
    create_matrix(&res);

    int error_code;
    error_code = check_mult(&mat_1, &mat_2, &res, &res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}
END_TEST

START_TEST(normal_mult)
{
    matrix_t mat_1;
    mat_1.rows = 4;
    mat_1.columns = 3;
    create_matrix(&mat_1);
    int a_1[12] = {1, 2, 3, 4, 5 ,6 ,7 ,8 , 9, 1, 2, 2};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 3;
    mat_2.columns = 5;
    create_matrix(&mat_2);
    int a_2[15] = {3, 3, 3, 0, 0, 0, 2, 4, 6, 4, 1, 2, 0, 5, 6};
    write_mat(&mat_2, a_2);

    matrix_t res_check;
    res_check.rows = mat_1.rows;
    res_check.columns = mat_2.columns;
    create_matrix(&res_check);
    int a_res[20] = {6, 13, 11, 27, 26, 18, 34, 32, 60, 56, 30, 55, 53, 93, 86, 5, 11, 11, 22, 20};
    write_mat(&res_check, a_res);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_2.columns;
    create_matrix(&res);

    int error_code;
    error_code = check_mult(&mat_1, &mat_2, &res, &res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}
END_TEST

START_TEST(one_el_matrix)
{
    matrix_t mat_1;
    mat_1.rows = 1;
    mat_1.columns = 1;
    create_matrix(&mat_1);
    int a_1[1] = {1};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 1;
    mat_2.columns = 5;
    create_matrix(&mat_2);
    int a_2[5] = {1, 2, 3, 4, 5};
    write_mat(&mat_2, a_2);

    matrix_t res_check;
    res_check.rows = mat_1.rows;
    res_check.columns = mat_2.columns;
    create_matrix(&res_check);
    int a_res[5] = {1, 2, 3, 4, 5};
    write_mat(&res_check, a_res);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_2.columns;
    create_matrix(&res);

    int error_code;
    error_code = check_mult(&mat_1, &mat_2, &res, &res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}
END_TEST

START_TEST(one_el_two_matrix)
{
    matrix_t mat_1;
    mat_1.rows = 1;
    mat_1.columns = 1;
    create_matrix(&mat_1);
    int a_1[1] = {1};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 1;
    mat_2.columns = 1;
    create_matrix(&mat_2);
    int a_2[1] = {2};
    write_mat(&mat_2, a_2);

    matrix_t res_check;
    res_check.rows = mat_1.rows;
    res_check.columns = mat_2.columns;
    create_matrix(&res_check);
    int a_res[1] = {2};
    write_mat(&res_check, a_res);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_2.columns;
    create_matrix(&res);

    int error_code;
    error_code = check_mult(&mat_1, &mat_2, &res, &res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}
END_TEST

Suite* mult_test_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, normal_sqare_mult);
    tcase_add_test(tc_pos, normal_mult);
    tcase_add_test(tc_pos, one_el_matrix);
    tcase_add_test(tc_pos, one_el_two_matrix);

    suite_add_tcase(s, tc_pos);
    return s;
}