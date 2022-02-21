#include "Sections.h"

int Section::fill_with(Section &donor)
{
	int receiver_type = section_type;

	// Deal with any memory sizing issues
	int smaller_memory_size = (donor.size < size) ? donor.size : size;
	int size_to_move = smaller_memory_size;

	if (true)
	{
		Serial.print("moved size: ");
		Serial.println(size_to_move);
		if (size_to_move % 4 != 0)
		{
			Serial.println("Invalid modulo");
		}
	}

	if (receiver_type == (EXEC_INTERNAL) || (receiver_type == BLOCK_SECTION) || (receiver_type == MAIN_EXEC_BLOCK))
	{
		int donor_type = donor.section_type;

		if (donor_type == FILE_SECTION)
		{
			block_wise_file_copy(memory_area, donor.parent_file, size_to_move);
			return 0;
		}
		else if (donor_type == EXEC_INTERNAL)
		{
			Serial.println("Directly above memcopy");
			block_wise_memcopy(memory_area, donor.memory_area, size_to_move);
			return 0;
		}
		else
		{
			return -1;
		}
	}
}
/*
Section::Section(String file_name, int &error)
{
	memory_area = nullptr;
	section_type = FILE_SECTION;
	parent_file = file_name;
	size = getFileSize_long(file_name); //
	// Hopefully:
	has_valid_content = true;
	has_valid_memory = false;
}
*/
Section::Section(unsigned char preallocated_array[], size_t len, int &error)
{
	section_type = MAIN_EXEC_BLOCK;
	memory_area = preallocated_array;
	size = len;

	void *voidcon = &preallocated_array;
	unsigned long num_address = (unsigned long)voidcon;

	bool in_external_exec = (EXTERNAL_INS_START <= num_address) && (num_address <= EXTERNAL_INS_END);

	has_valid_memory = (len % 4 == 0) && (num_address % 4 == 0);
	has_valid_content = false;
	parent_file = "";
	if (has_valid_memory)
	{
		Serial.println("Invalid Memory");
		error = NO_ERROR;
	}
	else
	{
		error = DEFAULT_ERROR;
	}
}

Section::Section(unsigned long preallocated_array[], size_t len, int &error)
{
	section_type = MAIN_EXEC_BLOCK;
	memory_area = preallocated_array;
	size = len;

	void *voidcon = &preallocated_array;
	unsigned long num_address = (unsigned long)voidcon;

	bool in_external_exec = (EXTERNAL_INS_START <= num_address) && (num_address <= EXTERNAL_INS_END);

	has_valid_memory = (len % 4 == 0) && (num_address % 4 == 0);
	has_valid_content = false;
	parent_file = "";
	if (has_valid_memory)
	{
		Serial.println("Invalid Memory");
		error = NO_ERROR;
	}
	else
	{
		error = DEFAULT_ERROR;
	}
}

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
// Section set block, then you can run
/* The only time the memory manager should be loading memory is if the block was preallocated.
static Section  Section::load_main_block_section(void *location, size_t this_block_size)
{
	Section temp Section("", BLOCK_SECTION);
	memory_area = location;
	size = this_block_size;
}
*/
// The only time you can initialize a section from an array is when you're setting up the main execblock

// The only time you can directly change the memory address of a section is when you have multiple preallocated blocks.
Section::change_main_block(unsigned long allocated_array, size_t array_size)
{
	memory_area = allocated_array;
	size = array_size;
	if (section_type == MAIN_EXEC_BLOCK)
	{

		is_valid = false;
		return 0;
	}
	return -1;
}
// Create a section of a different type from an existing section
//  Section::Section(Section parent, int type);
//  or Section::create_child_copy(int_type){ // copy the file section over to the correct memory type }
Section::fill_main_block(void *target)
{
	// void *target = main_block_section->memory_area;
	//  memcpy(target, memory_area, size);
	block_wise_memcopy(target, memory_area, size);
	/*
	if ((section_type == EXEC_INTERNAL) || (section_type == HEAP_INTERNAL))
	{

	}
	*/
}
Section::Section(unsigned long arr[], size_t my_size)
{
	section_type = MAIN_EXEC_BLOCK;
	unsigned long *p;
	unsigned long balance[4] = {0, 1, 1, 2};

	p = &balance[0];
	// memory_area = (void *)arr; // Error is here
	int a = 0;
	int *c = &a;
	void *t = (void *)p;
	// void *
	remove_me = p;
	// this->memory_area = malloc(16);
	// this->memory_area = (void *)remove_me;
	memory_area = (void *)arr;
	size = my_size;
	is_valid = false;
	parent_file = "";
}

