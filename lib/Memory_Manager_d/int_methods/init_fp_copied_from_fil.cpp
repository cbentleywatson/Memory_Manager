#include "../Memory_Manager.h"
// Not totally clear on how to deal with this one
// Might be best to make it an actual memory manager function
/*
void *func_load_with_void_ptr(void *source, int length_of_new_function)
{
	void *temp_ptr = heap_caps_malloc(length_of_new_function, MALLOC_CAP_EXEC);
	memcpy(temp_ptr, source, length_of_new_function);
	return temp_ptr;
}
*/
void Memory_Manager::init_fp_copied_to_exec()
{
	int_int_fp_copied_to_exec = func_load_with_void_ptr((void *)int_int_fp_plain, 200);
}