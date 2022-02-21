#include <Memory_Manager.h>
#include <unity.h>
int (*fpointer)(int);
#define MEMORY_BLOCK_SIZE 1024
unsigned long memory_block_array[1024] __attribute__((section(".iram0.text")));
unsigned char unsigned_char_block[1024] __attribute__((section(".iram0.text")));
unsigned char plain_array[1024];
int return_one_this(int input)
{
	return 1;
}

void move_into_block()
{
	String file_name = "/spiffs/single_e";
	// Variable for test
	int checker = 14;
	int output = -1;
}
void setup()
{
	delay(2500);
	Serial.begin(9600);
	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	SPIFFS.begin(false); //	bool begin(bool formatOnFail = false, const char *basePath = "/spiffs", uint8_t maxOpenFiles = 10);
	// SPIFFS.begin(false); //
	UNITY_BEGIN();
	RUN_TEST(move_into_block);
	UNITY_END();
}

void loop()
{
}
