#include "../../Memory_Manager.h"
void *Memory_Manager::file_to_exec(String file_name, size_t offset, size_t length)
{
    return file_to_exec(file_name, offset, 0, length);
}

void *Memory_Manager::file_to_exec(String file_name, size_t sec_offset, size_t offset_from_sec_start, size_t length)
{
    void *heap_pointer = file_sec_to_heap(file_name, sec_offset, offset_from_sec_start, length);
    // ERROR: funct_load_with_void_ptr takes int but it's loaded with size_t here.
    void *exec_ptr = func_load_with_void_ptr(heap_pointer, length);
    free(heap_pointer);
    return exec_ptr;
}

// This one is for moving exec sections into new memory and
void *Memory_Manager::file_to_exec(String file_name)
{
    FILE *ptr;
    /// const char* real_file_name = "/spiffs" + file_name;
    int length_file;
    ptr = fopen(file_name.c_str(), "r");
    if (ptr == NULL)
    {
        return ptr;
    }
    fseek(ptr, 0, SEEK_END);
    length_file = ftell(ptr);
    fseek(ptr, 0, SEEK_SET);
    // length_file = getFileSize(ptr);

    // CURRENT WORK:
    /*
   int size_of_allocated_memory = 0; // Be filled by reference in get_valid_heap_memory
   void *allocated_heap_memory = file_to_heap_pure_fstructs(file_name, size_of_allocated_memory);
   //
   allocated_exec_memory = get_valid_exec_memory(length_file, size_of_allocated_memory);

   return allocated_heap_memory;
*/
}

/* Febrauary 13, final memory move to exec
void *Memory_Manager::file_to_exec(String file_name, int &memory_size){
    ?? void * exec_mem = file_to_heap_pure_fstructs(file_name, memory_size);
    return exec_meme;
}

*/