Section::Section(void *e, size_t my_size)
{
	section_type = MAIN_EXEC_BLOCK;
	unsigned long *p;
	unsigned long balance[4] = {0, 1, 1, 2};

	p = &balance[0];
	// memory_area = (void *)arr; // Error is here
	int a = 0;
	int *c = &a;
	void *t = (void *)p;
	// void *
	// remove_me = e;
	t = malloc(16);
	// t = remove_me;
	memory_area = e;

	size = my_size;
	is_valid = false;
	parent_file = "";
}
Section::set_ptr(void *a)
{
	memory_area = a;
}
Section::set_ptr(unsigned long a)
{

	//	this->memory_area = (void *)a;
}

// get main block pointer
Section::Section(String file_name, int type)
{ /*
   * You can use the initializer to ensure that everything is valid to prevent the
   * the creation of dangerous undefined sections
   * You can't create a section with an invalid filename if you're making an executable or data section
   */

	parent_file = file_name;
	section_type = type;
	if (type == BLOCK_SECTION)
	{
		memory_area = get_valid_memory(512, EXEC_INTERNAL);
		is_valid = false;
		size = 512;
		parent_file = "";
		return;
	}
	if (type == MAIN_EXEC_BLOCK)
	{
		// main_block_section = this;
		parent_file = "";
		// this needs to be freed after reassignement
		memory_area = get_valid_memory(4, EXEC_INTERNAL);
		size = 0;
		// memory_area;
		section_type = MAIN_EXEC_BLOCK;
		is_valid = false;
		return;
	}
	if (type == FILE_SECTION)
	{
		memory_area = nullptr;
		section_type = FILE_SECTION;
		parent_file = file_name;
		size = getFileSize_long(file_name); //
		// Hopefully:
		has_valid_content = true;
		has_valid_memory = false;
	}

	long file_size = getFileSize_long(file_name);
	// Do checking etc.
	size = modulo_smooth((size_t)file_size);
	if (type == FILE_SECTION)
	{
		// no memory needs to be allocated if the section is a file.
		// Since the size is a division of 4 this way, I think its
		// safe to just let the size be the modulo 4 and assume that thd
		// other section definitions will fall in line properly.
		is_valid = true;
		return;
	}
	// void *temp_store = heap_caps_malloc(size, MALLOC_CAP_DMA);
	// int mem_size = size;
	// load_from_file(file_name, mem_size, temp_store);

	memory_area = get_valid_memory(size, type);

	switch (type)
	{
	case HEAP_INTERNAL:
		block_wise_file_copy(memory_area, file_name, size);
		break;
		// In the block init get_valid memory isn't needed
		//	case BLOCK_SECTION:
		//		break;
	case EXEC_INTERNAL:
		// memory_area = get_valid_memory(size, type);
		//  void *load_from_file(String file_name, int &size);
		//  Switch these two lines in and out with comments to compare the files loads
		block_wise_file_copy(memory_area, file_name, size);
		// block_wise_memcopy(memory_area, temp_store, size);

		// heap_caps_free(temp_store);
	}

	// do more checks...

	// section_type = type;
	is_valid = true;
}
Section::~Section()
{
	// need to check if memory area is actually a nullptr;
	if (memory_area != NULL && (section_type != MAIN_EXEC_BLOCK))
	{
		heap_caps_free(memory_area);
	}
}
size_t Section::block_wise_memcopy(void *dest, void *source, size_t source_size)
{
	size_t remainder = source_size;
	size_t cur_address = 0;
	size_t page_size = 256;
	size_t num_pages = 4;
	size_t temp_block_size = page_size * num_pages;
	void *temp_store = heap_caps_malloc(temp_block_size, MALLOC_CAP_32BIT);
	while (remainder > temp_block_size)
	{
		memcpy(temp_store, source + cur_address, temp_block_size);
		memcpy(dest + cur_address, temp_store, temp_block_size);
		// memcpy(dest + cur_address, source + cur_address, temp_block_size);
		cur_address = cur_address + temp_block_size;
		remainder = remainder - temp_block_size;
	}
	if (remainder > 0)
	{

		memcpy(temp_store, source + cur_address, remainder);
		memcpy(dest + cur_address, temp_store, remainder);
		// memcpy(dest + cur_address, source + cur_address, remainder);
		cur_address = cur_address + remainder;
	}
	heap_caps_free(temp_store);
	return cur_address;
}
void *Section::load_from_file(String file_name, int &memory_size, void *to_fill)
{
	FILE *ptr;
	/// const char* real_file_name = "/spiffs" + file_name;
	int length_file;
	ptr = fopen(file_name.c_str(), "r");
	if (ptr == NULL)
	{
		return ptr;
	}
	fseek(ptr, 0, SEEK_END);
	length_file = ftell(ptr);
	fseek(ptr, 0, SEEK_SET);
	// length_file = getFileSize(ptr);
	// int size_of_allocated_memory = 0; // Be filled by reference in get_valid_heap_memory

	// void *allocated_heap_memory;
	//  heap_caps_malloc(real_size, MALLOC_CAP_DMA);
	// allocated_heap_memory = get_valid_heap_memory(length_file, size_of_allocated_memory);
	fread(to_fill, 1, memory_size, ptr);
	fclose(ptr);
	// memory_size = size_of_allocated_memory;
	return to_fill;
}

