#include <check.h>
#include "check_turn.h"

Suite *unit_suite(void)
{
    Suite *s = suite_create("unit_tests");

    s = turn_test_suite(s);

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