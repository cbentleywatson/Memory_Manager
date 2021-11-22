#include <Arduino.h>
#include "Memory_Manager.h"
#include <SPIFFS.h>
#include <FreeRTOS.h>
#include <iostream>
#include <stddef.h>
#include "simple_aa.h"
#include "simple_lib_d.h"

// esp_spi_flash.h explains how
#include "esp_spi_flash.h"

// extern "C" void* mv_func_ptr(void* initial_function_ptr, void* function_ptr_to_copy, int length_of_new_function);
// extern "C" void* mv_to_address(void* initial_function_ptr, unsigned long address, int length_of_new_function);
//#include <Serial.h>
typedef int (*fn_def)(void);
int my_int_func(int x);
int int_void();
int int_void6();
int my_int_func(int x)
{
  return 5;
}
int int_void()
{
  return 5;
}
int int_void_6()
{
  return 6;
}
int int_void_88()
{
  return 88;
}

int int_void_21()
{
  return 21;
}
int simple_int(int a)
{
  return a;
}

void int_void_6(int x)
{
  ;
  ;
}

int (*mem_func)();
void setup()
{
  // esp_flash_t chip;
  Serial.begin(9600);
  // SPIFFS.begin();
  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  //  spi_bus_initialize()
}
unsigned long a = 0;
unsigned long *a_address;
unsigned long **ptr_from_address;
unsigned long location_of_a_address;
void *adress_address_void;
unsigned long *a_address_as_long_ptr;

