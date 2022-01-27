#include "Memory_Manager.h"
void *long_to_void_ptr(unsigned long input_long)
{
  unsigned long *a;       // make a pointer pointing at a, using the correct pointer type
  a = (void *)input_long; // assign the pointer to the correct value
  void *b;                // create a void* to return
  b = (void *)a;          // type cast the unsigned long ptr to a void*
  return b;               // return the
}