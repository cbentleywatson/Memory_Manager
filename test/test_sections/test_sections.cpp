#include "Arduino.h"
#include <Memory_Manager.h>
#include <unity.h>
#include "single.h"
extern int _load_lib_start;
extern unsigned int _larray[3];
int (*fpointer)(int);
#define MEMORY_BLOCK_SIZE 1024
unsigned long small[64] __attribute__((section(".test.text")));
unsigned long small2[64] __attribute__((section(".test2.text")));
unsigned long small3[64] __attribute__((section(".test3.text")));
static unsigned long small4[4] __attribute__((section(".test4.text"))) = {1, 2, 3, 4};
unsigned long small5[4] __attribute__((section(".test5.text"))) = {5, 6, 7, 8};
unsigned long small6[4] __attribute__((section(".test6.text"))) = {5, 6, 7, 8};
unsigned long small7[4] __attribute__((section(".test7.text"))) = {5, 6, 7, 8};
unsigned long small8[4] __attribute__((section(".test8.text"))) = {5, 6, 7, 8};

unsigned long in_new_sec[16] __attribute__((section(".loadlib.text")));
unsigned long normal[2];
unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));
unsigned long external_mem[256] __attribute__((section("extern_ram_segment")));

unsigned char unsigned_char_block[1024] __attribute__((section(".iram0.text")));
unsigned char plain_array[1024];
<<<<<<< Updated upstream
=======

void IRAM_ATTR copy(unsigned long dest[], unsigned long source[], int length);
void IRAM_ATTR copy(unsigned long dest[], unsigned long source[], int length)
{
	// v quick test of ld script
	// flash_array2[0] = 0;
	// flash_array2[1] = 1;
	int i = 0;
	int temp;
	while (i < length)
	{
		temp = source[i];
		dest[i] = temp;
		i++;
	}
}
// demonstrates that a moved function can call hardware....
int side_effect_test(void) __attribute__((section(".side_effect_test.text")));
/*
int test_flash_partion(void){


}


*/
int side_effect_test(void)
{
	int b = 0;
	// int b = test(11);

	b = b + 11;
	Serial.print("Hello World From Side Effect Test");
	return b;
}
void test_sort_test(void)
{
	int a = 1;
	int (*to_test)(int) = &test;
	unsigned long address = (unsigned long)to_test;
	int b = 1;
	// test will add 1 to a
	b = test(a);

	if ((address >= 0x3F800000) && (address < (0x40080000)))
	{
		b = 2;
	}
	else
	{
		b = 1;
	}

	TEST_ASSERT_EQUAL_INT(2, b);
}

