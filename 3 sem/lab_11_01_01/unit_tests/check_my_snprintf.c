#include "check_my_snprintf.h"
#include <limits.h>

int check_buf(char* buf_1, int n_1, char* buf2, int n_2)
{
    if (n_1 != n_2)
        return FAIL_N;
    if (strcmp(buf_1, buf2) != 0)
        return FAIL_BUF;
    return OK;
}

//Pos tests
START_TEST(char_string_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "Hello %s %c", "world", '!');
    test_n = my_snprintf(test_buf, BUF_SIZE, "Hello %s %c", "world", '!');

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(char_test_only)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "1 2 %c %c ", '3', '4');
    test_n = my_snprintf(test_buf, BUF_SIZE, "1 2 %c %c ", '3', '4');

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(string_test_only)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "I %s in %s ", "study", "BMSTU");
    test_n = my_snprintf(test_buf, BUF_SIZE, "I %s in %s ", "study", "BMSTU");

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

//Negatives
START_TEST(char_int_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "Hi %c", 6);
    test_n = my_snprintf(test_buf, BUF_SIZE, "Hi %c", 6);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(string_int_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "Hi %c", 6);
    test_n = my_snprintf(test_buf, BUF_SIZE, "Hi %c", 6);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

Suite *char_test_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, char_string_test);
    tcase_add_test(tc_pos, char_test_only);
    tcase_add_test(tc_pos, string_test_only);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, char_int_test);
    tcase_add_test(tc_neg, string_int_test);

    suite_add_tcase(s, tc_neg);

    return s;
}


//Pos tests
START_TEST(ox_unsign_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "8 - %o", 256);
    test_n = my_snprintf(test_buf, BUF_SIZE, "8 - %o", 256);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(hex_unsign_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "hex - %x, %x ", 15, 2894);
    test_n = my_snprintf(test_buf, BUF_SIZE, "hex - %x, %x ", 15, 2894);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

//Neg tests
START_TEST(hex_int_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "hex - %x, %x ", -15, 2894);
    test_n = my_snprintf(test_buf, BUF_SIZE, "hex - %x, %x ", -15, 2894);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(ox_int_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "8 - %o ", -286);
    test_n = my_snprintf(test_buf, BUF_SIZE, "8 - %o ", -286);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}


Suite *num_test_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, ox_unsign_test);
    tcase_add_test(tc_pos, hex_unsign_test);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, hex_int_test);
    tcase_add_test(tc_neg, ox_int_test);

    suite_add_tcase(s, tc_neg);

    return s;
}

//Pos tests
START_TEST(d_int_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "This is %d-th lab", -11);
    test_n = my_snprintf(test_buf, BUF_SIZE, "This is %d-th lab", -11);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(i_int_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "This is %i-th lab", 11);
    test_n = my_snprintf(test_buf, BUF_SIZE, "This is %i-th lab", 11);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

//Neg test
START_TEST(d_float_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "This is %d-th lab", 11);
    test_n = my_snprintf(test_buf, BUF_SIZE, "This is %d-th lab", 11.0);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, FAIL_N);
}

START_TEST(i_float_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "This is %i-th lab", -11);
    test_n = my_snprintf(test_buf, BUF_SIZE, "This is %i-th lab", -11.0);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, FAIL_N);
}

START_TEST(d_long_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    long int arg = 16274764;
    n = snprintf(buf, BUF_SIZE, "This is %ld-th lab", arg);
    test_n = my_snprintf(test_buf, BUF_SIZE, "This is %ld-th lab", arg);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, OK);
}

START_TEST(i_long_test)
{
    int error_code;
    
    char buf[BUF_SIZE];
    char test_buf[BUF_SIZE];
    int n;
    int test_n;

    n = snprintf(buf, BUF_SIZE, "This is %i-th lab", -11);
    test_n = my_snprintf(test_buf, BUF_SIZE, "This is %i-th lab", -11.0);

    error_code = check_buf(buf, n, test_buf, test_n);
    ck_assert_int_eq(error_code, FAIL_N);
}

Suite *int_test_suite(Suite *s)
{
    TCase *tc_pos, *tc_neg;

    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, d_int_test);
    tcase_add_test(tc_pos, i_int_test);
    tcase_add_test(tc_pos, i_long_test);
    tcase_add_test(tc_pos, d_long_test);

    suite_add_tcase(s, tc_pos);

    tc_neg = tcase_create("negatives");

    tcase_add_test(tc_neg, d_float_test);
    tcase_add_test(tc_neg, i_float_test);

    suite_add_tcase(s, tc_neg);
    return s;
}

