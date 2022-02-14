#include "Sections.h"
#define EXEC_INTERNAL 0
#define HEAP_INTERNAL 1

void *Section::get_valid_memory(size_t arg_size, int type)
{
	/* this function is designed to get piece of heap memory with the correct size and alignment for running functions
	 * These pieces of memory need to have 4 byte alignment, and sizes need to be a multiple of four. If they're not and you try to copy the whole thing, you'll break the requiremnt
	 * that all exec memory accesses need to be four byte aligned, resulting in a load store error when using memcopy.
	 */
	size_t real_size = modulo_smooth(arg_size);
	void *my_pointer;
	switch (type)
	{
	case EXEC_INTERNAL:
		my_pointer = heap_caps_malloc(real_size, MALLOC_CAP_EXEC);
		break;
	case HEAP_INTERNAL:
		my_pointer = heap_caps_malloc(real_size, MALLOC_CAP_DMA);
		break;
	default:
		my_pointer = NULL;
	}
	return my_pointer;
}
Section::Section(String file_name, int type)
{ /*
   * You can use the initializer to ensure that everything is valid to prevent the
   * the creation of dangerous undefined sections
   */
	is_valid = false;
	long file_size = getFileSize_long(file_name);
	// Do checking etc.
	size = modulo_smooth((size_t)file_size);
	memory_area = get_valid_memory(size, type);
	// do more checks...
	parent_file = file_name;
	section_type = type;
	is_valid = true;
}
Section::~Section()
{
	// need to check if memory area is actually a nullptr;
	if (memory_area != NULL)
	{
		heap_caps_free(memory_area);
	}
}

/*
	int real_size = modulo_smooth(arg_size); //  make the size valid if it isn't
	void *my_pointer = heap_caps_malloc(real_size, MALLOC_CAP_DMA);
	// switch (type)
	size_allocated_array = real_size;
	return my_pointer;
}

Section::Section(String file_name, int type)
{
	memory_area = nullptr;
	section_type = 0;
	size = 0;
	parent_file = "";
}
void *Section::get_valid_heap_memory(int arg_size, int &size_allocated_array);
// constructors
//  unsigned long VMA;
//  unsigned long LMA;
// Get Valid h
}
*/