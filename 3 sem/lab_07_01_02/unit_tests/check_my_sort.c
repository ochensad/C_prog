#include "check_my_sort.h"

int comp_arrays(int *array_one, int len_one, int *array_two, int len_two)
{
    if (len_one != len_two)
    {
        return FAIL;
    }

    for (int i = 0; i < len_one; i++)
    {
        if (array_one[i] != array_two[i])
        { 
            return FAIL;
        }
    }

    return OK;
}

void check_sort(int *arr_1, size_t len_1, int *arr_2, size_t len_2)
{
    mysort(arr_1, len_1, sizeof(int), greater);

    int error_code = comp_arrays(arr_1, len_1, arr_2, len_2);

    ck_assert_int_eq(error_code, OK);
}

START_TEST(normal_sort)
{
    int array_in[] = {0, 8, 3, -4, 2, -20, 34, 8, 1};
    int array_out[] = {-20, -4, 0, 1, 2, 3, 8, 8, 34};
    size_t len = 9;

    check_sort(array_in, len, array_out, len);
}
END_TEST

START_TEST(sorted_array)
{
    int array_in[] = {-90, -30, -5, 0, 1, 5, 24, 70};
    int array_out[] = {-90, -30, -5, 0, 1, 5, 24, 70};
    size_t len = 8;

    check_sort(array_in, len, array_out, len);
}
END_TEST

START_TEST(reversed_sort)
{
    int array_in[] = {34, 20, 12, 12, 8, 7, 1, -6};
    int array_out[] = {-6, 1, 7, 8, 12, 12, 20, 34};
    size_t len = 8;

    check_sort(array_in, len, array_out, len);
}
END_TEST

START_TEST(one_el_sort)
{
    int array_in[] = {100};
    int array_out[] = {100};
    size_t len = 1;

    check_sort(array_in, len, array_out, len);
}
END_TEST

Suite* sort_test_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, normal_sort);
    tcase_add_test(tc_pos, sorted_array);
    tcase_add_test(tc_pos, one_el_sort);
    tcase_add_test(tc_pos, reversed_sort);

    suite_add_tcase(s, tc_pos);
    return s;
}