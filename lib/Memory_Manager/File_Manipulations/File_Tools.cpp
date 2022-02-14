#include "File_Tools.h"
int modulo_smooth(int n)
{
	// Integer math to make every piece of memory come in a 4 byte chunk
	int four = 4;
	return ((n + four) / four) * four;
}
size_t modulo_smooth(size_t n)
{
	// Integer math to make every piece of memory come in a 4 byte chunk
	size_t four = 4;
	return ((n + four) / four) * four;
}

int getFileSize(String file_name)
{
	FILE *ptr;
	ptr = fopen(file_name.c_str(), "r");
	if (ptr == NULL)
	{
		return -1;
	}
	fseek(ptr, 0, SEEK_END);
	int length_file = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	fclose(ptr);
	return length_file;
}
long getFileSize_long(String file_name)
{
	FILE *ptr;
	ptr = fopen(file_name.c_str(), "r");
	if (ptr == NULL)
	{
		return -1;
	}
	fseek(ptr, 0, SEEK_END);
	long length_file = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	fclose(ptr);
	return length_file;
}

int print_file_info(String file_name)
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

