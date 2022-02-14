/*
#include "../Memory_Manager.h"

static int Sections::modulo_smooth(int n)
{
	// Integer math to make every piece of memory come in a 4 byte chunk
	int four = 4;
	return ((n + four) / four) * four;
}

static int Sections::getFileSize(String file_name)
{
	FILE *ptr;
	ptr = fopen(file_name.c_str(), "r");
	if (ptr == NULL)
	{
		return -1;
	}
	fseek(ptr, 0, SEEK_END);
	int length_file = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	fclose(ptr);
	return length_file;
}

void *Section::get_valid_memory(int arg_size, int type)
{
	/* this function is designed to get piece of heap memory with the correct size and alignment for running functions
	 * These pieces of memory need to have 4 byte alignment, and sizes need to be a multiple of four. If they're not and you try to copy the whole thing, you'll break the requiremnt
	 * that all exec memory accesses need to be four byte aligned, resulting in a load store error when using memcopy.
	 */
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