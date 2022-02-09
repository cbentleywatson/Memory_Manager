#include <Arduino.h>
#include <string.h>
#include "SPIFFS.h"

// Probably need an additional header for common function type defs. i.e. int foo(void), int bar(int a, int b) and so on
//
//#include "esp-elf.h"
//#include "FreeRTOS.h"

#include <esp_heap_caps.h>
//#include "c_header.h"

//#include "elf.h" // this one needs to be deleted

// The exact type of the offsets is 16 bit but the

// #define FILE_NOT_FOUND -1
// # define FILE_FOUND_NO_FUNC -2

void *file_to_heap_pure_fstructs(String file_name);
// This function gives the full contents

void *exec_from_spiffs(String file_name);
void *mv_func_ptr(void *initial_function_ptr, void *function_ptr_to_copy, int length_of_new_function);
void *mv_to_address(void *initial_function_ptr, unsigned long address, int length_of_new_function);

void *long_to_void_ptr(unsigned long input_long);
void *func_load_with_long(unsigned long source, int length);

// void* func_load_with_long(unsigned long source, int length);
void *func_load_with_void_ptr(void *source, int length);

// these weren't finished; can probably be replaced by swap_ptr
unsigned long swap(unsigned long a, unsigned long b);

// When malloc is used to create space for a function a void * is created
// that void * can't be used to call a function and it can't be assigned equal to a function pointer without
// an explicit cast unless f-permissive is set. This function gets areound that by moving the
// ptr redefinition into a library compiled with f-permissive, which does allow those reassignments.
void swap_ptr(void *a, void *b);
// swap whould be easy to implement actually if void* is used

void *exec_ptr();

// Not tested:
// Moves a string (i.e. the function) in a file given by file name
// If the file exists, it's destroyed and the new string is put there
int funct_to_file(void *funct_ptr, String file_name, size_t length);

// It may be better to treat these functions as if they're moving around

// Not Tested:
// This would move something from file into a void * in main ram.
void *file_to_heap(String file_name, size_t offset, size_t length);

// move the entire file to the heap; this hasn't been tested at all
void *file_to_heap(String file_name);
void *file_to_exec(String file_name, size_t offset, size_t length);
void *file_to_exec(String file_name, size_t sec_offset, size_t offset_from_sec_start, size_t length);
//  exec from file would then be:
//  file_to_heap, func_load_with_void_ptr, then free memory from file to heap, then exec new code

void *file_sec_to_heap(String file_name, size_t sec_offset, size_t offset_from_sec_start, size_t length);

// This function grabs the elf header from an elf file.
// elf_header *ld_elf_header(String file_name);

// find and load the file/function then take the function pointer given and swap it in
// execution would require making a pointer to the correct type of function, then swapping,
// and then calling the original function pointer
// return is for error codes.
// int MM.full_ld(string file_name, string function name, void * &function);

// These are ideas for setting up functions for relocation. These probably require an actual elf object to work
// because they would work best with stored values for the location of the data and text sections in memory via this.

// To get data from the relocation table:
// Probably requires creating a vector of relocation entry pointers
// int ld_relocation_data

// Using the relocation table's offset and section name data, update the values listed.
// int update_vals()

// Write the data from loading back into files in a way that reduces space or requires less work to be done next time the function is called.
// potentially this could also be done in the setup code in some way.
// int MM.write_back

// check if a given adress is in the range 4xxx_xxxx which is instruction address space.
// bool check_for_legal_address_exec(void* address)

// KEY: This one is designed to move things to external flash/ ram and execute from there