>>>>>>> Stashed changes
void test_section_creation(void)
{
	Serial.print("Load lib start: ");
	// Serial.println(_load_lib_start);
	//   these will be the same as the args in memory manager
	String file_name = "/spiffs/single_e";
	int type = HEAP_INTERNAL;
	// Variable for  test
	unsigned int *t = _larray;

	Serial.print("Single_func output: ");
	int j = single_func(37);
	/*Serial.println(j);*/
	unsigned int a = _larray[0];
	unsigned int b = _larray[1];
	unsigned int c = _larray[2];
	//  unsigned long a = 0;
	// a = *t;
	// delay(500);
	small[0] = 11;
	small2[0] = 12;
	small3[0] = 13;
	Serial.print("a = ");
	Serial.println(a, HEX);

	Serial.print("b = ");
	Serial.println(b, HEX);
	Serial.print("c = ");
	Serial.println(c, HEX);
	Serial.print("Small[0] = ");

	unsigned int double_place = 57;
	Serial.print("double_place = ");
	Serial.println(double_place);
	small3[0] = 99;
	Serial.print("small3[0] = ");
	Serial.println(small3[0]);

	small2[0] = double_place;
	Serial.print("small2[0] assigned to double place and now equals : ");
	Serial.println(small2[0]);
	Serial.print("small3[0] becase : ");
	Serial.println(small3[0]);

	small2[1] = double_place;
	small2[2] = double_place;
	small4[0] = 11;
	small4[1] = 12;
	small4[2] = 13;
	small4[3] = 14;
	small5[0] = 12;
	// small5[0] = 512;

	Serial.print("small4[0] now equals ");
	Serial.println(small4[0]);

	Serial.print("small5[0] (previously 1)");
	Serial.println(small5[0]);
	small5[1] = 21;
	small5[2] = 22;
	small5[3] = 23;
	// delay(1000);
	// small6[0] = 1;

	small7[0] = 2; // small6[0];
	small6[1] = small7[0];

	small8[1] = small7[0];
	small7[2] = small8[1];
	int q;

	// q = 1111;
	//  delay(1000);
	q = small[0];
	Serial.println(q);
	int checker = 14;
	int output;
	// Logic Similar to memory manager
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	fpointer = sec1.memory_area;

	// output = fpointer(checker);
	//  mm.load_section(checker);
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
	void *to_long = (void *)memory_block_array;
	unsigned char *test_arr = (unsigned char *)heap_caps_malloc(512, MALLOC_CAP_EXEC);
	Section main_block = Section(test_arr, 512, error_check);
	// Section main_block = Section((unsigned char *)to_long, 1024, error_check);
	//  Section main_block = Section(unsigned_char_block, 1024, error_check);
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
	memory_block_array[0] = 100;
	memcpy((void *)memory_block_array, (void *)unsigned_char_block, 16);
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

void test_block_based_load(void)
{
	// these will be the same as the args in memory manager
	String file_name = "/spiffs/single_e";
	// Variable for test
	int checker = 14;
	int output = -1;
	int error_check;
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	// void *to_long = (void *)memory_block_array;
	// unsigned char *test_arr = (unsigned char *)heap_caps_malloc(512, MALLOC_CAP_EXEC);
	// Section main_block = Section(memory_block_array, 512, error_check);
	Section main_block = Section(memory_block_array, 512);
	void *a = &memory_block_array[0];
	void *s = malloc(8);
	void *norm = &normal[0];
	// unsigned
	// Section vs = Section(s, 8); // Section works with new meemory
	unsigned long internal_array[2] = {0, 0};
	void *ia = &internal_array[0];
	unsigned long address = (unsigned long)ia;
	//  Section vs = Section(norm, 8);// Does not work with norm in memory area assigned
	Section vs = Section(ia, 8); // Does not work with an array allocated here. // Works
	s = a;
	int ran = 11;
	int *intptr = &ran;
	void *rr = intptr;
	s = malloc(8);
	// vs.set_ptr(s);
	//  vs.set_ptr(address);
	Serial.println("Finished Section with array");
	// Section main_block = Section((unsigned char *)to_long, 1024, error_check);
	//  Section main_block = Section(unsigned_char_block, 1024, error_check);
	if (print_debug)
	{
		Serial.println("Begin fill_with()");
	}
	// main_block.fill_with(sec1);
	const int error = 0; // error_check;
	switch (error)
	{
	case 0:
		Serial.println("No Error Reported");
		delay(1000);
		// void *small = heap_caps_malloc(256, MALLOC_CAP_32BIT);
		//	memcpy(exec_ram_memory_block, (void *)file_contents, array_length);
		//  memcpy((void *)memory_block_array, (void *)sec1.memory_area, 8);
		//	unsigned long *a = sec1.memory_area;
		//	unsigned long q;
		//	for (int i = 0; i < 2; i++)

		//	{
		// q = a[i];
		// memory_block_array[i] = q;
		//	}
		// Section prebuilt = Section(memory_block_array, 8);

		// Wait a second to flush the buffer in case the cpu is about to crash
		// memcpy((void *)main_block.memory_area, (void *)sec1.memory_area, 8); // memcpy is not the cause of the crash
		// memcpy(small, (void *)sec1.memory_area, 8);		  // memcpy is not the cause of the crash
		// memcpy((void *)main_block.memory_area, small, 8); // memcpy is not the cause of the crash
		Serial.println("Copy finished");
		// fpointer = prebuilt.memory_area;
		// void *z = &memory_block_array;
		main_block.fill_with(sec1);
		Serial.println("Directly above fpointer set with main_block");
		fpointer = main_block.memory_area;
		// fpointer = sec1.memory_area;
		output = fpointer(checker);
		break;
	default:
		Serial.print("Error: #");
		Serial.print(error);
		Serial.println(" Reported in test_array_load");
	}

	TEST_ASSERT_EQUAL_INT(checker, output);
}

void test_external_exec(void)
{
	String file_name = "/spiffs/single_e";
	// Variable for test
	int checker = 14;
	int output = -1;
	int error_check;
	Section sec1 = Section(file_name, EXEC_INTERNAL);
	Section external = Section("", EXTERNAL_EXEC);
	external.fill_with(sec1);
	fpointer = external.memory_area;
	output = fpointer(checker);
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

	// Final Test of block Stuff
	RUN_TEST(test_block_based_load);
	RUN_TEST(test_external_exec);
	//     section from a memory section
	//     section from a file section
	//     File pointer from block
	UNITY_END();
}

void loop()
{
}
