#include "check_all_el.h"

int check_all_arr(num_t *a, num_t *b, int n)
{
    get_num_arr(n, a);
    if (comp_arr(a, b) == FAIL)
        return FAIL;
    return OK;
}


//Pos tests
START_TEST(simple_num_el)
{
    int error_code;
    
    int n = 37;

    num_t a_in;

    num_t a_out;
    int a[] = {37};
    a_out.arr = a;
    a_out.size = 1;
    error_code = check_all_arr(&a_in, &a_out, n);
    free(a_in.arr);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(comp_num_el)
{
    int error_code;
    
    int n = 24;

    num_t a_in;

    num_t a_out;
    int a[] = {2, 2, 2, 3};
    a_out.arr = a;
    a_out.size = 4;
    error_code = check_all_arr(&a_in, &a_out, n);
    free(a_in.arr);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(lit_num_el)
{
    int error_code;
    
    int n = 121;

    num_t a_in;

    num_t a_out;
    int a[] = {11, 11};
    a_out.arr = a;
    a_out.size = 2;
    error_code = check_all_arr(&a_in, &a_out, n);
    free(a_in.arr);
    ck_assert_int_eq(error_code, OK);
}


Suite *all_arr_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, simple_num_el);
    tcase_add_test(tc_pos, comp_num_el);
    tcase_add_test(tc_pos, lit_num_el);

    suite_add_tcase(s, tc_pos);

    return s;
}
