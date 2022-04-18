#include "tests_for_submission.h"

void map_physical_flash_to_virtual_address(void)
{
	unsigned int PADDR;
	String target_partition;
	PADDR = real_get_physical_address_of_pointer("code_space");
	unsigned int VADDR;
	VADDR = &_block_text_start;
	// VADDR = 0x407F0000; // VADDR2 available
	VADDR = 0x40400000; // VADDR3 AVAILABLE -- 0x4040_0000
	//  VADDR = 0x40BC0000;
	//   cache_flash_mmu_set(int cpu_no, int pid, unsigned int vaddr, unsigned int paddr, int psize, int num);
	//    pxCurrentTCB->uxTCBNumber;
	unsigned int core = xPortGetCoreID();
	// Xthal_have_prid
	int cur_pid = getpid();

	int return_code = cache_flash_mmu_set(core, cur_pid, VADDR, PADDR, 64, 1);
	const void *cached = (void *)VADDR;
	// TEST_ASSERT_EQUAL_HEX32(0, spi_flash_cache2phys(cached));
	// TEST_ASSERT_EQUAL_HEX32(0, return_code);
	if (((PADDR % 0x10000) != 0))
	{
		TEST_ASSERT_EQUAL_HEX32(0, 0xff);
	}
	if (((VADDR % 0x10000) != 0))
	{
		TEST_ASSERT_EQUAL_HEX32(0, VADDR / (0x10000));
	}

	TEST_ASSERT_EQUAL_HEX32(0, return_code);
}
// xPortGetCoreID()
// XCHAL_HAVE_PRID

int real_map_physical_to_virtual_address(unsigned long VADDR, unsigned long PADDR, int num_pages)
{
	unsigned int core = xPortGetCoreID();
	// Xthal_have_prid
	int cur_pid = getpid();

	int return_code = cache_flash_mmu_set(core, cur_pid, VADDR, PADDR, 64, num_pages);
	// const void *cached = (void *)VADDR;
	//  TEST_ASSERT_EQUAL_HEX32(0, spi_flash_cache2phys(cached));
	//  TEST_ASSERT_EQUAL_HEX32(0, return_code);
	if (((PADDR % 0x10000) != 0))
	{
		return 6;
	}
	if (((VADDR % 0x10000) != 0))
	{
		return 7;
	}

	return return_code;
}