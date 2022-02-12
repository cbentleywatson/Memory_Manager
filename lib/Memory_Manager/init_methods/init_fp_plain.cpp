#include "../Memory_Manager.h"
void Memory_Manager::init_fp_plain(int (*int_int_fp_plain_pass)(int))
{
	int_int_fp_plain = int_int_fp_plain_pass;
}