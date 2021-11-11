#include <Arduino.h>
#include "Memory_Manager.h"
#include <SPIFFS.h>
#include <FreeRTOS.h>
#include <iostream>
#include <stddef.h>
#include "simple_lib_d.h"
//extern "C" void* mv_func_ptr(void* initial_function_ptr, void* function_ptr_to_copy, int length_of_new_function);
//extern "C" void* mv_to_address(void* initial_function_ptr, unsigned long address, int length_of_new_function);
//#include <Serial.h>
typedef int (*fn_def)(void);
int my_int_func(int x);
int int_void();
int int_void6();
int my_int_func(int x){
  return 5;
}
int int_void(){
  return 5;
}
int int_void_6(){
  return 6;
} 
int int_void_88(){
  return 88;
} 

int int_void_21(){
  return 21;
}  
int simple_int(int a){
  return a;
}  


void int_void_6(int x){
  ;;
}  

int (*mem_func)();
void setup() {
   Serial.begin(9600);
  SPIFFS.begin();
}
unsigned long a = 0;
 unsigned long* a_address;
 unsigned long** ptr_from_address;
 unsigned long location_of_a_address;
 void* adress_address_void;
 unsigned long* a_address_as_long_ptr;
void loop() {
  a_address =  &a;
  ptr_from_address = &a_address;
  adress_address_void = (void*) ptr_from_address;
  a_address_as_long_ptr = (unsigned long*) adress_address_void;

  
  Serial.print("a adress as long: ");
  Serial.println(*a_address_as_long_ptr);
  Serial.println("\n\n");
  int p_header_size;
  int s_header_size;
  int start_of_section_header;
  int start_of_program_header;
  //char* file_contents = (char* ) malloc(file_size);
  //simple_lib.read(file_contents, file_size);

  // this can be used for any type but it requires specific casts to work.
  //void (*gen)(void);
  // void * cube(void*)// take any object and return any object.  
  //int (*foo)(){&int_void};
int (*void_6)(){&int_void_6};
int (*void_88)(){&int_void_88};
  //int (*mem_func)(){&int_void_6};
 int (*void_21)(){&int_void_21};
// int a = &simple_funct;
 Serial.print(" Initial value of void 6: ");
Serial.println(void_6());
//boo = &my_int_func;
Serial.print("\n\n");
delay(2000);
Serial.print(" Void 6 after mv_func_ptr attempts to copy over void 21: ");
void *f6;

//*f6 =(void *) void_6; 
//void *funct_6_as_void = (void *) void_6;
void_6 = (int (*)()) mv_func_ptr( (void *) void_6, (void *) void_21, 100);
Serial.println(void_6());
//Serial.print(void_6());
delay(2000);

Serial.print("\n\n\nAttempting to use mv_to address to move pointer to void_88 ");
void_6 = (int (*)()) mv_to_address((void *) void_6, (unsigned long) void_88 ,100);
Serial.print("void_6 ptr after mv_to_address: ");
Serial.println(void_6());
delay(3000);












}