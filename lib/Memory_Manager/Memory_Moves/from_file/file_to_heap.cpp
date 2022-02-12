#include "../../Memory_Manager.h"
void *Memory_Manager::file_to_heap(String file_name, size_t offset, size_t length)
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
void *Memory_Manager::file_to_heap(String file_name)
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
