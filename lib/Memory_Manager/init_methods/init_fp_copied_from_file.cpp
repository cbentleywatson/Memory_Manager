#include "../Memory_Manager.h"
void Memory_Manager::init_fp_copied_from_file()
{
	void *function_contents = malloc(200);
	memcpy(function_contents, (void *)int_int_fp_plain, 200);

	FILE *ptr;
	ptr = fopen("/spiffs/t2", "wb");
	fwrite(function_contents, 200, 1, ptr);
	fclose(ptr);

	void *contents_from_file = malloc(200);
	size_t block_size;
	void *exec_ram_function;
	// get_valid_exec_memory(block_size, exec_ram_function); //
	exec_ram_function = heap_caps_malloc(200, MALLOC_CAP_EXEC);
	ptr = fopen("/spiffs/t2", "r");
	fread(contents_from_file, 1, 200, ptr);
	fclose(ptr);
	memcpy(exec_ram_function, contents_from_file, 200);
	// funct_to_file(int_int_fp_plain, "/testheap", 200);
	int_int_fp_copied_from_file = exec_ram_function;
}