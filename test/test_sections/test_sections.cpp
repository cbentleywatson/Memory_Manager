
#include <Memory_Manager.h>
#include <unity.h>
int (*fpointer)(int);
#define MEMORY_BLOCK_SIZE 1024
unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));
void test_section_creation(void)
{
	// these will be the same as the args in memory manager
	String file_name = "/spiffs/single_e";
	int type = HEAP_INTERNAL;
	// Variable for  test
	int checker = 14;
	int output;
	// Logic Similar to memory manager
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	fpointer = sec1.memory_area;

	output = fpointer(checker);
	// mm.load_section(checker);
	TEST_ASSERT_EQUAL_INT(checker, output);
}

void test_simple_fill_main_on_mainblock(void)
{
	// these will be the same as the args in memory manager
	String file_name = "/spiffs/single_e";
	int type = HEAP_INTERNAL;
	// Variable for  test
	int checker = 14;
	int output;
	// Logic Similar to memory manager
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	fpointer = sec1.memory_area;

	Section main_block = Section("", MAIN_EXEC_BLOCK);

	void *main_block_target = main_block.memory_area;
	sec1.fill_main_block(main_block_target);

	// fpointer = main_block.memory_area;
	fpointer = main_block.memory_area;
	output = fpointer(checker);
	// mm.load_section(checker);
	TEST_ASSERT_EQUAL_INT(checker, output);
}

void test_change_mainblock(void)
{
	// these will be the same as the args in memory manager
	String file_name = "/spiffs/single_e";
	int type = HEAP_INTERNAL;
	// Variable for  test
	int checker = 14;
	int output;
	// Logic Similar to memory manager
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	fpointer = sec1.memory_area;

	Section main_block = Section("", MAIN_EXEC_BLOCK);
	// Line below fails

	// main_block.change_main_block(memory_block_array, 1024);
	main_block.memory_area = memory_block_array; // replacement with direct change to array

	//void *main_block_target = main_block.memory_area;
	sec1.fill_main_block(memory_block_array);
main_block()
	// fpointer = main_block.memory_area;
	fpointer = main_block.memory_area;
	output = fpointer(checker);
	// mm.load_section(checker);
	TEST_ASSERT_EQUAL_INT(checker, output);
}

void setup()
{
	delay(2500);
	Serial.begin(9600);
	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	SPIFFS.begin(false); //	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	// SPIFFS.begin(false); //
	UNITY_BEGIN();

	RUN_TEST(test_section_creation);
	RUN_TEST(test_simple_fill_main_on_mainblock);

	//RUN_TEST(test_change_mainblock);
	//   section from a memory section
	//   section from a file section
	//   File pointer from block
	UNITY_END();
}

void loop()
{
}
