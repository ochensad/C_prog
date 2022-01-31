#include "check_pop.h"

int check_pop(node_t **head_1, node_t *head_2)
{
    pop_front(head_1);
    pop_back(head_1);
    if (comp_lists(*head_1, head_2) == FAIL)
        return FAIL;
    return OK;
}


//Pos tests
START_TEST(norm_pop)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {1, 1, 3, 4, 4, 4, 8, 9, 9};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 9;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {1, 3, 4, 4, 4, 8, 9};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 7;
    head_out = get_list(&a_out_s);

    error_code = check_pop(&head_in, head_out);
    free_list(head_in);
    free_list(head_out);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(pop_two_el)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {1, 1};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 2;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;

    error_code = check_pop(&head_in, head_out);
    free_list(head_in);
    free_list(head_out);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(pop_one_el)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {1, 1, 3, 4, 4, 4, 8, 9, 9};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 9;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {1, 3, 4, 4, 4, 8, 9};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 7;
    head_out = get_list(&a_out_s);

    error_code = check_pop(&head_in, head_out);
    free_list(head_in);
    free_list(head_out);
    ck_assert_int_eq(error_code, OK);
}

Suite *pop_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, norm_pop);
    tcase_add_test(tc_pos, pop_two_el);
    tcase_add_test(tc_pos, pop_one_el);

    suite_add_tcase(s, tc_pos);

    return s;
}
