#include "../Memory_Manager.h"
void *file_sec_to_heap(String file_name, size_t sec_offset, size_t offset_from_sec_start, size_t length)
{
    return file_to_heap(file_name, offset_from_sec_start + sec_offset, length);
}