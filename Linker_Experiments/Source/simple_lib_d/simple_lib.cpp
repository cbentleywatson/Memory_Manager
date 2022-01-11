#include "junk_funcs.h"
#include "simple_lib.h"
extern unsigned long _text_offset;
#define NUM_HEADER_ELEMENTS 0
#define TEXT_OFF 1
#define TEXT_LEN 2

#define DATA_OFF 3 // these aren't used yet
#define DATA_LEN 4

#define BSS_OFF 5
#define BSS_LEN 6

/*

int simple_funct(int a){

	return a+53;d
}

int main(){

	return 2;
}
*/

// KEY: Stick the declerations in here and they'll show up in thec
unsigned long num_elements = 7;
unsigned long _text_offset;
unsigned long _text_length;
unsigned long _data_offset = 11;
unsigned long _data_length;
unsigned long _bss_offset;
unsigned long null_check;
unsigned long _bss_length;
unsigned long _header_array[7];
unsigned long _e_txt;
unsigned long _ele[2];
int get_cur_offsets();
extern int load_funcs(void)
{
	_data_offset++;
	return 777;
}
// This can be made relocatable if a pointer to the function itself is included; That way you can find the location of these function relative to load_func_struct, which you know everywhere.
// I think this may work without any of that though

int get_cur_offsets()
{
	return _data_offset;
	/*
	offsets[TEXT_OFF] = num_elements;
	offsets[TEXT_LEN] = text_length;
	offsets[DATA_OFF] = data_offset;
	offsets[DATA_LEN] = data_length;
	*/
}
int load_func_struct(simple_lib_funcs *fill_table_ptr)
{
	// load_offset_array(my_section_header); // (this would allow use with non relocatable code as well)
	fill_table_ptr->is_filled = 0;

	fill_table_ptr->int_void_LOOK_FOR_ME = &int_void_LOOK_FOR_ME;
	//
	fill_table_ptr->load_777 = &load_777;
	fill_table_ptr->call = &call;
	fill_table_ptr->get_cur_offsets = &get_cur_offsets;
	// return &_e_txt;
	return 0;
}

// Create a function that reads the values of the segment data and puts them in an array for relocation
// Load that structure when you need to run the program. Don't directly access values the main c++ code can't see
// Replace the load data function with stuff from the elf file later if you want

// Return the value of the starting function?
// sec_header

int load_offset_array(unsigned long my_section_header[])
{
	my_section_header[NUM_HEADER_ELEMENTS] = num_elements;
	my_section_header[TEXT_OFF] = _text_offset;
	my_section_header[TEXT_LEN] = _text_length;
	my_section_header[DATA_OFF] = _data_offset;

	my_section_header[DATA_LEN] = _data_length;
	// fill in the rest of this when it's
	return 0;
}

extern int load_777(void)
{
	return 777;
}

void *get_func_loc()
{

	return (void *)&get_func_loc;
}
void *get_call_loc(void)
{

	return &call;
}

int ns_not_ext();

// extern int int_void_LOOK_FOR_ME();
// extern int call();
//

int e = 20;

extern int int_void_LOOK_FOR_ME()
{
	return 21;
}

extern int call()
{
	// int a = int_void_LOOK_FOR_ME();
	int z = other_elf_include(10);
	int (*void_ptr)(){&int_void_LOOK_FOR_ME};
	int a = void_ptr();
	z = int_void_LOOK_FOR_ME();
	z = 11 + z;
	int y = 10 + other_elf_include(11);
	int e = 8;
	z = z + y;
	// z = z + _text_offset;
	//  z = junk_funct(z);
	z = z + e;
	z = z + z;

	return a + z;
	// int (*void_ptr)(){&int_void_LOOK_FOR_ME};
}
int (*call_ptr)(){&call};
namespace
{

	int extern_and_name_space(void)
	{
		return 1 + 1;
	}
	int ns_not_ext()
	{
		return 22;
	}

}
// Not in namespace but not in external
int normal_decleration(void);
int normal_decleration()
{
	return 23;
}