size_t Section::block_wise_file_copy(void *dest, String file_name, size_t source_size)
{
	// Future self: If this naming convention was a horrible idea, I'm sorry...ish
	FILE *ptr;
	ptr = fopen(file_name.c_str(), "r");
	size_t remainder = source_size;
	size_t cur_address = 0;
	size_t page_size = 256;
	size_t num_pages = 4;
	size_t temp_block_size = page_size * num_pages;
	void *temp_store = heap_caps_malloc(temp_block_size, MALLOC_CAP_DMA);
	while (remainder > temp_block_size)
	{
		fread(temp_store, 1, temp_block_size, ptr);
		// memcpy(temp_store,source+cur_address, temp_block_size);
		memcpy(dest + cur_address, temp_store, temp_block_size);

		memcpy(dest + cur_address, temp_store, temp_block_size);
		cur_address = cur_address + temp_block_size;
		remainder = remainder - temp_block_size;
	}
	if (remainder > 0)
	{
		fread(temp_store, 1, remainder, ptr);
		memcpy(dest + cur_address, temp_store, remainder);
		cur_address = cur_address + remainder;
		//	memcpy(dest+cur_address, temp_store, remainder);
	}
	heap_caps_free(temp_store);

	/// const char* real_file_name = "/spiffs" + file_name;
	// int length_file;
	/*
		if (ptr == NULL)
		{
			return ptr;
		}
		fseek(ptr, 0, SEEK_END);
		length_file = ftell(ptr);
		fseek(ptr, 0, SEEK_SET);
	*/
	// length_file = getFileSize(ptr);
	// int size_of_allocated_memory = 0; // Be filled by reference in get_valid_heap_memory

	// void *allocated_heap_memory;
	//  heap_caps_malloc(real_size, MALLOC_CAP_DMA);
	// allocated_heap_memory = get_valid_heap_memory(length_file, size_of_allocated_memory);
	fclose(ptr);
	return cur_address;
}