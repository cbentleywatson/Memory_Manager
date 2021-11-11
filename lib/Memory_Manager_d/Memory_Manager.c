//#include <Arduino.h>
//#include "SPIFFS.h"
//#include "FreeRTOS.h"
#include "Memory_Manager.h"
#include <esp_heap_caps.h>

//File file = SPIFFS.open("/test.txt", FILE_WRITE);
//file.close();

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
  heap_caps_free(temp_ptr);
  return prior_func_position;
  // void * to memory = address 
}  

void* mv_to_address(void* initial_function_ptr, unsigned long address, int length_of_new_function){
  unsigned long add_dummy = 0;
  unsigned long dummy =0;
  void* direct = add_dummy;
  void* direct_2 = add_dummy;
  void* a =  add_dummy;

  void **b = &a;
  void *c = (void*) dummy; // no warning on this one
  

  void* temp_ptr =  heap_caps_malloc(length_of_new_function,MALLOC_CAP_EXEC);
  void* prior_func_position =initial_function_ptr;
  //void* original_ptr_location = initial_function_ptr;
  // temp ptr 1 of type ?? 
  memcpy(temp_ptr, c, length_of_new_function);
  //void* temp2 =  heap_caps_malloc(300,MALLOC_CAP_EXEC);
  //initial_function_ptr =temp_ptr;
  heap_caps_free(temp_ptr);
  return prior_func_position;
  // void * to memory = address 
} 



// call function after the move as normal 
// void force_move_without ()

