#include "check_simple_arr.h"

int comp_arr(num_t *a, num_t *b)
{
    if (a->size != b->size)
        return FAIL;
    for (size_t i = 0; i < a->size; i++)
        if (a->arr[i] != b->arr[i])
            return FAIL;
    return OK;
}

int check_simple_arr(num_t *a, num_t *b, int n)
{
    get_simple_num_arr(a, n);
    if (comp_arr(a, b) == FAIL)
        return FAIL;
    return OK;
}


//Pos tests
START_TEST(simple_num)
{
    int error_code;
    
    int n = 57;

    num_t a_in;

    num_t a_out;
    int a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    a_out.arr = a;
    a_out.size = 16;
    error_code = check_simple_arr(&a_in, &a_out, n);
    free(a_in.arr);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(comp_num)
{
    int error_code;
    
    int n = 16;

    num_t a_in;

    num_t a_out;
    int a[] = {2, 3, 5, 7, 11, 13};
    a_out.arr = a;
    a_out.size = 6;
    error_code = check_simple_arr(&a_in, &a_out, n);
    free(a_in.arr);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(lit_num)
{
    int error_code;
    
    int n = 2;

    num_t a_in;

    num_t a_out;
    int a[] = {2};
    a_out.arr = a;
    a_out.size = 1;
    error_code = check_simple_arr(&a_in, &a_out, n);
    free(a_in.arr);
    ck_assert_int_eq(error_code, OK);
}


Suite *simple_arr_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, simple_num);
    tcase_add_test(tc_pos, comp_num);
    tcase_add_test(tc_pos, lit_num);

    suite_add_tcase(s, tc_pos);

    return s;
}