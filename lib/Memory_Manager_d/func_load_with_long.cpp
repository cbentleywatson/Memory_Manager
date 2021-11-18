#include "Memory_Manager.h"
void* func_load_with_long(unsigned long source, int length_of_new_function){
  void* temp_ptr =  heap_caps_malloc(length_of_new_function,MALLOC_CAP_EXEC);  
  memcpy(temp_ptr, long_to_void_ptr(source), length_of_new_function);
  return temp_ptr;
}
