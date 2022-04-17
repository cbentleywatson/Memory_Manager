#include "tests_for_submission.h"

int (*fpointer)(int);
#define MY_MEMORY_BLOCK_SIZE 1024
unsigned long small[2]; // __attribute__((section(".iram0.text")));
unsigned long normal[2];
unsigned long flash_array[1024] __attribute__((section(".block.text")));
unsigned long flash_array2[1024] __attribute__((section(".block2.text")));
// unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));

void setup()
{
	// esp_spiram_init();
	delay(2500);
	Serial.begin(9600);
	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	SPIFFS.begin(false);

	UNITY_BEGIN();
	// sanity check on unity running
	RUN_TEST(default_test);
	// Location of Block was found via the external check
	RUN_TEST(block_address_found_via_linker_variable);

	RUN_TEST(get_physical_address_of_pointer);
	// find partition
	// find physical address of a pointer
	// copy into partition
	// Map
	//
	// Check that partition is available
	// Check that
	UNITY_END();
}

void loop()
{
}
