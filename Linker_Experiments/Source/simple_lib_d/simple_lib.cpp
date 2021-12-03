#include "junk_funcs.h"
#include "simple_lib.h"

#define NUM_HEADER_ELEMENTS 0
#define TEXT_OFF 1
#define TEXT_LEN 2
#define DATA_OFF 3 // these aren't used yet
#define DATA_LEN 4
#define DATA_LEN 5
#define BSS_OFF 6
#define BSS_LEN 7

/*

int simple_funct(int a){

	return a+53;d
}

int main(){

	return 2;
}
*/

// KEY: Stick the declerations in here and they'll show up in thec
unsigned long num_elements;
unsigned long text_offset;
unsigned long text_length;
unsigned long data_offset;
unsigned long data_length;
unsigned long bss_offset;
unsigned long bss_length;
unsigned long header_array[];
extern int load_funcs(void)
{
	return 777;
}
// This can be made relocatable if a pointer to the function itself is included; That way you can find the location of these function relative to load_func_struct, which you know everywhere.
// I think this may work without any of that though
int load_func_struct(simple_lib_funcs *fill_table_ptr)
{
	// load_offset_array(my_section_header); // (this would allow use with non relocatable code as well)
	fill_table_ptr->is_filled = 0;
	fill_table_ptr->int_void_LOOK_FOR_ME = &int_void_LOOK_FOR_ME;
	fill_table_ptr->load_777 = &load_777;
	fill_table_ptr->call = &call;
	fill_table_ptr->&get_cur_offsets;
	return 0;
}
int get_cur_offsets()
{
	return data_offset;
	/*
	offsets[TEXT_OFF] = num_elements;
	offsets[TEXT_LEN] = text_length;
	offsets[DATA_OFF] = data_offset;
	offsets[DATA_LEN] = data_length;
	*/
}
// Create a function that reads the values of the segment data and puts them in an array for relocation
// Load that structure when you need to run the program. Don't directly access values the main c++ code can't see
// Replace the load data function with stuff from the elf file later if you want

// Return the value of the starting function?
int load_offset_array(unsigned long my_section_header[])
{
	my_section_header[NUM_HEADER_ELEMENTS] = num_elements;
	my_section_header[TEXT_OFF] = text_offset;
	my_section_header[TEXT_LEN] = text_length;
	// fill in the rest of this when it's needed
}

extern int load_777(void)
{
	return 777;
}

void *get_func_loc()
{

	return &get_func_loc;
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
	z = int_void_LOOK_FOR_ME;
	z = 11 + z;
	int y = 10 + other_elf_include(11);
	int e = 8;
	z = z + y;
	// z = junk_funct(z);
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
