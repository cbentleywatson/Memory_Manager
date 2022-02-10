#include "../Memory_Manager.h"
void *Memory_Manager::exec_from_spiffs(String file_name)
{
	FILE *ptr;
	/// const char* real_file_name = "/spiffs" + file_name;
	int length;
	ptr = fopen(file_name.c_str(), "r");
	fseek(ptr, 0, SEEK_END);
	length = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	// length = 200;
	void *exec_ram_function = heap_caps_malloc(length, MALLOC_CAP_EXEC);
	void *contents_from_file = malloc(length);
	fread(contents_from_file, 1, length, ptr);
	memcpy(exec_ram_function, contents_from_file, length);
	free(contents_from_file);
	fclose(ptr);
	return exec_ram_function;
}