#include "Memory_Manager.h"
void swap_ptr(void *a, void *b)
{
    // char *char_a = (char *)a;
    // char *char_b = (char *)b;
    // a = char_b;
    // b = char_a;

    void *c;
    c = a;
    a = b;
    b = c;
}