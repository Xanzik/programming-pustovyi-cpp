/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій
 *
 * @author Pustovy I.
 * @date 26-apr-2022
 * @version 1.0
 */
 #include <stdio.h>
 #include <stdlib.h>
#include <check.h>
START_TEST(test_func) {
}
END_TEST

int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("lab14");
	tcase_add_test(tc_core, test_func);
	suite_add_tcase(s, tc_core);
	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
