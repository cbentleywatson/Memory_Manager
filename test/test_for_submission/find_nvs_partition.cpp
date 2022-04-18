#include "tests_for_submission.h"
void find_nvs_partition(void)
{
	String code_partition_name;
	// code_partition_name = "code_nvs";
	code_partition_name = "nvs";
	// char *c = strcpy(new char[code_partition_name.length() + 1], str.c_str());
	const char *code_space = code_partition_name.c_str();
	const esp_partition_t *partition_to_fill;
	partition_to_fill = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, code_space);
	if (partition_to_fill == NULL)
	{
		// This Line is shaky!
		TEST_ASSERT_EQUAL_HEX32(0x00009000, 0);
		return;
	}
	else
	{
		unsigned long flash_address = partition_to_fill->address;
		TEST_ASSERT_EQUAL_HEX32(flash_address, 0x00009000);
		return;
	}
}