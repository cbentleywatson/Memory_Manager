/*
 * This file contains argument structs for loadable functions processing both
 * files and various types of data stored in arrays. Each type of function
 * takes a specific struct designed to represent the arguments needed to control
 * any function working on either buffers or files.
 * The first arguments tell the functions which files or buffers to process
 * and the last argument is a pointer to a costom struct that can contain any
 * user defined arguments needed. That makes the range of functions that can be
 * controlled by functions of this types extremely flexible. At the bottom
 * of the file there are typedefs for function pointers of all of these types
 * and one for a function that returns int and takes no arguments, which is what is used
 * in the basic testing functions.
 */

// This struct represents an argument struct for a loadable function
struct loadable_function_args_struct
{
	void *input_buffer;
	int input_length;

	void *output_buffer;
	int output_length;
	void *arg_struct; // This struct can hold any number of arguments or controls as long as it's defined somewhere.
};
struct void_loadable_function_args_struct
{
	void *input_buffer;
	int input_length;
	void *arg_struct; // This struct can hold any number of arguments or controls as long as it's defined somewhere.
};

// these can all be overloaded so that any arg struct can be destroyed
int destroy_buffer_struct(loadable_function_args_struct in)
{
	free(in.input_buffer);
	free(in.output_buffer);
	return 0;
}

// This deals with pure arguments
struct loadable_file_processing_int_struct
{
	char *input_file;
	char *output_file;
	void *arg_struct; // This struct can hold any number of arguments or controls as long as
}
// This one allows information to be transmitted back via an additional struct
struct loadable_file_processing_void_struct
{
	char *input_file;
	char *output_file;
	void *arg_struct;
	// allows an arbitrary out put as a struct;
	void *output_struct;
};

int destroy_file_struct(loadable_file_processing_arg_struct)
{
	free(in.input_file);
	free(in.output_file);
}
/* The first two pointer defs deal with normal functions return integer error
 * codes. The second two function pointers are for functions that can allocate
 * memory. The side effects one is just so that if you want to manage a function that
 * is just testing something like whether it's possible to access a function
 * like Serial.print() you don't need to bother with creating an arg array.
 * The arg_loadable_func is basically for consistency with the format of system calls in other
 * operating systems.
 */
/*
 * It would totally be possible to remove the two void * structs if needed and send the
 */
// you could actually malloc the output buffer in the same set up if desired
typedef int (*buffer_loadable_func)(loadable_function_args_struct);

typedef int (*file_loadable_func)(void_loadable_function_args_struct);
// if you remove these two and make new structs with different types,  you can overload
// If you don't want to specify the size of the output buffer, you can pass in something that
typedef void *(*void_buffer_loadable_func)(loadable_file_processing_int_struct);

// if this thing doesn't get it's own type of struct it won't be possible to make MM overload
// the runable functions. This thing is actually just for convenience, the void * is
// jus
typedef int (*void_file_loadable_func)(loadable_file_processing_void_struct);

typedef int (*side_effect_only)();
typedef int (*arg_loadable_func)(void *input_buffer, int input_length, void *output_buffer, int output_length, void *arg_struct);