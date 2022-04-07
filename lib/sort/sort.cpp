
#include "sort.h"
// This was just for reference but it can also be tested if desired.
int IRAM_ATTR test(int a); //__attribute__((section("ext_ram_seg")));
int IRAM_ATTR test(int a)
{
	/*
		while (true)
		{
			a = a + 1;
		}
	*/
	return a + 1;
}

int selection_sort(int a[], int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
	return 0;
}
// This is a demo function that will be run from RAM
int buffer_formatted_selection_sort(void *input_buffer, int input_length, void *output_buffer, int output_length, void *arg_struct)
{
	// Check if there's enough space for the output just in case.
	if (input_length != output_length)
	{
		return -1;
	}
	// fill up the output buffer
	memcpy(output_buffer, input_buffer, input_length * 4);
	// Format the output buffer as an integer array
	int *a = output_buffer;
	// Sort the output buffer in place
	int i, j, min, temp;
	int n = input_length;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

	return 0;
}

int struct_arg_selection_sort(loadable_function_args_struct in)
{
	void *input_buffer = in.input_buffer;
	int input_length = in.input_length;
	void *output_buffer = in.output_buffer;
	int output_length = in.output_length;
	void *arg_struct = in.arg_struct;
	// Check if there's enough space for the output just in case.
	if (input_length != output_length)
	{
		return -1;
	}
	// fill up the output buffer
	memcpy(output_buffer, input_buffer, input_length * 4);
	// Format the output buffer as an integer array
	int *a = output_buffer;
	// Sort the output buffer in place
	int n = input_length;
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++)
	{
		min = i;
		for (j = i + 1; j < n; j++)
			if (a[j] < a[min])
				min = j;
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}

	return 0;
}
