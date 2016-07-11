
#include <stdlib.h>
#include <stdint.h>
#include <check.h>
#include "../src/AddSubRomanNum.h"

char inputRoman1[1000] = "XIV";
char inputRoman2[1000] = "XI";

void setup(void)
{
    inputRoman1[0] = 'X';
	inputRoman1[1] = 'I';
	inputRoman1[2] = 'V';
	inputRoman1[3] = '\0';
	inputRoman2[0] = 'X';
	inputRoman2[1] = 'V';
	inputRoman2[2] = '\0';
	
}



START_TEST(test_money_create)
{
    ck_assert_str_eq(AddTwoRomanNumbers(inputRoman1,inputRoman2), "XXIX");
    ck_assert_str_eq(SubtractTwoRomanNumbers(inputRoman1,inputRoman2), "I");
}
END_TEST

START_TEST(test_money_create_neg)
{
    ck_assert_str_eq(AddTwoRomanNumbers(inputRoman1,inputRoman2), "XXIX");
    ck_assert_str_eq(SubtractTwoRomanNumbers(inputRoman1,inputRoman2), "I");
}
END_TEST

START_TEST(test_money_create_zero)
{
   ck_assert_str_eq(AddTwoRomanNumbers(inputRoman1,inputRoman2), "XXIX");
    ck_assert_str_eq(SubtractTwoRomanNumbers(inputRoman1,inputRoman2), "I");
}
END_TEST

Suite * money_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_limits;

    s = suite_create("Money");

    /* Core test case */
    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_money_create);
    suite_add_tcase(s, tc_core);

    /* Limits test case */
    tc_limits = tcase_create("Limits");

    tcase_add_test(tc_limits, test_money_create_neg);
    tcase_add_test(tc_limits, test_money_create_zero);
    suite_add_tcase(s, tc_limits);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = money_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
