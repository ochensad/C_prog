#include "check_add.h"

int comp_matrix(matrix_t *mat_1, matrix_t *mat_2)
{
    if (mat_1->rows != mat_2->rows || mat_1->columns != mat_2->columns)
        return FAIL;

    for (int i = 0; i < mat_1->rows; i++)
        for (int j = 0; j < mat_1->columns; j++)
            if (mat_1->matrix[i][j] != mat_2->matrix[i][j])
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

int check_add(matrix_t *mat_1, matrix_t *mat_2, matrix_t *res)
{
    if (mat_1->rows > mat_2->rows)
    {
        add_line(mat_2, mat_1->rows);
        if (comp_matrix(mat_2, res) == FAIL)
            return FAIL;
    }
    else if (mat_1->rows < mat_2->rows)
    {
        add_line(mat_1, mat_2->rows);
        if (comp_matrix(mat_1, res) == FAIL)
            return FAIL;
    }
    return OK;
}
//Pos tests

START_TEST(no_add)
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
    res.columns = mat_2.columns;
    create_matrix(&res);
    int a_res[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    write_mat(&res, a_res);

    int error_code = check_add(&mat_1, &mat_2, &res);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(first_mat_add)
{
    matrix_t mat_1;
    mat_1.rows = 2;
    mat_1.columns = 2;
    create_matrix(&mat_1);
    int a_1[4] = {1, 3, 4, 2};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 3;
    mat_2.columns = 3;
    create_matrix(&mat_2);
    int a_2[9] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    write_mat(&mat_2, a_2);

    matrix_t res;
    res.rows = mat_2.rows;
    res.columns = mat_2.columns;
    create_matrix(&res);
    int a_res[9] = {1, 3, 1, 4, 2, 2, 2, 2, 2};
    write_mat(&res, a_res);

    int error_code = check_add(&mat_1, &mat_2, &res);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(second_mat_add)
{
    matrix_t mat_1;
    mat_1.rows = 4;
    mat_1.columns = 4;
    create_matrix(&mat_1);
    int a_1[16] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
    write_mat(&mat_1, a_1);

    matrix_t mat_2;
    mat_2.rows = 2;
    mat_2.columns = 2;
    create_matrix(&mat_2);
    int a_2[9] = {1, 1, 3, 5};
    write_mat(&mat_2, a_2);

    matrix_t res;
    res.rows = mat_1.rows;
    res.columns = mat_1.columns;
    create_matrix(&res);
    int a_res[16] = {1, 1, 1, 1, 3, 5, 3, 3, 2, 3, 2, 2, 2, 3, 2, 2};
    write_mat(&res, a_res);

    int error_code = check_add(&mat_1, &mat_2, &res);

    free_matrix(mat_1.matrix, mat_1.rows);
    free_matrix(mat_2.matrix, mat_2.rows);
    free_matrix(res.matrix, res.rows);
    ck_assert_int_eq(error_code, OK);
}

Suite *add_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, no_add);
    tcase_add_test(tc_pos, first_mat_add);
    tcase_add_test(tc_pos, second_mat_add);

    suite_add_tcase(s, tc_pos);

    return s;
}