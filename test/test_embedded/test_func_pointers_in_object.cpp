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

void check_fp_loaded_from_file_with_spiff_exec_loading(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	mm.init_fp_copied_with_spiff_func("/spiffs/t2");
	output = mm.return_fp_copied_from_file(1);
	TEST_ASSERT_EQUAL_INT(1, output);
}
void check_fp_loaded_from_file_with_spiff_exec_loading_and_elf(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	mm.init_fp_copied_with_spiff_func("/spiffs/t2");
	output = mm.return_fp_copied_from_file(1);
	TEST_ASSERT_EQUAL_INT(1, output);
}

void check_fp_loaded_from_file_with_memory_block_lib_transfer_no_crash(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	mm.init_memory_block();
	// mm.init_fp_copied_with_spiff_func()
	mm.init_fp_copied_with_spiff_func("/spiffs/t2");
	mm.fill_memory_block("/spiffs/t2");
	output = mm.return_fp_copied_from_file(1);
	TEST_ASSERT_EQUAL_INT(1, output);
}

void check_fp_loaded_from_file_with_memory_block_lib_transfer_and_external_lib(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	mm.init_memory_block();
	// mm.init_fp_copied_with_spiff_func()
	mm.init_fp_copied_with_spiff_func("/spiffs/t2");
	mm.fill_memory_block("/spiffs/single_e");
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
	RUN_TEST(check_fp_loaded_from_file_with_spiff_exec_loading);
	RUN_TEST(check_fp_loaded_from_file_with_spiff_exec_loading_and_elf);
	RUN_TEST(check_fp_loaded_from_file_with_memory_block_lib_transfer_no_crash);
	RUN_TEST(check_fp_loaded_from_file_with_memory_block_lib_transfer_and_external_lib);

	UNITY_END();
}

void loop()
{
}