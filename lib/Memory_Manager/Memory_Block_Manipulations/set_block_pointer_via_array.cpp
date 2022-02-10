#include "../Memory_Manager.h"
int Memory_Manager::set_block_pointer_via_array(unsigned long allocated_array)
{
	exec_ram_memory_block = allocated_array;
	//  return zero if no error
	return 0;
}