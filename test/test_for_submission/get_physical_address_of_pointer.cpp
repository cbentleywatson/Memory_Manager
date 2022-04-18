#include "tests_for_submission.h"

// esp_partition_iterator_tesp_partition_find(esp_partition_type_ttype, esp_partition_subtype_tsubtype, const char *label)
void get_physical_address_of_pointer(void)
{
	String code_partition_name;
	code_partition_name = "code_space";
	// code_partition_name = "nvs";
	//  char *c = strcpy(new char[code_partition_name.length() + 1], str.c_str());
	const char *code_space = code_partition_name.c_str();
	const esp_partition_t *partition_to_fill;
	partition_to_fill = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, code_space);
	if (partition_to_fill == NULL)
	{
		TEST_ASSERT_EQUAL_HEX32(0x110000, 0x21);
		return;
	}
	else
	{
		unsigned long flash_address = partition_to_fill->address;
		TEST_ASSERT_EQUAL_HEX32(flash_address, 0x140000);
		return;
	}
}

unsigned long real_get_physical_address_of_pointer(String code_partition_name)
{
	//String code_partition_name;
	//code_partition_name = "code_space";
	// code_partition_name = "nvs";
	//  char *c = strcpy(new char[code_partition_name.length() + 1], str.c_str());
	const char *code_space = code_partition_name.c_str();
	const esp_partition_t *partition_to_fill;
	partition_to_fill = esp_partition_find_first(ESP_PARTITION_TYPE_DATA, ESP_PARTITION_SUBTYPE_ANY, code_space);
	if (partition_to_fill == NULL)
	{
		// TEST_ASSERT_EQUAL_HEX32(0x110000, 0x21);
		return 0;
	}
	else
	{
		unsigned long flash_address = partition_to_fill->address;

		return flash_address;
	}
}
