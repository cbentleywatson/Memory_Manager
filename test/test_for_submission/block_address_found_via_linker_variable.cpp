#include "tests_for_submission.h"

void block_address_found_via_linker_variable(void)
{

	TEST_ASSERT_EQUAL_HEX32(0x400D0018, &_block_text_start);

	return;
}