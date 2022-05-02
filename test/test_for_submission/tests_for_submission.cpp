#include "tests_for_submission.h"
#define MY_MEMORY_BLOCK_SIZE 1024;
int (*fpointer)(int);

// unsigned long flash_array2[1024] __attribute__((section(".block2.text")));
unsigned long small[2]; // __attribute__((section(".iram0.text")));
unsigned long normal[2];
// unsigned long flash_array[1024] __attribute__((section(".block.text")));
// unsigned long flash_array2[1024] __attribute__((section(".block2.text")));
// unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));
// int loadable(void);

int loadable(void) __attribute__((section(".block2.text")));
int loadable(void)
{

	return 0xFFF;
}
// Worst error with the my_iram.txt
//

int loadable_iram(void) __attribute__((section(".my_iram.text"))); // Calls the thing correctly but says the instruction is illegal
// int loadable_iram(void) __attribute__((section(".my_flash_overlay.text")));
int loadable_iram(void)
{
	return 0xFFF;
}
int loadable_iram(void) __attribute__((section(".my_iram.text"))); // Calls the thing correctly but says the instruction is illegal
// int loadable_iram(void) __attribute__((section(".my_flash_overlay.text")));
int loadable_VADDR1(void) __attribute__((section(".my_post_flash_seg.text")));

int loadable_VADDR1(void)
{
	return 0xFFF;
}

int copy_from(void)
{
	return 0xDDD;
}

void setup()
{
	// esp_spiram_init();
	delay(2500);
	// loadable_VADDR1(); // This now points to VADDR2
	//    loadable_iram();
	//  loadable_iram();
	Serial.begin(9600);
	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	SPIFFS.begin(false);

	UNITY_BEGIN();
	// sanity check on unity running
	RUN_TEST(default_test);
	// Location of Block was found via the external check
	RUN_TEST(block_address_found_via_linker_variable);
	RUN_TEST(find_nvs_partition);
	RUN_TEST(get_physical_address_of_pointer);
	RUN_TEST(map_physical_flash_to_virtual_address);
	RUN_TEST(fill_flash_for_write);
	RUN_TEST(fill_flash_with_ordinary_function);
	RUN_TEST(fill_flash_from_file);
	RUN_TEST(test_run_moveable);
	RUN_TEST(test_function_copied_to_exec);
	RUN_TEST(test_function_copied_to_exec_from_file);

	/*
	// demo normal function
	// demo loaded
	*/

	//   find partition
	//   find physical address of a pointer
	//   copy into partition
	//   Map
	//
	//   Check that partition is available
	//   Check that
	UNITY_END();
}

void loop()
{
}
