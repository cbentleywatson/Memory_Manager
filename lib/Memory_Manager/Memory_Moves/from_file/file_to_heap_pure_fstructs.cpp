#include "../../Memory_Manager.h"
void *Memory_Manager::file_to_heap_pure_fstructs(String file_name)
{
	FILE *ptr;
	/// const char* real_file_name = "/spiffs" + file_name;
	int length_file;
	ptr = fopen(file_name.c_str(), "r");
	if(ptr ==NULL){
		return ptr;
	}
	fseek(ptr, 0, SEEK_END);
	length_file = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	// length_file = getFileSize(ptr);
	int size_of_allocated_memory = 0; // Be filled by reference in get_valid_heap_memory

	void *allocated_heap_memory;
	//
	allocated_heap_memory = get_valid_heap_memory(length_file, size_of_allocated_memory);
	fread(allocated_heap_memory, 1, size_of_allocated_memory, ptr);
	fclose(ptr);
	return allocated_heap_memory;
}