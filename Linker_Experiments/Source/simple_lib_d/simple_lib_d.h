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