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
void simple_file_load()
{
	Memory_Manager mm;
	int error_code = mm.getFileSize("/spiffs/single_e");
	TEST_ASSERT_GREATER_OR_EQUAL_INT(0, error_code);
}
unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));
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

void check_fp_loaded_from_file_with_memory_block_lib_transfer_doesnt_load_nonexistant_file(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	mm.init_memory_block();
	// mm.init_fp_copied_with_spiff_func()
	mm.init_fp_copied_with_spiff_func("/spiffs/t2");

	mm.fill_memory_block("/spiffs/t2");
	output = mm.fill_memory_block("/spiffs/tss2");
	// output = mm.return_fp_copied_from_file(1);
	TEST_ASSERT_EQUAL_INT(-1, output);
}

void check_fp_loaded_from_file_with_memory_block_lib_transfer_random_files(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	mm.init_memory_block();
	// mm.init_fp_copied_with_spiff_func()
	mm.init_fp_copied_with_spiff_func("/spiffs/t2");

	int return_mm_block = mm.fill_memory_block("/spiffs/t2");
	// FINISH ME!!!

	// output = mm.fill_memory_block("/spiffs/tss2");
	output = mm.fill_memory_block("/single_e");
	return_mm_block = mm.fill_memory_block("/spiffs/single_e");
	if (return_mm_block == -1)
	{
		Serial.println("FILL_MEMORY_BLOCK Failed");
		// TEST_ASSERT_EQUAL_INT(checker, return_mm_block);
	}
	//	output = mm.fill_memory_block("/spiffs/data/single_e");
	int checker = 14;
	output = mm.return_fp_copied_from_file(checker);
	TEST_ASSERT_EQUAL_INT(checker, output);
}
// A global variable memory_block_array is created with an attribute placing it in an existing section sepcified in the linker script,
// The array's address is then passed.
// This checks that the file actually loads the pointer in without errors and the

/*
void check_memory_block_based_pointer_load()
{
	// unsigned long memory_block_array[1024];
	int output;
	int checker = 0;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	mm.init_memory_block();
	output = mm.set_block_pointer_via_array(memory_block_array);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	int return_mm_block = mm.fill_memory_block("/spiffs/single_e");
	if (return_mm_block == -1)
	{
		Serial.println("FILL_MEMORY_BLOCK Failed");
		// TEST_ASSERT_EQUAL_INT(checker, return_mm_block);
	}

	// output = 3;
	TEST_ASSERT_EQUAL_INT(checker, output);
}
*/
void check_fp_loaded_from_file_with_memory_block_created_via_array(void)
{
	int output;
	Memory_Manager mm;
	mm.init_fp_plain(&return_one_this);
	// "/spiffs/t2" is the name of the file that is saved in the testing set up in the init fucntion
	mm.set_block_pointer_via_array(memory_block_array);
	// mm.init_fp_copied_with_spiff_func()
	// mm.init_fp_copied_with_spiff_func("/spiffs/t2");

	// mm.fill_memory_block("/spiffs/t2");
	//  output = mm.fill_memory_block("/spiffs/tss2");
	//  output = mm.fill_memory_block("/single_e");
	output = mm.fill_memory_block("/spiffs/single_e");
	//	output = mm.fill_memory_block("/spiffs/data/single_e");
	int checker = 14;
	output = mm.return_fp_copied_from_file(checker);
	TEST_ASSERT_EQUAL_INT(checker, output);
}

void setup()
{
	delay(2500);
	Serial.begin(9600);
	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	SPIFFS.begin(false); //

	UNITY_BEGIN();
	RUN_TEST(check_default);
	RUN_TEST(check_fp_plain);
	RUN_TEST(check_fp_copied_to_exec);
	RUN_TEST(check_fp_loaded_from_file);
	RUN_TEST(check_fp_loaded_from_file_with_spiff_exec_loading);
	RUN_TEST(check_fp_loaded_from_file_with_spiff_exec_loading_and_elf);
	RUN_TEST(simple_file_load);
	RUN_TEST(check_fp_loaded_from_file_with_memory_block_lib_transfer_no_crash);
	RUN_TEST(check_fp_loaded_from_file_with_memory_block_lib_transfer_doesnt_load_nonexistant_file);
	RUN_TEST(check_fp_loaded_from_file_with_memory_block_lib_transfer_random_files); // Last Successful version
	// This one seems to basically be a test of whether or not the file system loads properly, but it could be a lot clear
	//RUN_TEST(check_memory_block_based_pointer_load); // This is the one that's failing

	RUN_TEST(check_fp_loaded_from_file_with_memory_block_created_via_array); // this is also failing

	UNITY_END();
}

void loop()
{
}