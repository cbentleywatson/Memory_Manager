#include "../Memory_Manager.h"
int Memory_Manager::fill_memory_block(String file_name)
{

	// Get file contents onto the heap

	int length = getFileSize(file_name); // This can probably go later, this is just a quck and
	int array_length = modulo_smooth(length);
	if (length <= 0)
	{
		// File No Found Errors
		if (PRINT_DEBUG)
		{
			Serial.print("file_name:");
			Serial.println("File Not Found!!!");
		}
		return -1;
	}
	if (PRINT_DEBUG)
	{
		Serial.print("File Name: ");
		Serial.println(file_name);
		Serial.print("File Size: ");
		Serial.println(length);
		// Serial.print("Array Length: ");
		// Serial.println(array_length);
	}
	void *file_contents = NULL;
	file_contents = file_to_heap_pure_fstructs(file_name);

	// move the stuff from the heap onto the preallocated memory block area, free the heap memory
	memcpy(exec_ram_memory_block, (void *)file_contents, array_length);
	int_int_fp_copied_from_file = exec_ram_memory_block;
	free(file_contents);
	// Move the function point to to point to the block, return success or emit an error.

	return 0;
}