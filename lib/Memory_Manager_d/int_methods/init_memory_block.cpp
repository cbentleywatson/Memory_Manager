#include "../Memory_Manager.h"
Memory_Manager::init_memory_block()
{
	int size = 1024;
	exec_ram_memory_block = heap_caps_malloc(size, MALLOC_CAP_EXEC);
	// If there's an error return 1, but that's not setup
	return 0;
}