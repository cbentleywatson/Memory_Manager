#include "junk_funcs.h"
#include "simple_lib.h"
/*

int simple_funct(int a){

	return a+53;d
}

int main(){

	return 2;
}
*/

// KEY: Stick the declerations in here and they'll show up in thec

extern int load_funcs(void)
{
	return 777;
}

int load_func_struct(simple_lib_funcs *fill_table_ptr)
{
	fill_table_ptr->is_filled = 0;
	fill_table_ptr->int_void_LOOK_FOR_ME = &int_void_LOOK_FOR_ME;
	fill_table_ptr->load_777 = &load_777;
	fill_table_ptr->call = &call;
	return 0;
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

	int (*void_ptr)(){&int_void_LOOK_FOR_ME};
	int a = void_ptr();
	int z = int_void_LOOK_FOR_ME;
	z = 11 + z;
	int y = 10;
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
