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
#define NO_ERROR 0
#define DEFAULT_ERROR -1
#define print_debug true
class Section
{
public:
	// static Section *main_block_section;
	void *memory_area;
	unsigned long *remove_me;
	int section_type;
	size_t size; // Heap caps malloc uses this so we should too
	String parent_file;
	// Section::
	bool is_valid;
	bool has_valid_content;
	bool has_valid_memory;
	set_ptr(void *a);
	set_ptr(unsigned long a);
	// Methods:
	// void set_this_main();
	// public static Section * create_file_section(String file_name);
	// public static Section * create_exec_block(unsigned char preallocated_array[], size_t len)

	// Section(String file_name);
	// Section( unsigned char preallocated_array[], size_t len)
	int fill_with(Section &donor);
	// Section(Section &donor, int type);

	// Section(String file_name, int &error);								 // creates a file section
	Section(unsigned char preallocated_array[], size_t len, int &error); // used for creating layover block sections
	Section(unsigned long preallocated_array[], size_t len, int &error); // used for creating layover block sections
	// int fill_with(Section &donor, int &error); // move a section into the memory block
	// Section(Section &donor, int type, int &error);
	// fill_function_pointer(void * fp, int &error); // fill a function pointer of any type
	size_t block_wise_memcopy(void *dest, void *source, size_t source_size);
	size_t Section::block_wise_file_copy(void *dest, String file_name, size_t source_size);
	Section(String file_name, int type);
	void *get_valid_memory(size_t arg_size, int type);
	~Section();

	void *load_from_file(String file_name, int &memory_size, void *to_fill);
	Section(unsigned long arr[], size_t my_size);								  //
	Section(void *, size_t size);												  //
	Section::change_main_block(unsigned long allocated_array, size_t array_size); // Also to be deleted
	Section::fill_main_block(void *target);										  // to be deleted ASAP
};
