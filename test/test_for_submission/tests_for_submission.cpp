#include "Arduino.h"
#include <Memory_Manager.h>
#include "sort.h"
#include <unity.h>

int (*fpointer)(int);
#define MY_MEMORY_BLOCK_SIZE 1024
unsigned long small[2]; // __attribute__((section(".iram0.text")));
unsigned long normal[2];
unsigned long flash_array[1024] __attribute__((section(".block.text")));
unsigned long flash_array2[1024] __attribute__((section(".block2.text")));
// unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));
void default_test(void);
void default_test(void)
{
	TEST_ASSERT_EQUAL_INT(2, 2);
}

void setup()
{
	// esp_spiram_init();
	delay(2500);
	Serial.begin(9600);
	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	SPIFFS.begin(false); //	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	// SPIFFS.begin(false); //
	UNITY_BEGIN();

	RUN_TEST(default_test);

	UNITY_END();
}

void loop()
{
}
