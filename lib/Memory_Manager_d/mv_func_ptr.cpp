#include "Memory_Manager.h"
//copy
// takes a pointer and moves it to any address
// in main the pointer type hasn't changed;
// void* a = function pointer




void* mv_func_ptr(void* initial_function_ptr, void* function_ptr_to_copy, int length_of_new_function){
  void* temp_ptr =  heap_caps_malloc(length_of_new_function,MALLOC_CAP_EXEC);
  void* prior_func_position =initial_function_ptr;
  //void* original_ptr_location = initial_function_ptr;
  // temp ptr 1 of type ?? 
  memcpy(temp_ptr, function_ptr_to_copy , length_of_new_function);
  void* temp2 =  heap_caps_malloc(300,MALLOC_CAP_EXEC);
  initial_function_ptr =temp_ptr;
  //heap_caps_free(temp_ptr);
  return temp_ptr;
  // void * to memory = address 
}  
