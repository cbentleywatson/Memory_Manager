
#include "Memory_Manager.h"

/*
Memory_Manager::Memory_Manager()
{
  int_int_fp_plain = &return_one;
  int_int_fp_copied_to_exec = &return_one;
  int_int_fp_copied_from_file = &return_one;
}
*/
// File file = SPIFFS.open("/test.txt", FILE_WRITE);
// file.close();

// BROKEN:
/*
DMA_ATTR uint8_t buffer[]="I want to send something";

void app_main()
{
   // initialization code...
   spi_transaction_t temp = {
       .tx_buffer = buffer,
       .length = 8 * sizeof(buffer),
   };
   spi_device_transmit(spi, &temp);
   // other stuff
}
void app_main()
{
   DMA_ATTR static uint8_t buffer[] = "I want to send something";
   // initialization code...
   spi_transaction_t temp = {
       .tx_buffer = buffer,
       .length = 8 * sizeof(buffer),
   };
   spi_device_transmit(spi, &temp);
   // other stuff
}
*/

/*
 //SPIFFS.exists("file_name"); returns true if file exists
int func_to_file(void* funct_ptr, File file  , size_t length ){
  ///File file = SPIFFS.open(filename, FILE_WRITE);
  //size_t write(const uint8_t *buf, size_t size) override;
  file.write(funct_ptr, length);
}
//
    //size_t readBytes(char *buffer, size_t length)
    //{
    //    return read((uint8_t*)buffer, length);
    //}

    SeekSet // position offset x bytes from the start of the file
    //SeekCur // the current position is  moved by x bytes
    // SeekEnd the // the position is moved n bytes from the end of the file
  if (!SPIFFS.exists(filename)){ then call the  }
void * file_to_funct(  size_t length, String filename){


  //void* return_buf = new
  char* buff = (char *)malloc(length*sizeof(char));
  file.readBytes(buff, length);

  return (void *) buff;
}


*/

// Make exec null ptr function
/*
void* exec_ptr(){
  //void* returnval;
  //void* return_val2;
  unsigned long* a =(unsigned long) heap_caps_malloc(4,MALLOC_CAP_EXEC);
  unsigned long z = *a;
  void* finished = long_to_void_ptr(z);
  return finished;
}
*/
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
/*
unsigned long swap(unsigned long a, unsigned long b)
{
  unsigned long a1 = a;
  unsigned long b1 = b;
  unsigned long temp = a1;

  b1 = temp;
  memcpy(long_to_void_ptr(a1), long_to_void_ptr(b1), 4);
  memcpy(long_to_void_ptr(b1), long_to_void_ptr(temp), 4);
  return b1;
}
*/

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

// call function after the move as normal
// void force_move_without ()
