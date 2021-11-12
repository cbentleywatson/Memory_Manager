#include <Arduino.h>
#include <string.h>
//#include "SPIFFS.h"
//#include "FreeRTOS.h"
//#include "Memory_Manager.h"
#include <esp_heap_caps.h>
#include "c_header.h"
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
  //heap_caps_free(temp_ptr);
  return temp_ptr;
  // void * to memory = address 
}  

void* mv_to_address(void* initial_function_ptr, unsigned long address, int length_of_new_function){
  unsigned long add_dummy = 0;
  unsigned long dummy =0;
  void* direct = add_dummy;
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
void* long_to_void_ptr(unsigned long input_long){
  unsigned long *a; // make a pointer pointing at a, using the correct pointer type
  a = (void* )input_long;  // assign the pointer to the correct value
  void *b;          // create a void* to return
  b = (void *) a;   // type cast the unsigned long ptr to a void*
  return b;         // return the  
}

unsigned long void_ptr_to_long(void* input){
  //unsigned long return;
  return (unsigned long) input; // the  
} 
// Make exec null ptr function

void* exec_ptr(){
  //void* returnval;
  //void* return_val2;
  unsigned long* a =(unsigned long) heap_caps_malloc(4,MALLOC_CAP_EXEC);
  unsigned long z = *a;
  void* finished = long_to_void_ptr(z);
  return finished;
}
/*
unsigned long swap (unsigned long a, unsigned long b){
  unsigned long a1 =a;
  unsigned long b1 = b;
  unsigned long temp = a1;
  void* to_f1 =   heap_caps_malloc(4,MALLOC_CAP_EXEC);
  void* to_f2 =   heap_caps_malloc(4,MALLOC_CAP_EXEC);
  void* to_original_a = long_to_void_ptr(a1);
  void* to_original_b = long_to_void_ptr(b1);
  *to_f1 = *to_original_a;
  *to_f2 = *to_original_b;

  to_f1* =long_to_void_ptr(a1);
  to_f2* = long_to_void_ptr(b1)
  b1 = temp;
  memcpy(long_to_void_ptr(a1), long_to_void_ptr(b1), 4  );

  memcpy(long_to_void_ptr(b1), long_to_void_ptr(temp), 4 );
  return b1;
 }
*/
/*
void swap (void* a, void* b){
  void *to_func = 
  unsigned long a1 =a;
  unsigned long b1 = b;
  unsigned long temp = a1;
  
  b1 = temp;
  memcpy(long_to_void_ptr(a1), long_to_void_ptr(b1), 4  );

  memcpy(long_to_void_ptr(b1), long_to_void_ptr(temp), 4 );
  return b1;
 }*/






unsigned long swap (unsigned long a, unsigned long b){
  unsigned long a1 =a;
  unsigned long b1 = b;
  unsigned long temp = a1;
  
  b1 = temp;
  memcpy(long_to_void_ptr(a1), long_to_void_ptr(b1), 4  );
  memcpy(long_to_void_ptr(b1), long_to_void_ptr(temp), 4 );
  return b1;
 }




/*
  // Swap can move a function pointer around with no changes to function types and no casts at all
 

  example:
  swap(  void_to_long((void *) argq ) arg1,  void_to_long(void *  ))){
  unsigned long = temp;
  temp =a;
  long_to_void(a) = long_to_voi(b);  = orgiginval value of a
  long_to_voi(b)=long_to_void( temp);
  // return original f location     
}
  use:
  f(args); // run normal version
  original_position = swap(f, new);
  f(args) // run new
  swap(f, temp)
  f(args); // now the original version runs
  // no type casting occurs between the value returned and the original



*/


 // take an unsigned long that denotes a pointer
 // convert it into a pointer
 // allocate memory and copy data from the memory position specified by the long
void* func_load_with_long(unsigned long source, int length_of_new_function){
  void* temp_ptr =  heap_caps_malloc(length_of_new_function,MALLOC_CAP_EXEC);  
  memcpy(temp_ptr, long_to_void_ptr(source), length_of_new_function);
  return temp_ptr;
}

void* func_load_with_void_ptr(void* source, int length_of_new_function){
  void* temp_ptr =  heap_caps_malloc(length_of_new_function, MALLOC_CAP_EXEC);  
  memcpy(temp_ptr, source, length_of_new_function);
  return temp_ptr;
}

// call function after the move as normal 
// void force_move_without ()