int loop_count = 0;
int (*f_allocated)();
void loop()
{
  // config_SPI_RAM

  int (*void_88_flash)(){&int_void_88};

  // esp_err_t spi_flash_write(size_t dest_addr, const void *src, size_t size);
  void *external = heap_caps_malloc(1000, MALLOC_CAP_EXEC);
  void *dma_buffer = heap_caps_malloc(1000, MALLOC_CAP_DMA);
  // MALLOC_CAP_EXEC
  //
  memcpy(external, (const void *)void_88_flash, 300);
  memcpy(dma_buffer, (const void *)void_88_flash, 300);

  delay(10000);
  Serial.print("Free Exec Heap Size a: ");
  Serial.println(heap_caps_get_free_size(MALLOC_CAP_EXEC));
  int (*void_21_flash)(){&int_void_21};
  void_21_flash = (int (*)())external;
  Serial.print("void_21_flash after ld from flash: ");
  Serial.println(void_21_flash());

  int (*f_external)() = (int (*)())external;
  // spi_flash_write(x400C_2000, (const void *)void_88_flash, 300);
  Serial.print("external Address: ");
  Serial.println(void_ptr_to_long(external), HEX);
  // simple_funct(101);

  Serial.print("Printing directly from external: ");
  Serial.println(f_external());

  simple_int_aa = 11;
  a_address = &a;
  ptr_from_address = &a_address;
  adress_address_void = (void *)ptr_from_address;
  a_address_as_long_ptr = (unsigned long *)adress_address_void;
  unsigned long test = 1000;
  unsigned long *my_long = &test;
  unsigned long z = void_ptr_to_long((void *)my_long);
  Serial.println("\n");
  Serial.print(String((long)z, HEX));
  Serial.print("Double pointer zs before swap: ");
  // Serial.print(*v());
  Serial.println("\n\n");
  delay(3000);
  unsigned long ll = 239;
  unsigned long *zs = &ll;
  // Serial.print((unsigned long ) &zs);
  delay(10000);

  if (loop_count == 0)
  {

    // esp_err_t spi_flash_mmap(size_t src_addr, size_t size, spi_flash_mmap_memory_t memory,
    //   const void **out_ptr, spi_flash_mmap_handle_t *out_handle);

    // The enum spi_flash_mmap_memory_t has these two fields defined:
    // SPI_FLASH_MMAP_DATA, /**< map to data memory (Vaddr0), allows byte-aligned access, 4 MB total */
    // SPI_FLASH_MMAP_INST,
    // 0x400A 0000
    // Should Be working, but it's been commented out for a test

    int one_kb = 1024;

    const void **out_ptr;
    size_t size = 65536;
    spi_flash_mmap_memory_t memory_type = SPI_FLASH_MMAP_DATA;
    // points to the mapped memory region
    spi_flash_mmap_handle_t handle;
    spi_flash_mmap_handle_t *handle_t_ptr;
    handle_t_ptr = &handle;
    size_t src_address = 0x40080000;
    spi_flash_mmap(src_address, size, memory_type, out_ptr, handle_t_ptr);
    heap_caps_malloc_extmem_enable(25);
    //  while (true)
    //  {
    //    delay(1000);
    //  }
    Serial.println("/n/n Attempting mem copy");

    Serial.print("Free Exec Heap Size a: ");
    Serial.println(heap_caps_get_free_size(MALLOC_CAP_EXEC));
    while (true)
    {
      delay(250);
    }

    delay(1000);
    // SPI_FAS
    // int (*void_89_flash)(){&int_void_88};
    // memcpy(out_ptr, (const void *)void_89_flash, 1024);
    //   int (*void_21_flash)(){&int_void_21};
    //   void_21_flash = (int (*)())external;
    //   Serial.print("void_21_flash after ld from flash: ");
    //   Serial.println(void_21_flash());

    // f_allocated = (int (*)()) * out_ptr;

    delay(1000);

    loop_count++;
    // spi_flash_write(x400C_2000, (const void *)void_88_flash, 300);

    // simple_funct(101);

    /**
        // memcpy(temp_ptr, function_ptr_to_copy , length_of_new_function);
        File file = SPIFFS.open("/saved_funct", FILE_WRITE);

        //
        // 200 is a place holder for length values
        if (!file)
        {
          Serial.println("Failed to open file for reading.");
        }
        int (*void_6_file)(){&int_void_6};
        void *temp_ptr = heap_caps_malloc(200, MALLOC_CAP_DMA);
        memcpy(temp_ptr, void_6_file, 200);
        // Serial.println("temp ptr :", (uint32_t) temp_ptr );
        file.write((const uint8_t *)temp_ptr, 200);
        free(temp_ptr);
        file.close();
        // write(const uint8_t *buf, size_t size)
        loop_count++;
      }
      else
      {
        // int (*void_6_file)(){&int_void_6};
        // File file = SPIFFS.open("/ELF_Files/simple_lib_d", "r");
        //  file = SPIFFS.open("/saved_funct", FILE_READ);
        // char* buff = (char *)heap_caps_malloc( 200, MALLOC_CAP_DMA);
        // char* buff2 = (char *)heap_caps_malloc( 200, MALLOC_CAP_DMA);

        // file.seek(34,SeekSet);
        // Serial.print("\n Void 6 * : ");
        // Serial.print((unsigned long) void_6_file);
        //  works
        // file.readBytes(buff, 200);
        // void* temp_ptr = heap_caps_malloc(200,MALLOC_CAP_EXEC);
        //  char* entrance = buff+

        // void* mv_func_ptr(void* initial funct ptr, void* ptr to copy, int length);

        // need to move the
        // memcpy(buff2, buff[64] , (200-0x40 -4));

        // int start = 0x40;
        // int end =0x60;
        // char* to_loc = buff+ funct_offset;
        // Serial.println();

        // for (int i =0; (i + start)<end; i++){
        //   buff2[i] = buff[i+start];
        // }

        // unsigned long funct_offset = 0x34;
        // char* offset_3 = buff + 0x40;
        //  With funct offset =0x40, load store error reported instead of illegal instruction
        //  with the memcopy offset the error is labele "load prohibited"
        // void* target = buff + funct_offset;

        // load prohibited or load store
        // memcpy( (void*) temp_ptr, (void*) buff[funct_offset] , 200);
        // memcpy( (void*) temp_ptr, buff , 200);

        // memcpy( (void*) temp_ptr, (void*) buff2 , 30);
        /*
        char* agg =temp_ptr + funct_offset;
        Serial.println("\n");
        Serial.println(*agg);
        Serial.println("\n");
        void* temp2 = (void*) agg;
        int(*ptr_to_new)() =  (int (*)()) ( (void*) agg);
        */
    // char* temp_ptr_char = (char *) temp_ptr;
    // for (int i = offset)

    // void* temp2;
    // temp2  =(void *) temp_ptr;
    // int(*ptr_to_new)() =  (int (*)()) ( temp_ptr);
    // Serial.print("Void ptr_to_new's output after being read from file /saved_funct: ");
    // Serial.println( ptr_to_new());
    // free(buff);
    // free(temp_ptr);
    // file.close();
  }
  /// void *external = heap_caps_malloc(1000, EXTERNAL || MALLOC_CAP_EXEC);
  //
  Serial.print("Flash out_ptr address: ");
  delay(1000);
  // Serial.println(void_ptr_to_long(*out_ptr), HEX);
  //  Serial.print("Printing from External flash region ");
  //  Serial.println(f_external());

  *zs = 13;
  // swap(void_ptr_to_long(   (void *) *void_6)    ,  void_ptr_to_long((void *) *void_88 )  );
  Serial.print("Void_6 after swap: ");

  Serial.print("f_allocated return val : ");

  // Serial.println(f_allocated());
  //  Serial.print((unsigned long) &zs);
  //  Serial.println("\n\n");

  // void* z = &
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