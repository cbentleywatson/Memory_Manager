#include "elf.h"
void* mv_func_ptr(void* initial_function_ptr, void* function_ptr_to_copy, int length_of_new_function);
void* mv_to_address(void* initial_function_ptr, unsigned long address, int length_of_new_function);