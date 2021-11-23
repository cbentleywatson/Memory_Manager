#include "junk_funcs.h"
//#include "simple_lib_d.h"
/*

int simple_funct(int a){

	return a+53;d
}

int main(){

	return 2;
}
*/

// KEY: Stick the declerations in here and they'll show up in thec

extern "C"
{
	int int_void_LOOK_FOR_ME();
	int call();
	int extern_and_name_space(void);
	void *get_func_loc(void);
	void *get_call_loc(void);
	void *load_funcs(void *);
}

extern void *load_funcs(void *args)
{
	return NULL;
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
	z = int_void_LOOK_FOR_ME;
	int z = 11 + z;
	int y = 9;
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
