#include "../Memory_Manager.h"
int Memory_Manager::print_file_info(String file_name)
{
	int length = getFileSize(file_name);
	// int array_length = modulo_smooth(length);
	if (length <= 0)
	{
		// File No Found Errors

		Serial.print("file_name:");
		Serial.println("File Not Found!!!");

		return -1;
	}
	Serial.print("File Name: ");
	Serial.println(file_name);
	Serial.print("File Size: ");
	Serial.println(length);
	Serial.print("Array Length: ");
}