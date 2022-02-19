
#include <Memory_Manager.h>
#include <unity.h>
int (*fpointer)(int);
#define MEMORY_BLOCK_SIZE 1024
unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));
unsigned char unsigned_char_block[1024] __attribute__((section(".iram0.text")));
unsigned char plain_array[1024];
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
	// Variable for  test
	int checker = 14;
	int output = 1;
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	Section empty_section = Section("", BLOCK_SECTION); // a 512 byte empty executable section.

	empty_section.fill_with(sec1);

	fpointer = empty_section.memory_area;
	output = fpointer(checker);

	TEST_ASSERT_EQUAL_INT(checker, output);
}
void test_array_load(void)
{
	// these will be the same as the args in memory manager
	String file_name = "/spiffs/single_e";
	// Variable for test
	int checker = 14;
	int output = -1;
	int error_check;
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	unsigned char *test_arr = (unsigned char *)heap_caps_malloc(512, MALLOC_CAP_EXEC);
	Section main_block = Section(test_arr, 512, error_check);

	//Section main_block = Section(unsigned_char_block, 1024, error_check);
	if (print_debug)
	{
		Serial.println("Begin fill_with()");
	}
	main_block.fill_with(sec1);
	const int error = error_check;
	switch (error)
	{
	case 0:
		Serial.println("No Error Reported");
		delay(1000); // Wait a second to flush the buffer in case the cpu is about to crash
		fpointer = main_block.memory_area;
		output = fpointer(checker);
		break;
	default:
		Serial.print("Error: #");
		Serial.print(error);
		Serial.println(" Reported in test_array_load");
	}

	TEST_ASSERT_EQUAL_INT(checker, output);
}

test_file_section_load()
{
	// these will be the same as the args in memory manager
	String file_name = "/spiffs/single_e";
	// Variable for test
	int checker = 14;
	int output = -1;
	int error_check;
	Section sec1 = Section(file_name, error_check); // create a file section

	// Section main_block = Section(plain_array, sizeof(plain_array), error_check);
	Section main_block = Section("", BLOCK_SECTION);
	// Section main_block = Section(unsigned_char_block, sizeof(unsigned_char_block), error_check);
	if (print_debug)
	{
		Serial.println("Begin fill_with()");
	}
	main_block.fill_with(sec1);
	const int error = error_check;
	switch (error)
	{
	case 0:
		Serial.println("No Error Reported");
		delay(1000); // Wait a second to flush the buffer in case the cpu is about to crash
		fpointer = main_block.memory_area;
		output = fpointer(checker);
		break;
	default:
		Serial.print("Error: #");
		Serial.print(error);
		Serial.println(" Reported in test_array_load");
	}

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

	// Sanity check on section creation
	RUN_TEST(test_section_creation);
	// designed to experiment with initial memcopy stuff directly on the section's memory pointers
	RUN_TEST(test_simple_fill_main_on_mainblock);

	// Designed to demonstrate that a section can be filled via a reference to another section.
	RUN_TEST(test_change_mainblock); // First check of fill with system.
	RUN_TEST(test_array_load);		 // Doesn't currently work with the block section approach.
	// Desiged to demonstrate a file can be converted to a section and then run
	RUN_TEST(test_file_section_load);
	//     section from a memory section
	//     section from a file section
	//     File pointer from block
	UNITY_END();
}

void loop()
{
}
