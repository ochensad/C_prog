#include "check_turn.h"

int check_stack(node_stack_t *st, int *a, int len)
{
    node_stack_t *cur;
    int i = 0;
    cur = st;
    for (; cur->next; cur = cur->next, i++)
        if (cur->data != a[i])
            return 1;
    if (i != len)
        return 2;
    return OK;
}

//Pos tests
START_TEST(only_push)
{
    int error_code;
    list_turn_t turn;
    turn = create_turn();
    size_t len = 4;
    push_turn(&turn, len, 1, 2, 3, 4);

    int a[4] = {4, 3, 2, 1};
    error_code = check_stack(turn.head->head, a, len - 1);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(push_and_pop)
{
    int error_code;
    list_turn_t turn;
    turn = create_turn();
    size_t len = 4;
    push_turn(&turn, len, 1, 2, 3, 4);
    pop_turn(&turn, len - 2);
    int a_1[2] = {2, 1};
    int a_2[2] = {3, 4};
    error_code = check_stack(turn.head->head, a_1, len - 3);
    if (error_code == 0)
        error_code = check_stack(turn.tail->head, a_2, len - 3);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(only_pop)
{
    int error_code;
    list_turn_t turn;
    turn = create_turn();
    size_t len = 4;
    push_turn(&turn, len, 1, 2, 3, 4);
    pop_turn(&turn, len);
    int a[4] = {1, 2, 3, 4};
    error_code = check_stack(turn.tail->head, a, len - 1);
    ck_assert_int_eq(error_code, OK);
}


Suite *turn_test_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, only_push);
    tcase_add_test(tc_pos, push_and_pop);
    tcase_add_test(tc_pos, only_pop);

    suite_add_tcase(s, tc_pos);

    return s;
}