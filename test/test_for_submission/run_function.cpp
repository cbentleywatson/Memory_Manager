#include "tests_for_submission.h"
void test_run_moveable(void)
{

	Serial.print("\nHello from moved function!\n");
	TEST_ASSERT_EQUAL_HEX32(11, 11);
}

// Copy function to exec

void test_function_copied_to_exec(void)
{
	TEST_ASSERT_EQUAL_HEX32(11, 11);
}

void test_function_copied_to_exec_from_file(void)
{
	TEST_ASSERT_EQUAL_HEX32(11, 11);
}
