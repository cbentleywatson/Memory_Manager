#include <Arduino.h>
#include "Memory_Manager.h"
#include <SPIFFS.h>
#include <FreeRTOS.h>
#include <iostream>
#include <stddef.h>
#include "simple_lib_d.h"
//#include <Serial.h>
typedef int (*fn_def)(void);
int my_int_func(int x);
int int_void();
int int_void6();
int my_int_func(int x)
{
	return 5;
}
int int_void()
{
	return 5;
}
int int_void_6()
{
	return 6;
}
int int_void_21()
{
	return 21;
}
int simple_int(int a)
{
	return a;
}

void int_void_6(int x)
{
	;
	;
}

int (*mem_func)();
void setup()
{
	// put your setup code here, to run once:
	Serial.begin(9600);
	SPIFFS.begin();
	// Serial.println("Hello World!");
}

void loop()
{

	// foo(111);
	/*
	if (!simple_lib)
	{

		Serial.println("file open error");
	}
	else
	{
		Serial.print("File Contenets: ");
		while (simple_lib.available())
		{
			Serial.write(simple_lib.read());
		}

		Serial.println(file_contents);
		free(file_contents);
	}
	simple_lib.close();

	*/
	//
	// this can be used for any type but it requires specific casts to work.
	void (*gen)(void);

	// void * cube(void*)// take any object and return any object.

	int (*foo)(){&int_void};
	int (*void_6)(){&int_void_6};
	int (*mem_func)(){&int_void_6};
	int (*void_21)(){&int_void_21};
	// boo = &my_int_func;
	foo();
	void_6();
	delay(2001);
	Serial.print("void_6 before relocation: ");
	Serial.println(void_6());
	// int32_t address = &int_void_21;
	// Serial.print(address);
	delay(2000);
	void_6 = foo;
	Serial.print("Void_6 after relocation: ");
	Serial.println(void_6());
	int32_t temp2_address;

	delay(2001);
	void *temp2 = heap_caps_malloc(300, MALLOC_CAP_EXEC);

	// int_32t address_of_temp= (int32_t) temp2;
	// void* int_void_21_address =(void*) int_void_21;
	// char original[100];
	char moved[100];
	// Serial.println(&int_void);

	memcpy(temp2, void_21, 300);
	void *temp_for_lib_test;
	// memcpy(temp2, &moved, 100);
	// memcpy(int_void_21, &original,100);

	moved[99] = 0;
	// Serial.println(original);
	// Serial.println(moved);
	// Serial.print("Temp2 Address: ");
	// Serial.println( address_of_temp);
	delay(2000);
	void_6 = &int_void_6;
	Serial.print("Void_6 after reset: ");
	Serial.println(void_6());

	delay(2000);
	void_6 = temp2;
	gen = temp2;
	Serial.print("Void_6 after temp2 move: ");
	Serial.println(void_6());
	gen = temp2;
	Serial.print("Gen pointer: ");
	// Serial.println(gen());
	Serial.println("\n\n\n");
	delay(2000);

	Serial.print("Void_6 after reset for testing mv_fun_ptr");
	void_6 = &int_void_6;
	Serial.println(void_6());
	delay(2000);

	Serial.print("Void_6 after mv_func_ptr call: ");
	mv_func_ptr(void_6, void_21, 100);
	Serial.println(void_6());
	free(void_6);
	delay(2000);
	gen = temp2;
	Serial.print("Gen pointer: ");
	// Serial.println(gen());
	Serial.println("\n\n");

	// foo = temp2;
	//  These are two ways to to do this

	// void* fnvptr = (void*)&void_6; // make a void ptr to func
	// fn_def fnptr = (fn_def)fnvptr; // pointer to pointer to function

	// void* voidptr = temp2;

	// int (*fptr)(int); // function pointer
	//(void**)(&fptr) = voidptr;

	/*
	(void**)(&fptr) = voidptr;

	*/

	// Serial.print(a);
	// foo =temp2;
	// mem_func = MALLOC_CAP_32BIT;
	free(temp2);
}