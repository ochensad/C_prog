#include "check_array_func.h"
#include <math.h>
#include <string.h>

int comp_array(product_t *pr_1, size_t len_1, product_t *pr_2, size_t len_2)
{
    if (len_1 != len_2)
        return FAIL;
    for (size_t i = 0; i < len_1; i++)
    {
        if (strcmp(pr_1[i].name, pr_2[i].name) == 0)
        {
            if (pr_1[i].price != pr_2[i].price)
                return FAIL;
        }
        else
            return FAIL;
    }

    return OK;
}

int check_filt(product_t *pr_in, size_t *len_in, product_t *pr_out, size_t len_out, price_t p)
{
    filt_array(pr_in, len_in, p);

    if (comp_array(pr_in, *len_in, pr_out, len_out) == FAIL)
        return FAIL;
    
    return OK;
}

START_TEST(normal_filt)
{
    int error_code = OK;

    product_t products_in[4] = {{"Milk", 10}, {"Carrot", 20}, {"Meat", 34}, {"Bread", 5}};
    size_t len_in = 4;

    product_t products_out[3] = {{"Milk", 10}, {"Carrot", 20}, {"Bread", 5}};
    size_t len_out = 3;

    price_t p = 25;

    error_code = check_filt(products_in, &len_in, products_out, len_out, p);
    ck_assert_int_eq(error_code, OK);
}
END_TEST

START_TEST(all_el_filt)
{
    int error_code = OK;

    product_t products_in[4] = {{"Milk", 10}, {"Carrot", 20}, {"Meat", 34}, {"Bread", 5}};
    size_t len_in = 4;

    product_t products_out[4] = {{"Milk", 10}, {"Carrot", 20}, {"Meat", 34}, {"Bread", 5}};
    size_t len_out = 4;

    price_t p = 40;

    error_code = check_filt(products_in, &len_in, products_out, len_out, p);
    ck_assert_int_eq(error_code, OK);
}
END_TEST

START_TEST(no_el_filt)
{
    int error_code = OK;

    product_t products_in[4] = {{"Milk", 10}, {"Carrot", 20}, {"Meat", 34}, {"Bread", 5}};
    size_t len_in = 4;

    price_t p = 5;

    error_code = filt_array(products_in, &len_in, p);
    ck_assert_int_eq(error_code, ERROR_EMPTY_ARRAY);
}
END_TEST

Suite* filt_test_suite(Suite *s)
{
    TCase *tc_pos;
    tc_pos = tcase_create("positives");

    tcase_add_test(tc_pos, normal_filt);
    tcase_add_test(tc_pos, all_el_filt);
    tcase_add_test(tc_pos, no_el_filt);

    suite_add_tcase(s, tc_pos);
    return s;
}