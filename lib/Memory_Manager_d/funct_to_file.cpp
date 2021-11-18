#include "Memory_Manager.h"
/*
    This was written in main and transferred over without modification
    the general structure was found to work
*/

// funct to file should probably be simpler,

//    TO DO:       !!!!
// take filename to target, pointer, length.

int funct_to_file(void* funct_ptr, String file_name, size_t length){
  //if (SPIFFS.exists(file_name)){
  //    SPIFFS.remove(file_name);
  //}
  //  "w" option should automatically erase existing data
  File file = SPIFFS.open(file_name, "w");
  if (!file){
    
    //Serial.println("Failed to open file for reading.");
    return -1;
  }

  file.write((const uint8_t *) funct_ptr ,length);
  file.close();
  return 0;
}
  //memcpy(temp_ptr, function_ptr_to_copy , length_of_new_function);
  
  /*
  
  File file = SPIFFS.open("/saved_funct", FILE_WRITE);

  //
  //200 is a place holder for length values
  if (!file){
    Serial.println("Failed to open file for reading.");
  }
  int (*void_6_file)(){&int_void_6};
  void* temp_ptr =  heap_caps_malloc(200, MALLOC_CAP_DMA);
  memcpy(temp_ptr, void_6_file, 200);
  //Serial.println("temp ptr :", (uint32_t) temp_ptr );
  file.write((const uint8_t *) temp_ptr ,200);
  free(temp_ptr);
  file.close();
  //write(const uint8_t *buf, size_t size)
  loop_count++;
}else{

    */