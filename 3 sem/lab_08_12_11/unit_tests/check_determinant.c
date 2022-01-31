#include "check_determinant.h"


int check_det(matrix_t *mat_1, int a_res, int a_res_check)
{
    if (mat_1->rows == 2 && mat_1->columns == 2)
    {
        a_res = *(mat_1->matrix[0] + 0) * *(mat_1->matrix[1] + 1) - *(mat_1->matrix[1] + 0) * *(mat_1->matrix[0] + 1);
        if (a_res != a_res_check)
            return FAIL;
        return OK;
    }

    for (int i = 0; i < mat_1->rows; i++)
        a_res += mat_1->matrix[0][i] * pow(-1.0, (i + 2.0)) * det(mat_1, i);
    if (a_res != a_res_check)
        return FAIL;
    return OK;
}

//Pos tests

START_TEST(normal_det_3)
{
    matrix_t mat_1;
    mat_1.rows = 3;
    mat_1.columns = 3;
    create_matrix(&mat_1);
    int a_1[9] = {2, 2, 2, 2, 2, 2, 2, 2, 2};
    write_mat(&mat_1, a_1);

    int a_res = 0;
    int a_res_check = 0;

    int error_code;
    error_code = check_det(&mat_1, a_res, a_res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(normal_det_2)
{
    matrix_t mat_1;
    mat_1.rows = 2;
    mat_1.columns = 2;
    create_matrix(&mat_1);
    int a_1[4] = {1, 2, 3, 4};
    write_mat(&mat_1, a_1);

    int a_res = 0;
    int a_res_check = -2;

    int error_code;
    error_code = check_det(&mat_1, a_res, a_res_check);

    free_matrix(mat_1.matrix, mat_1.rows);
    ck_assert_int_eq(error_code, OK);
}

Suite *det_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, normal_det_3);
    tcase_add_test(tc_pos, normal_det_2);

    suite_add_tcase(s, tc_pos);

    return s;
}