#include "../Memory_Manager.h"
void *Memory_Manager::file_to_heap_pure_fstructs(String file_name)
{
	FILE *ptr;
	/// const char* real_file_name = "/spiffs" + file_name;
	int length_file;
	ptr = fopen(file_name.c_str(), "r");
	fseek(ptr, 0, SEEK_END);
	length_file = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);

	int length_array = modulo_smooth(length_file);
	void *heap_memory_input_ptr = heap_caps_malloc(length_array, MALLOC_CAP_DMA);
	fread(heap_memory_input_ptr, 1, length_file, ptr);
	fclose(ptr);
	return heap_memory_input_ptr;
}