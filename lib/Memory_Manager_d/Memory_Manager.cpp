#include <Arduino.h>
#include "SPIFFS.h"
#include "FreeRTOS.h"
#include "Memory_Manager.h"


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
  //void* temp2 =  heap_caps_malloc(300,MALLOC_CAP_EXEC);
  initial_function_ptr =temp_ptr;
  return prior_func_position;
  // void * to memory = address 
}  
// call function after the move as normal 
// void force_move_without ()

