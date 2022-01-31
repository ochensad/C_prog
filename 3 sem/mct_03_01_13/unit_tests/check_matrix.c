#include "check_matrix.h"

int comp_mat(matrix_t *a, matrix_t *b)
{
    if (a->row != b->row || a->column != b->column)
        return FAIL;
    for (size_t i = 0; i < a->row; i++)
        for (size_t j = 0; j < a->column; j++)
            if (a->matrix[i][j] != b->matrix[i][j])
                return FAIL;
    return OK;
}

int check_copy(matrix_t *new, matrix_t *old, matrix_t *result)
{
    mat_copy(new, old);
    if (comp_mat(new, result) == FAIL)
        return FAIL;
    return OK;
}

START_TEST(copy_el)
{
    int error_code = OK;

    matrix_t a = {{{1, 2},{3, 4}}, 2, 2};
    matrix_t b = {{{0, 0},{0, 0}}, 2, 2};

    matrix_t r = {{{2, 1},{4, 3}}, 2, 2};
    
    error_code = check_copy(&b, &a, &r);
    ck_assert_int_eq(error_code, OK);
}
END_TEST

Suite* filt_test_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, copy_el);

    suite_add_tcase(s, tc_pos);
    return s;
}
