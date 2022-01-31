#include "check_multiplication.h"

int check_mult(matrix_t *mat_1, matrix_t *mat_2, matrix_t *res, matrix_t *res_check, int p, int g)
{
    matrix_t buf;
    buf.rows = res->rows;
    buf.columns = res->columns;
    create_matrix(&buf);
    
    if (p != 0)
    {
        copy_matrix(&buf, mat_1);
        p--;
    }
    else
    {
        copy_matrix(&buf, mat_2);
        g--;
    }
    for (int i = 0; i < p; i++)
    {
        multiplication_matrix(res, &buf, mat_1);
        copy_matrix(&buf, res);
    }
    for (int k = 0; k < g; k++)
    {
        multiplication_matrix(res, &buf, mat_2);
        copy_matrix(&buf, res);
    }

    free_matrix(buf.matrix, buf.rows);

    if (comp_matrix(res, res_check) == FAIL)
        return FAIL;
    return OK;
}
//Pos tests

START_TEST(two_mat_mult)
{
    matrix_t mat_1;
    mat_1.rows = 3;
    mat_1.columns = 3;
    create_matrix(&mat_1);
    int a_1[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 3;
    mat_2.columns = 3;
    create_matrix(&mat_2);
    int a_2[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    write_mat(&mat_2, a_2);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_1.columns;
    create_matrix(&res);

    matrix_t res_check;
    res_check.rows = mat_1.rows;
    res_check.columns = mat_1.columns;
    create_matrix(&res_check);
    int a_res[9] = {6, 6, 6, 6, 6, 6, 6, 6, 6};
    write_mat(&res_check, a_res);

    int p = 1, g = 1;
    int error_code = check_mult(&mat_1, &mat_2, &res, &res_check, p, g);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(four_mat_mult)
{
    matrix_t mat_1;
    mat_1.rows = 2;
    mat_1.columns = 2;
    create_matrix(&mat_1);
    int a_1[4] = {2, 3, 4, 2};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 2;
    mat_2.columns = 2;
    create_matrix(&mat_2);
    int a_2[4] = {2, 6, 2, 1};
    write_mat(&mat_2, a_2);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_1.columns;
    create_matrix(&res);

    matrix_t res_check;
    res_check.rows = mat_1.rows;
    res_check.columns = mat_1.columns;
    create_matrix(&res_check);
    int a_res[4] = {328, 444, 352, 496};
    write_mat(&res_check, a_res);

    int p = 2, g = 2;
    int error_code = check_mult(&mat_1, &mat_2, &res, &res_check, p, g);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(dif_mat_mult)
{
    matrix_t mat_1;
    mat_1.rows = 2;
    mat_1.columns = 2;
    create_matrix(&mat_1);
    int a_1[4] = {2, 3, 1, 5};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 2;
    mat_2.columns = 2;
    create_matrix(&mat_2);
    int a_2[4] = {3, 1, 2, 4};
    write_mat(&mat_2, a_2);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_1.columns;
    create_matrix(&res);

    matrix_t res_check;
    res_check.rows = mat_1.rows;
    res_check.columns = mat_1.columns;
    create_matrix(&res_check);
    int a_res[4] = {63, 91, 77, 119};
    write_mat(&res_check, a_res);

    int p = 2, g = 1;
    int error_code = check_mult(&mat_1, &mat_2, &res, &res_check, p, g);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}

Suite *mult_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, two_mat_mult);
    tcase_add_test(tc_pos, four_mat_mult);
    tcase_add_test(tc_pos, dif_mat_mult);

    suite_add_tcase(s, tc_pos);

    return s;
}