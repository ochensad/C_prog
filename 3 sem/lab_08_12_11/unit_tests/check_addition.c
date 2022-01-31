#include "check_addition.h"


int check_addit(matrix_t *mat_1_in, matrix_t *mat_2_in, matrix_t *res_in_mat, matrix_t *res_out_mat)
{
    addition_matrix(res_in_mat, mat_1_in, mat_2_in);
    if (comp_matrix(res_in_mat, res_out_mat) == FAIL)
        return FAIL;
    return OK;
}

//Pos tests

START_TEST(normal_addition)
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

    matrix_t res_check;
    res_check.rows = mat_1.rows;
    res_check.columns = mat_2.columns;
    create_matrix(&res_check);
    int a_res[9] = {3, 3, 3, 3, 3, 3, 3, 3, 3};
    write_mat(&res_check, a_res);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_2.columns;
    create_matrix(&res);

    int error_code;
    error_code = check_addit(&mat_1, &mat_2, &res, &res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(one_el_addition)
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
    int a_res[1] = {3};
    write_mat(&res_check, a_res);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_2.columns;
    create_matrix(&res);

    int error_code;
    error_code = check_addit(&mat_1, &mat_2, &res, &res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    free_matrix(res_check.matrix, res_check.rows);
    ck_assert_int_eq(error_code, OK);
}

Suite *addit_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, normal_addition);
    tcase_add_test(tc_pos, one_el_addition);

    suite_add_tcase(s, tc_pos);

    return s;
}