// mv_ptr_external()
int modulo_smooth(int n);
class Memory_Manager
{
	int default_val = 1;
	int (*int_int_fp_plain)(int);
	int (*int_int_fp_copied_to_exec)(int);
	int (*int_int_fp_copied_from_file)(int);
	void *exec_ram_memory_block;

public:
	int return_zero(int input);
	// int return_zero(int input);
	unsigned long get_valid_exec_memory(size_t size, void *my_pointer)
	{
		/* this function is designed to get piece of exec memory with the correct size and alignment for running functions
		 * These pieces of memory need to have 4 byte alignment, and sizes need to be a multiple of four. If they're not and you try to copy the whole thing, you'll break the requiremnt
		 * that all exec memory accesses need to be four byte aligned, resulting in a load store error when using memcopy.
		 */

		unsigned long real_size = modulo_smooth(size);
		my_pointer = heap_caps_malloc(real_size, MALLOC_CAP_EXEC);
		return real_size;
	}
	unsigned long get_valid_heap_memory(int arg_size, void *my_pointer)
	{
		/* this function is designed to get piece of heap memory with the correct size and alignment for running functions
		 * These pieces of memory need to have 4 byte alignment, and sizes need to be a multiple of four. If they're not and you try to copy the whole thing, you'll break the requiremnt
		 * that all exec memory accesses need to be four byte aligned, resulting in a load store error when using memcopy.
		 */
		unsigned long real_size = modulo_smooth(arg_size);
		my_pointer = heap_caps_malloc(real_size, MALLOC_CAP_EXEC);
		return real_size;
	}

	int return_one(int input)
	{
		return 1;
	}

	int return_fp_plain(int input)
	{
		return int_int_fp_plain(input);
	}
	int return_fp_copied_to_exec(int input)
	{
		return int_int_fp_copied_to_exec(input) + 1;
	}
	int return_fp_copied_from_file(int input)
	{
		return int_int_fp_copied_from_file(input);
	}
	// There need to be init functions
	void init_fp_plain(int (*int_int_fp_plain_pass)(int))
	{
		int_int_fp_plain = int_int_fp_plain_pass;
	}
	void init_fp_copied_to_exec();
	/*
	 void init_fp_copied_to_exec()
	{
		int_int_fp_copied_to_exec = func_load_with_void_ptr((void *)int_int_fp_plain, 200);
	}
	*/
	void init_fp_copied_from_file()
	{
		void *function_contents = malloc(200);
		memcpy(function_contents, (void *)int_int_fp_plain, 200);

		FILE *ptr;
		ptr = fopen("/spiffs/t2", "wb");
		fwrite(function_contents, 200, 1, ptr);
		fclose(ptr);

		void *contents_from_file = malloc(200);
		size_t block_size;
		void *exec_ram_function;
		// get_valid_exec_memory(block_size, exec_ram_function); //
		exec_ram_function = heap_caps_malloc(200, MALLOC_CAP_EXEC);
		ptr = fopen("/spiffs/t2", "r");
		fread(contents_from_file, 1, 200, ptr);
		fclose(ptr);
		memcpy(exec_ram_function, contents_from_file, 200);
		// funct_to_file(int_int_fp_plain, "/testheap", 200);
		int_int_fp_copied_from_file = exec_ram_function;
	}
	void init_fp_copied_with_spiff_func(String file_name);

	int init_memory_block();

	int fill_memory_block(String file_name)
	{
		//
		// Get file contents onto the heap

		int length = getFileSize(file_name); // This can probably go later, this is just a quck and
		int array_length = modulo_smooth(length);
		if (length <= 0)
		{
			// File No Found Errors
			Serial.print("file_name:");
			Serial.println("File Not Found!!!");
			return -1;
		}
		Serial.print("File Name: ");
		Serial.println(file_name);
		Serial.print("File Size: ");
		Serial.println(length);
		Serial.print("Array Length: ");
		Serial.println(array_length);

		void *file_contents = NULL;
		file_contents = file_to_heap_pure_fstructs(file_name);

		// move the stuff from the heap onto the preallocated memory block area, free the heap memory
		memcpy(exec_ram_memory_block, (void *)file_contents, array_length);
		int_int_fp_copied_from_file = exec_ram_memory_block;
		free(file_contents);
		// Move the function point to to point to the block, return success or emit an error.

		return 0;
	}

	int set_block_pointer_via_array(unsigned long allocated_array)
	{
		exec_ram_memory_block = (void *)allocated_array;
		// return zero if no error
		return 0;
	}
	int getFileSize(String file_name);
};