/*
    Header will include one decleration of a function foo to be stored in memory.
    The first will be a dummy which will be included in the program and be small
    The second will contain the real version of the function. When the dummy version is called
    a load from memory function will be called followed by the movement of the function pointer to the location of 
    the real function which was just loaded into memory.
    The origianal function ptr will then be called.
    The return value taken from the actual function will be returned to the dummy's caller.

    If , necessary the origanl function pointer will be reset to it's original value. 
    A copy of the original function address will be saved in a void* ptr temp. Before the ptr is returned, 
    the address of temp will be copied back into the original pointer. 


*/
int simple_funct(int a);


struct simple_lib_funcs
{
	int is_filled;
	int (*int_void_LOOK_FOR_ME)();
	int (*load_777)();
	int (*call)();
};

typedef int (*loader_ptr)(simple_lib_funcs *);

extern "C"
{
	// type of loader function
	int int_void_LOOK_FOR_ME();
	int call();
	int extern_and_name_space(void);
	void *get_func_loc(void);
	void *get_call_loc(void);
	int load_funcs();
	int load_777();
	int load_func_struct(simple_lib_funcs *fill_table_ptr);
}
