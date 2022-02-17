#pragma once
// PURPOSE: ENSURE THAT CALLING A SECTION NEVER LEADES TO A CORE PANIC!!!
#include "../File_Manipulations/File_Tools.h"
#include "ESP32_Memory_Regions.h"

#include <Arduino.h>
#define EXEC_INTERNAL 0
#define HEAP_INTERNAL 1
#define BLOCK_SECTION 3 // This is an empty section basically. Should not be called from memory manager as far as possible because it doesn't give
#define FILE_SECTION 4
#define MAIN_EXEC_BLOCK 5 // A section built on top of a preallocated array.
class Section
{
public:
	// static Section *main_block_section;
	void *memory_area;
	int section_type;
	size_t size; // Heap caps malloc uses this so we should too
	String parent_file;
	// Section::
	bool is_valid;
	// Methods:
	// void set_this_main();
	size_t block_wise_memcopy(void *dest, void *source, size_t source_size);
	size_t Section::block_wise_file_copy(void *dest, String file_name, size_t source_size);
	Section(String file_name, int type);
	// The one below is designed to set up an exec block,
	// Until a main exec block is initialized it isn't safe to use.
	Section::change_main_block(unsigned long allocated_array, size_t array_size);
	Section::fill_main_block(void *target);

	void *get_valid_memory(size_t arg_size, int type);
	~Section();
	void *load_from_file(String file_name, int &memory_size, void *to_fill);
};
