#include "simple_lib_d.h"
/*
int simple_funct(int a){

    return a+53;
}

int main(){

    return 2;
}
*/
extern int int_void_LOOK_FOR_ME();
int e = 20;

extern int int_void_LOOK_FOR_ME()
{
    return 21;
}
extern int call();
extern int call()
{
    // int a = int_void_LOOK_FOR_ME();
    int (*void_ptr)(){&int_void_LOOK_FOR_ME};
    int a = void_ptr();
    int z = 11;
    int y = 9;
    int e = 8;
    z = z + y;
    z = z + e;
    z = z + z;

    return a + z;
    // int (*void_ptr)(){&int_void_LOOK_FOR_ME};
}
/*
int hope_not();
int hope_not()
{

    int a = 1;
    a = a + 1;
    a++;
    a++;
    return a;
}
*/
int (*call_ptr)(){&call};
namespace
{
    int int_void_22()
    {
        return 22;
    }

}