#include <Arduino.h>
#include "Memory_Manager.h"
#include <SPIFFS.h>
#include <FreeRTOS.h>
#include <iostream>
#include <stddef.h>
#include "simple_aa.h"
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
 // SPIFFS.begin();
  if(!SPIFFS.begin(true)){
      Serial.println("An Error has occurred while mounting SPIFFS");
      return;
}

}
unsigned long a = 0;
 unsigned long* a_address;
 unsigned long** ptr_from_address;
 unsigned long location_of_a_address;
 void* adress_address_void;
 unsigned long* a_address_as_long_ptr;

int loop_count =0;

void loop() {
  //simple_funct(101);
  simple_int_aa =11;
  a_address =  &a;
  ptr_from_address = &a_address;
  adress_address_void = (void*) ptr_from_address;
  a_address_as_long_ptr = (unsigned long*) adress_address_void;
  unsigned long test =1000;
  unsigned long* my_long = &test;
  unsigned long z= void_ptr_to_long((void *) my_long  );
  Serial.print(String((long) z, HEX));
Serial.print("Double pointer zs before swap: ");
//Serial.print(*v());
Serial.println("\n\n");
delay(3000);
unsigned long ll =239;
unsigned long* zs =&ll; 
//Serial.print((unsigned long ) &zs);

if (loop_count==0){
  //memcpy(temp_ptr, function_ptr_to_copy , length_of_new_function);
  File file = SPIFFS.open("/saved_funct", FILE_WRITE);
  //200 is a place holder for length values
  if (!file){
    Serial.println("Failed to open file for reading.");
  }
  int (*void_6_file)(){&int_void_6};
  void* temp_ptr =  heap_caps_malloc(200, MALLOC_CAP_DMA);
  memcpy(temp_ptr, void_6_file, 200);
  file.write((const uint8_t *) temp_ptr ,200);
  free(temp_ptr);
  file.close();
  //write(const uint8_t *buf, size_t size)
  loop_count++;
}else{
  File file = SPIFFS.open("/saved_funct", FILE_READ);
  char* buff = (char *)heap_caps_malloc( 200, MALLOC_CAP_DMA);
  file.readBytes(buff, 200);
  void* temp_ptr =  heap_caps_malloc(200,MALLOC_CAP_EXEC);
  memcpy(temp_ptr, (void *) buff , 200);
  int(*ptr_to_new)() =  (int (*)()) temp_ptr; 
  Serial.print("Void ptr_to_new's output after being read from file /saved_funct: ");
  Serial.println( ptr_to_new());
  free(buff);
  free(temp_ptr);
  file.close();





}
*zs = 13;
//swap(void_ptr_to_long(   (void *) *void_6)    ,  void_ptr_to_long((void *) *void_88 )  );
Serial.print("Void_6 after swap: ");
//Serial.print((unsigned long) &zs);
//Serial.println("\n\n");






//void* z = &
delay(3000);






  /*
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
//  int (*void_22)() = new (int (*)());
int (**v)();  //= new int (*void_22){&int_void_21};
int *pa = new int;
int **pb = new int*;
void *vs = (void *) pb;
v =&void_21;
//int (*)() *funcptr[];
//new int(*void_22)() 

//int (*)() (*funcptr[]) ={void_6, void_88, void_21} ;
//(int (*22)()) 

// int a = &simple_funct;
//int (**ptr_ptr)(){&void_6()};
// declare a pointer to the function pointer
//*ptr_ptr 

//int (*)()* fptest33 = new int()();


 Serial.print(" Initial value of void 6: ");
Serial.println(void_6());
//boo = &my_int_func;
Serial.print("\n\n");
delay(2000);
Serial.print(" Void 6 after mv_func_ptr attempts to copy over void 21: ");
void *fz;
fz =&a;
unsigned long ul =0;
unsigned long out =0;
ul = void_ptr_to_long(fz);

unsigned long dummy =200;
unsigned long dummy2 = 300;
void *dummy_ptr = &dummy;
dummy_ptr =  long_to_void_ptr (dummy2);



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

*/









}