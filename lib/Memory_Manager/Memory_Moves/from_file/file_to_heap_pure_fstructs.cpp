#include "../../Memory_Manager.h"
void *Memory_Manager::file_to_heap_pure_fstructs(String file_name)
{
	FILE *ptr;
	/// const char* real_file_name = "/spiffs" + file_name;
	int length_file;
	ptr = fopen(file_name.c_str(), "r");
	fseek(ptr, 0, SEEK_END);
	length_file = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	int length_array = 0;

	// length_file = getFileSize(file_name);
	// length_array = modulo_smooth(length_file);
	void *heap_memory_input_ptr;
	// length array is a reference with a change to fill
	heap_memory_input_ptr = get_valid_heap_memory(length_file, length_array);
	// heap_caps_malloc(length_array, MALLOC_CAP_DMA);

	// length_array returned from func,
	// heap_mem input filled by get valid heap
	// void *heap_memory_input_ptr;
	// length_array =
	// get_valid_heap_memory(length_file, heap_memory_input_ptr);

	fread(heap_memory_input_ptr, 1, length_array, ptr);
	fclose(ptr);
	return heap_memory_input_ptr;
}