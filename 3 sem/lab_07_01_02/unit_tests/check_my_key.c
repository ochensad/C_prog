#include "check_my_key.h"

//Pos tests


START_TEST(normal_filter_half)
{
    int ps_src[] = {5, 3, 9, 2, 6, -8, 10, 4, 5, 25};
    size_t len_src = 10;
    int *pe_src = ps_src + len_src;

    int *ps_dst = NULL;
    int *pe_dst = NULL;

    int res[] = {5, 3, 9, 2, 6};
    size_t len_res = 5;

    key(ps_src, pe_src, &ps_dst, &pe_dst);

    size_t len_dst = pe_dst - ps_dst;

    int error_code = comp_arrays(ps_dst, len_dst, res, len_res);

    free(ps_dst);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(normal_filter_all)
{
    int ps_src[] = {5, 3, 9, 2, 6, 8, 10, 4, 5, 25};
    size_t len_src = 10;
    int *pe_src = ps_src + len_src;

    int *ps_dst = NULL;
    int *pe_dst = NULL;

    int res[] = {5, 3, 9, 2, 6, 8, 10, 4, 5, 25};
    size_t len_res = 10;

    key(ps_src, pe_src, &ps_dst, &pe_dst);

    size_t len_dst = pe_dst - ps_dst;

    int error_code = comp_arrays(ps_dst, len_dst, res, len_res);

    free(ps_dst);
    ck_assert_int_eq(error_code, OK);
}

//Neg tests

START_TEST(invalid_src_start_pointer)
{
    int arr[] = {5, 3, 9, 2, 6, -8, 10, 4, 5, 25};
    size_t len_src = 10;

    int *ps_src = NULL;
    int *pe_src = arr + len_src;

    int *ps_dst = NULL;
    int *pe_dst = NULL;

    int error_code = key(ps_src, pe_src, &ps_dst, &pe_dst);

    free(ps_dst);
    ck_assert_int_eq(error_code, ERROR_DATA);
}

START_TEST(invalid_src_end_pointer)
{
    int arr[] = {5, 3, 9, 2, 6, -8, 10, 4, 5, 25};

    int *ps_src = arr;
    int *pe_src = NULL;

    int *ps_dst = NULL;
    int *pe_dst = NULL;

    int error_code = key(ps_src, pe_src, &ps_dst, &pe_dst);

    free(ps_dst);
    ck_assert_int_eq(error_code, ERROR_DATA);
}

START_TEST(same_start_end_poinetrs)
{
    int arr[] = {5, 3, 9, 2, 6, -8, 10, 4, 5, 25};

    int *ps_src = arr;
    int *pe_src = arr;

    int *ps_dst = NULL;
    int *pe_dst = NULL;

    int error_code = key(ps_src, pe_src, &ps_dst, &pe_dst);

    free(ps_dst);
    ck_assert_int_eq(error_code, ERROR_DATA);
}

START_TEST(end_poiner_smaller)
{
    int arr[] = {5, 3, 9, 2, 6, -8, 10, 4, 5, 25};

    int *ps_src = arr;
    int *pe_src = arr - 1;

    int *ps_dst = NULL;
    int *pe_dst = NULL;

    int error_code = key(ps_src, pe_src, &ps_dst, &pe_dst);

    free(ps_dst);
    ck_assert_int_eq(error_code, ERROR_DATA);
}

START_TEST(first_neg_el)
{
    int arr[] = {-5, 3, 9, 2, 6, -8, 10, 4, 5, 25};
    size_t len_src = 10;
    int *ps_src = arr;
    int *pe_src = arr + len_src;

    int *ps_dst = NULL;
    int *pe_dst = NULL;

    int error_code = key(ps_src, pe_src, &ps_dst, &pe_dst);

    free(ps_dst);
    ck_assert_int_eq(error_code, ERROR_NO_EL_IN_ARRAY);
}

Suite *key_test_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, normal_filter_half);
    tcase_add_test(tc_pos, normal_filter_all);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, invalid_src_start_pointer);
    tcase_add_test(tc_neg, invalid_src_end_pointer);
    tcase_add_test(tc_neg, same_start_end_poinetrs);
    tcase_add_test(tc_neg, end_poiner_smaller);
    tcase_add_test(tc_neg, first_neg_el);

    suite_add_tcase(s, tc_neg);
    return s;
}