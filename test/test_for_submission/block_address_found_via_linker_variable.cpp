#include "tests_for_submission.h"
// extern unsigned long flash_array[1024];
unsigned long flash_array[1024] __attribute__((section(".block.text")));
unsigned long flash_array3[1024] __attribute__((section(".block2.text")));
void block_address_found_via_linker_variable(void)
{

	if (false)
	{

		/*
				flash_array[0] = 11;
				flash_array[16] = flash_array[0] + 11;
				flash_array[32] = flash_array[0] + flash_array[16];
		*/
		/*
				flash_array3[0] = 11;
				flash_array3[16] = flash_array[0] + 11;
				flash_array3[32] = flash_array[0] + flash_array[16];
		*/

		int a = flash_array[11];
		a = a + a;
		a = 2 * a;
	}

	TEST_ASSERT_EQUAL_HEX32(0x40BC0000, &_block_text_start);

	return;
}