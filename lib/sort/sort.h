#include "loadable_functions.h"
#include <Arduino.h>

// int side_effect_test(void) __attribute__((section(".side_effect_test.text")));
int side_effect_test(void) __attribute__((_ADDRESSOF(0x3f800004)));
int formatted_selection_sort(void *input_buffer, int input_length, void *output_buffer, int output_length, void *arg_struct);
int selection_sort(int a[], int n);
int buffer_formatted_selection_sort(void *input_buffer, int input_length, void *output_buffer, int output_length, void *arg_struct);

int struct_arg_selection_sort(loadable_function_args_struct in);
int test(int a);