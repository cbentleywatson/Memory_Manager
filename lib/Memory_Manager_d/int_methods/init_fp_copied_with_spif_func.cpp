#include "../Memory_Manager.h"
void Memory_Manager::init_fp_copied_with_spiff_func(String file_name)
{
	// Filling this in and exec_from_spiffs, and then thats going to be tested
	void *function_contents = malloc(200);
	memcpy(function_contents, (void *)int_int_fp_plain, 200);

	FILE *ptr;
	ptr = fopen("/spiffs/t2", "wb");
	fwrite(function_contents, 200, 1, ptr);
	fclose(ptr);

	int_int_fp_copied_from_file = exec_from_spiffs(file_name);
}