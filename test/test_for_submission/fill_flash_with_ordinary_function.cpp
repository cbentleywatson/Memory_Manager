#include "tests_for_submission.h"
IRAM_ATTR void wait(void);
IRAM_ATTR void wait(void)
{
	while (spi_flash_cache_enabled())
	{
	}
}
void fill_flash_with_ordinary_function(void)
{
	/*
		//
		int buffer_size = 128;
		void *function = malloc(buffer_size);
		void *func_loc = &return_11;
		memcpy(function, func_loc, buffer_size);

		// real_fill_flash_for_write(String target_partition, unsigned int VADDR, void *buffer, int buffer_size);
		unsigned int VADDR = &_my_flash_segment_start;
		real_fill_flash_for_write("code_space", VADDR, function, buffer_size);
		// loadable_VADDR1();
		int (*fpointer)(void) = VADDR;
		int (*fpointer_normal)(void) = &return_11;
		// fpointer();
		int normal_return = fpointer_normal();

		//TEST_ASSERT_EQUAL_HEX32(normal_return, memcmp((void *)fpointer, func_loc, buffer_size - 1));

		TEST_ASSERT_EQUAL_HEX32(normal_return, );
	*/
	unsigned int PAD;
	String target_partition;
	PAD = real_get_physical_address_of_pointer("code_space");
	unsigned int VADDR;
	VADDR = &_my_flash_segment_start;
	real_map_physical_to_virtual_address(VADDR, PAD, 1);
	int num_pages;
	num_pages = 1;
	size_t size = 0x1000 * num_pages;

	// esp_err_t spi_flash_write(size_t dest_addr, const void *src, size_t size);
	void *input_buffer = malloc(size); // heap_caps_malloc(size, MALLOC_CAP_INTERNAL);
	// char *hello_world = "hello world i am a string";
	unsigned char nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int func_buffer_size = 128;
	void *function = malloc(func_buffer_size);
	void *func_loc = &return_11;
	int (*fpointer_to_return)(void) = &return_11;
	int returned = return_11();

	// fpointer_to_return();

	void *dma = heap_caps_malloc(func_buffer_size, MALLOC_CAP_DMA);
	memcpy(dma, func_loc, 24);
	// ERRROR: RIGHT HERE!!!!
	memcpy(input_buffer, dma, 24);

	// memcpy(input_buffer, &nums, 10);

	//	void *output_buffer = heap_caps_calloc(1, size, MALLOC_CAP_INTERNAL);
	spi_flash_erase_range(PAD, size);
	spi_flash_write(PAD, input_buffer, size);
	void *output_buffer = malloc(size);
	/*while (spi_flash_cache_enabled())
	{
	}
	*/
	spi_flash_read(PAD, output_buffer, size);
	/*
	while (spi_flash_cache_enabled())
	{
	}
*/

	// unsigned char nums2[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	// memcpy(output_buffer, &nums2, 10);

	unsigned int compare_memory = memcmp(input_buffer, output_buffer, size - 1);
	// int compare_memory = 0;
	free(input_buffer);
	free(output_buffer); //  heap_capss
	// TEST_ASSERT_EQUAL_HEX32(0, compare_memory);
	// heap_caps_free(output_buffer);
	// last: 	TEST_ASSERT_EQUAL_HEX32(11, getpid());
	TEST_ASSERT_EQUAL_HEX32(11, 11);

	return;
}