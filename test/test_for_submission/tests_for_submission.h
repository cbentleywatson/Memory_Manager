
#include "Arduino.h"
#include <Memory_Manager.h>
#include "sort.h"
#include "esp_partition.h"
#include <unity.h>
//#include "esp_spi_flash.h"
#include "rom/cache.h"
//#include "multi_heap.h"
#include "esp_heap_caps.h"
//#include "esp32_heap_caps.h"
void default_test(void);
extern int _block_text_start;
extern int _my_flash_segment_start;
extern void *pxCurrentTCB;
void block_address_found_via_linker_variable(void);

void find_nvs_partition(void);
void get_physical_address_of_pointer(void);
//  memcpy (start_of_FLASH, start_of_ROM, end_of_ROM - start_of_ROM);
void map_physical_flash_to_virtual_address(void);
void fill_flash_for_write(void);
// Cleaned up test functions:

unsigned long real_get_physical_address_of_pointer(String code_partition_name);
int real_map_physical_to_virtual_address(unsigned long VADDR, unsigned long PADDR, int num_pages);

int real_fill_flash_for_write(String target_partition, unsigned int VADDR, void *buffer, int buffer_size);