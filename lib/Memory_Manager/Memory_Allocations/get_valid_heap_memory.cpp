#include "../Memory_Manager.h"
unsigned long Memory_Manager::get_valid_heap_memory(int arg_size, void *my_pointer)
{
	/* this function is designed to get piece of heap memory with the correct size and alignment for running functions
	 * These pieces of memory need to have 4 byte alignment, and sizes need to be a multiple of four. If they're not and you try to copy the whole thing, you'll break the requiremnt
	 * that all exec memory accesses need to be four byte aligned, resulting in a load store error when using memcopy.
	 */
	unsigned long real_size = modulo_smooth(arg_size);
	my_pointer = heap_caps_malloc(real_size, MALLOC_CAP_EXEC);
	return real_size;
}