#include "Memory_Manager.h"

elf_header *ld_elf_header(String file_name)
{
    // Load the header with file_to_heap (first 52 bytes)
    // convert the pointer into a (elf_header *)
    return (elf_header *)file_to_heap(file_name, 0, 52);
}