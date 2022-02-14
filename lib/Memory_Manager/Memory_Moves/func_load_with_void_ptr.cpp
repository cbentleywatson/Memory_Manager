#include "../Memory_Manager.h"

// take an unsigned long that denotes a pointer
// convert it into a pointer
// allocate memory and copy data from the memory position specified by the long


void *Memory_Manager::func_load_with_void_ptr(void *source, int length_of_new_function)
{
  void *temp_ptr = heap_caps_malloc(length_of_new_function, MALLOC_CAP_EXEC);

  memcpy(temp_ptr, source, length_of_new_function);
  return temp_ptr;
}

