#include "check_remove.h"

int comp_lists(node_t *head_1, node_t *head_2)
{
    node_t *cur_1 = head_1;
    node_t *cur_2 = head_2;

    for (; cur_1 && cur_2; cur_1 = cur_1->next, cur_2 = cur_2->next)
        if (*(int*)cur_1->data != *(int*)cur_2->data)
            return FAIL;
    if (cur_1 != NULL || cur_2 != NULL)
        return FAIL;
    return OK;
}

int check_remove(node_t **head_1, node_t *head_2)
{
    remove_duplicates(head_1, comparator);
    if (comp_lists(*head_1, head_2) == FAIL)
        return FAIL;
    return OK;
}


//Pos tests
START_TEST(norm_remove)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {1, 1, 3, 4, 4, 4, 8, 9, 9};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 9;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {1, 3, 4, 8, 9};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 5;
    head_out = get_list(&a_out_s);

    error_code = check_remove(&head_in, head_out);
    free_list(head_out);
    free_list(head_in);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(all_el_same)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 9;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {1};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 1;
    head_out = get_list(&a_out_s);

    error_code = check_remove(&head_in, head_out);
    free_list(head_out);
    free_list(head_in);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(no_el_to_remove)
{
    int error_code;
    node_t *head_in = NULL;
    int a_in[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set_t a_in_s;
    a_in_s.arr = a_in;
    a_in_s.size = 9;
    head_in = get_list(&a_in_s);

    node_t *head_out = NULL;
    int a_out[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    set_t a_out_s;
    a_out_s.arr = a_out;
    a_out_s.size = 9;
    head_out = get_list(&a_out_s);

    error_code = check_remove(&head_in, head_out);
    free_list(head_out);
    free_list(head_in);
    ck_assert_int_eq(error_code, OK);
}

Suite *remove_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, norm_remove);
    tcase_add_test(tc_pos, all_el_same);
    tcase_add_test(tc_pos, no_el_to_remove);

    suite_add_tcase(s, tc_pos);

    return s;
}