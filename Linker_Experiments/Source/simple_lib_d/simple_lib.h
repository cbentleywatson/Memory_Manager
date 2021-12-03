// To Load the program
// 1. Call MM and get the stuff into memory
// 2. Make a new simple_lib_funcs table
// 3. Make a new loader_ptr
// 4. Set the loader_ptr to point to the correct memory spot
// 5. Put the function table in as the loader's arguments
// 6. Call the loader
// 7. Call the functions inside of the table as needed.
int other_elf_include(int x);

struct simple_lib_funcs
{
	int is_filled;
	int (*int_void_LOOK_FOR_ME)();
	int (*load_777)();
	int (*call)();
	int (* get_cur_offsets)()
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
