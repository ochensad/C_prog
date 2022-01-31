#include "check_delite.h"

int check_del(matrix_t *mat_1, matrix_t *res)
{
    delite_line(mat_1);
    if (comp_matrix(mat_1, res) == FAIL)
        return FAIL;
    return OK;
}
//Pos tests

START_TEST(no_del)
{
    matrix_t mat_1;
    mat_1.rows = 3;
    mat_1.columns = 3;
    create_matrix(&mat_1);
    int a_1[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    write_mat(&mat_1, a_1);

    matrix_t res;
    res.rows = 3;
    res.columns = 3;
    create_matrix(&res);
    int a_res[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    write_mat(&res, a_res);

    int error_code = check_del(&mat_1, &res);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(res.matrix, res.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(del_rows)
{
    matrix_t mat_1;
    mat_1.rows = 4;
    mat_1.columns = 2;
    create_matrix(&mat_1);
    int a_1[8] = {1, 3, 4, 2, 3, 2, 8, 2};
    write_mat(&mat_1, a_1);

    matrix_t res;
    res.rows = 2;
    res.columns = mat_1.columns;
    create_matrix(&res);
    int a_res[4] = {1, 3, 3, 2};
    write_mat(&res, a_res);

    int error_code = check_del(&mat_1, &res);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(res.matrix, res.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(del_columns)
{
    matrix_t mat_1;
    mat_1.rows = 2;
    mat_1.columns = 5;
    create_matrix(&mat_1);
    int a_1[10] = {1, 3, 3, 4, 6, 3, 4, 5, 4, 2};
    write_mat(&mat_1, a_1);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = 2;
    create_matrix(&res);
    int a_res[4] = {1, 3, 3, 4};
    write_mat(&res, a_res);

    int error_code = check_del(&mat_1, &res);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(res.matrix, res.rows);
    ck_assert_int_eq(error_code, OK);
}

Suite *delite_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, no_del);
    tcase_add_test(tc_pos, del_rows);
    tcase_add_test(tc_pos, del_columns);

    suite_add_tcase(s, tc_pos);

    return s;
}