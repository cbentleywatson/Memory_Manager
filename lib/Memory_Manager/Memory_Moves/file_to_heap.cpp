#include "../Memory_Manager.h"
void *file_to_heap(String file_name, size_t offset, size_t length)
{
  File file = SPIFFS.open(file_name, FILE_READ);
  if (!file)
  {
    Serial.println("Failed to open file for reading.");
    return NULL;
  }
  if (length == 0)
  {
    length = file.size();
  }
  char *temp_ptr = (char *)heap_caps_malloc(length, MALLOC_CAP_DMA);
  file.seek(offset, SeekSet);

  // off by 1 errors possible here
  size_t remaining_length = file.size() - offset;
  if (remaining_length < length)
  {
    length = remaining_length;
  }
  file.readBytes(temp_ptr, length);
  file.close();
  return (void *)temp_ptr;
}

// move the entire file to the heap
void *file_to_heap(String file_name)
{
  File file = SPIFFS.open(file_name, FILE_READ);
  if (!file)
  {
    Serial.println("Failed to open file for reading.");
    return nullptr;
  }
  size_t length = file.size();
  // file.close();
  // return file_to_heap(file_name,  )
  char *temp_ptr = (char *)heap_caps_malloc(length, MALLOC_CAP_DMA);
  // file.seek(offset, SeekSet);
  //  off by 1 errors possible here
  // size_t remaining_length = file.size() - offset;
  //  if (remaining_length < length)
  //  {
  //    length = remaining_length;
  //  }
  file.readBytes(temp_ptr, length);
  file.close();
  return (void *)temp_ptr;
}
void *file_to_heap_pure_fstructs(String file_name)
{
  FILE *ptr;
  /// const char* real_file_name = "/spiffs" + file_name;
  int length_file;
  ptr = fopen(file_name.c_str(), "r");
  fseek(ptr, 0, SEEK_END);
  length_file = ftell(ptr);
  fseek(ptr, 0, SEEK_SET);

  int length_array = modulo_smooth(length_file);
  void *heap_memory_input_ptr = heap_caps_malloc(length_array, MALLOC_CAP_DMA);
  fread(heap_memory_input_ptr, 1, length_file, ptr);
  fclose(ptr);
  return heap_memory_input_ptr;
}