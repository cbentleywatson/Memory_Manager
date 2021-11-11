#include <Arduino.h>
#include "Memory_Manager.h"
#include <SPIFFS.h>
#include <FreeRTOS.h>
#include <iostream>
#include <stddef.h>
#include "simple_lib_d.h"
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
int a =0;
 unsigned long a_address;
void loop() {
  a_address = (unsigned long) &a;

  Serial.print(a_address);
  Serial.print(" :a address: \n");
  
  int p_header_size;
  int s_header_size;
  int start_of_section_header;
  int start_of_program_header;
  //char* file_contents = (char* ) malloc(file_size);
  //simple_lib.read(file_contents, file_size);

  //memcpy(&file_header, file_contents, 52);
  //p_header_size = file_header.e_phnum*file_header.e_phentsize;
  //s_header_size = file_header.e_shnum *file_header.e_shentsize;
  //start_of_section_header =file_header.e_shoff;
  //start_of_program_header = file_header.e_phoff;

  // this can be used for any type but it requires specific casts to work.
  //void (*gen)(void);
  // void * cube(void*)// take any object and return any object.  
  //int (*foo)(){&int_void};
  int (*void_6)(){&int_void_6};
  //int (*mem_func)(){&int_void_6};
 int (*void_21)(){&int_void_21};
 int a = &simple_funct;
 Serial.print(" Define ");
  //boo = &my_int_func;
mv_func_ptr(void_6, void_21, 100);
//Serial.println(void_6());
Serial.print(void_6());
delay(2000);

 Serial.print("Gen pointer: ");
 //Serial.println(gen());
 Serial.println("\n\n");

Serial.print("Begininng direct address moves: ");
mv_to_address(void_6, (unsigned long) & ,100)












}