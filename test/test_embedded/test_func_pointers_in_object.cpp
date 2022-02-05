#include <Memory_Manager.h>

#include <unity.h>
int return_one_this(int input)
{
	return 1;
}

void check_default(void)
{
	int output;
	Memory_Manager mm;
	output = mm.return_one(1);
	TEST_ASSERT_EQUAL_INT(1, output);
}

void check_fp_plain(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	output = mm.return_fp_plain(1);
	TEST_ASSERT_EQUAL_INT(1, output);
}

void check_fp_copied_to_exec(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	mm.init_fp_copied_to_exec();
	output = mm.return_fp_copied_to_exec(1);
	TEST_ASSERT_EQUAL_INT(1 + 1, output);
}

void check_fp_loaded_from_file(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	mm.init_fp_copied_from_file();
	output = mm.return_fp_copied_from_file(1);
	TEST_ASSERT_EQUAL_INT(1, output);
}

void setup()
{
	// Serial.begin(9600);
	SPIFFS.begin();
	delay(2000);
	UNITY_BEGIN();
	RUN_TEST(check_default);
	RUN_TEST(check_fp_plain);
	RUN_TEST(check_fp_copied_to_exec);
	RUN_TEST(check_fp_loaded_from_file);
	UNITY_END();
}

void loop()
{
}