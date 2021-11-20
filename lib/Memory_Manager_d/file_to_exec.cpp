#include "Memory_Manager.h"
void *file_to_exec(String file_name, size_t offset, size_t length)
{
    return file_to_exec(file_name, offset, 0, length);
}

void *file_to_exec(String file_name, size_t sec_offset, size_t offset_from_sec_start, size_t length)
{
    void *heap_pointer = file_sec_to_heap(file_name, sec_offset, offset_from_sec_start, length);
    // ERROR: funct_load_with_void_ptr takes int but it's loaded with size_t here.
    void *exec_ptr = func_load_with_void_ptr(heap_pointer, length);
    free(heap_pointer);
    return exec_ptr;
}