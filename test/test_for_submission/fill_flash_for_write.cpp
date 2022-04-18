#include "tests_for_submission.h"

void fill_flash_for_write(void)
{
	unsigned int PADDR;
	String target_partition;
	PADDR = real_get_physical_address_of_pointer("code_space");
	unsigned int VADDR;
	VADDR = &_block_text_start;
	real_map_physical_to_virtual_address(VADDR, PADDR, 1);
	int num_pages;
	num_pages = 1;
	size_t size = 0x1000 * num_pages;

	// esp_err_t spi_flash_write(size_t dest_addr, const void *src, size_t size);
	void *input_buffer = malloc(size); // heap_caps_malloc(size, MALLOC_CAP_INTERNAL);
	// char *hello_world = "hello world i am a string";
	unsigned char nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	memcpy(input_buffer, &nums, 10);

	//	void *output_buffer = heap_caps_calloc(1, size, MALLOC_CAP_INTERNAL);
	spi_flash_erase_range(PADDR, size);
	spi_flash_write(PADDR, input_buffer, size);
	void *output_buffer = malloc(size);
	spi_flash_read(PADDR, output_buffer, size);

	// unsigned char nums2[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	// memcpy(output_buffer, &nums2, 10);

	unsigned int compare_memory = memcmp(input_buffer, output_buffer, size - 1);
	// int compare_memory = 0;
	free(input_buffer);
	free(output_buffer); //  heap_caps_free(input_buffer);
	//  heap_caps_free(output_buffer);
	TEST_ASSERT_EQUAL_HEX32(0, compare_memory);
}

int real_fill_flash_for_write(String target_partition, unsigned int VADDR, void *buffer, int buffer_size)
{

	unsigned int PADDR;

	PADDR = real_get_physical_address_of_pointer("code_space");

	real_map_physical_to_virtual_address(VADDR, PADDR, 1);
	int num_pages;
	num_pages = (buffer_size / 0x1000) + 1;
	size_t size = 0x1000 * num_pages;

	// esp_err_t spi_flash_write(size_t dest_addr, const void *src, size_t size);
	void *input_buffer = malloc(size); // heap_caps_malloc(size, MALLOC_CAP_INTERNAL);
	// char *hello_world = "hello world i am a string";
	unsigned char nums[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	memcpy(input_buffer, buffer, buffer_size);

	//	void *output_buffer = heap_caps_calloc(1, size, MALLOC_CAP_INTERNAL);
	spi_flash_erase_range(PADDR, size);
	spi_flash_write(PADDR, input_buffer, size);
	void *output_buffer = malloc(size);
	spi_flash_read(PADDR, output_buffer, size);

	// unsigned char nums2[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	// memcpy(output_buffer, &nums2, 10);

	unsigned int compare_memory = memcmp(input_buffer, output_buffer, size - 1);
	// int compare_memory = 0;
	free(input_buffer);
	free(output_buffer); //  heap_caps_free(input_buffer);
						 //  heap_caps_free(output_buffer);
	if(compare_memory==0){
		return 0;
	}else{
		return -1;
	}

}