#include <check.h>
#include "check_pop.h"
#include "check_sort.h"
#include "check_remove.h"

Suite *unit_suite(void)
{
    Suite *s = suite_create("unit_tests");

    s = pop_test_suite(s);
    s = sort_test_suite(s);
    s = remove_test_suite(s);

    return s;
}

int main(void)
{
    int errors = 0;

    Suite *s;
    SRunner *runner;

    s = unit_suite();

    runner = srunner_create(s);

    srunner_run_all(runner, CK_VERBOSE);

    errors = srunner_ntests_failed(runner);

    srunner_free(runner);

    return errors;
}