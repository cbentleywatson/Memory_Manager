#include "../Memory_Manager.h"
void Memory_Manager::init_fp_copied_to_exec()
{
	int_int_fp_copied_to_exec = func_load_with_void_ptr((void *)int_int_fp_plain, 200);
}