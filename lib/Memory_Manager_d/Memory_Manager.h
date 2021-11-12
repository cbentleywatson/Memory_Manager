#include "elf.h"
void* mv_func_ptr(void* initial_function_ptr, void* function_ptr_to_copy, int length_of_new_function);
void* mv_to_address(void* initial_function_ptr, unsigned long address, int length_of_new_function);
unsigned long void_ptr_to_long(void* input);
void* long_to_void_ptr(unsigned long input_long);
void* func_load_with_long(unsigned long source, int length);

//void* func_load_with_long(unsigned long source, int length);
void* func_load_with_void_ptr(void* source, int length);
unsigned long swap (unsigned long a, unsigned long b);
void* exec_ptr();