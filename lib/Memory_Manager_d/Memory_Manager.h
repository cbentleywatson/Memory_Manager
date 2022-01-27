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

void *mv_func_ptr(void *initial_function_ptr, void *function_ptr_to_copy, int length_of_new_function);
void *mv_to_address(void *initial_function_ptr, unsigned long address, int length_of_new_function);
unsigned long void_ptr_to_long(void *input);
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