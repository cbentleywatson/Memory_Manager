#include "Arduino.h"
#include <Memory_Manager.h>
#include "sort.h"
#include <unity.h>
void default_test(void);
extern int _block_text_start;

void block_address_found_via_linker_variable(void);
void get_physical_address_of_pointer(void);
	//  memcpy (start_of_FLASH, start_of_ROM, end_of_ROM - start_of_ROM);