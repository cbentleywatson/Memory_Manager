#include "../File_Manipulations/File_Tools.h"

#pragma once
#include <Arduino.h>
#define EXEC_INTERNAL 0
#define HEAP_INTERNAL 1
#define BLOCK_SECTION 3
class Section
{
public:
	void *memory_area;
	int section_type;
	size_t size; // Heap caps malloc uses this so we should too
	String parent_file;
	bool is_valid;
	// Methods:
	size_t block_wise_memcopy(void *dest, void *source, size_t source_size);
	size_t Section::block_wise_file_copy(void *dest, String file_name, size_t source_size);
	Section(String file_name, int type);
	void *get_valid_memory(size_t arg_size, int type);
	~Section();
	void *load_from_file(String file_name, int &memory_size, void *to_fill);
};
