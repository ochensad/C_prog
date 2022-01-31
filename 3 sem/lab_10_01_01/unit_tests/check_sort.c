#include "check_sort.h"

int check_sort(node_t **head_1, node_t *head_2)
{
    node_t *new_head = sort(*head_1, comparator);
    *head_1 = new_head;
    if (comp_lists(new_head, head_2) == FAIL)
        return FAIL;
    return OK;
}


//Pos tests
START_TEST(norm_sort)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {1, 4, 2, 8, 0, 5, 6, 7, 3, 2};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 10;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {0, 1, 2, 2, 3, 4, 5, 6, 7, 8};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 10;
    head_out = get_list(&a_out_s);

    error_code = check_sort(&head_in, head_out);

    free_list(head_in);
    free_list(head_out);

    ck_assert_int_eq(error_code, OK);
}

START_TEST(no_el_to_sort)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {0, 1, 2, 2, 3, 4, 5, 6, 7, 8};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 10;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {0, 1, 2, 2, 3, 4, 5, 6, 7, 8};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 10;
    head_out = get_list(&a_out_s);

    error_code = check_sort(&head_in, head_out);

    free_list(head_in);
    free_list(head_out);

    ck_assert_int_eq(error_code, OK);
}

START_TEST(reverse_sort)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {8, 7, 6, 5, 4, 3, 2, 2, 1, 0};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 10;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {0, 1, 2, 2, 3, 4, 5, 6, 7, 8};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 10;
    head_out = get_list(&a_out_s);

    error_code = check_sort(&head_in, head_out);

    free_list(head_in);
    free_list(head_out);

    ck_assert_int_eq(error_code, OK);
}

Suite *sort_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, norm_sort);
    tcase_add_test(tc_pos, no_el_to_sort);
    tcase_add_test(tc_pos, reverse_sort);

    suite_add_tcase(s, tc_pos);

    return s;
}