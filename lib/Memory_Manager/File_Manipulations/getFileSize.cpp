#include "../Memory_Manager.h"
static int Memory_Manager::getFileSize(String file_name)
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
