#include "Memory_Manager.h"
void* mv_to_address(void* initial_function_ptr, unsigned long address, int length_of_new_function){
  unsigned long add_dummy = 0;
  unsigned long dummy =0;
  void* direct = (void *) add_dummy;
  void* direct_2 = add_dummy;
  void* a =  add_dummy;

  void **b = &a;
  void *c = (void*) address; // no warning on this one
  void* temp_ptr =  heap_caps_malloc(length_of_new_function,MALLOC_CAP_EXEC);
  void* prior_func_position =initial_function_ptr;
  //void* original_ptr_location = initial_function_ptr;
  // temp ptr 1 of type ?? 
  memcpy(temp_ptr, c, length_of_new_function);
  //void* temp2 =  heap_caps_malloc(300,MALLOC_CAP_EXEC);
  //initial_function_ptr =temp_ptr;
  //heap_caps_free(temp_ptr);
  return temp_ptr;
  // void * to memory = address 
} 
