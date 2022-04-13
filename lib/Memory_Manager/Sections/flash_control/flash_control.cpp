#include "flash_control.h"

/*
 */
/*
static inline unsigned int IRAM_ATTR cache_flash_mmu_set(int cpu_no, int pid, unsigned int vaddr, unsigned int paddr, int psize, int num)
*/
/*
// reference struct
struct page_args
{
	int first_page;
	int first_flash_address;
	int num_pages;
	bool has_spi_ram;
};
*/
// You can change this later if needed
// convert a virtual address into a page number in the mmu Table in normal_spi_flash
get_mempage(unsigned int virtual_address)
{
	int_first_page = ((virtual_address - VADDR1_FIRST_USABLE_ADDR) / SPI_FLASH_MMU_PAGE_SIZE) + 64;
	return first_page;
}
DPORT_APP_FLASH_MMU_TABLE
/*
get_real_flash_address(String partition_name)
{
}
*/
// Read in the
// esp_err_tesp_flash_write(esp_flash_t *chip, const void *buffer, uint32_t address, uint32_t length)

// needs to copy data from the file into th partition
// sections have all of this actually.

// basic map to partion for testing
/*
 *fill up the partition
 */
/*
int Section::partition_write{
	esp_err_t ret =  spi_flash_write(main_partition, cur_buffer, size);

	// interpret ret to return a proper error later;
	return 0;

}
*/
// Takes a buffer but writes to a default memory address
void Section::default_flash_write(void *source_buffer, uint32 length){
	spi_flash_write(0x110000, source_buffer, length)}
	/*
	#define DPORT_PRO_FLASH_MMU_TABLE ((volatile uint32_t*) 0x3FF10000)

	/* Flash MMU table for APP CPU */
	//#define DPORT_APP_FLASH_MMU_TABLE ((volatile uint32_t *)0x3FF12000)

	* /
// spi_flash_mmap_memory_t

void Section::default_flash_to_virtual_map()
{
	// current physical address of partion for code in flash

	void *void_pointer_to_page_table = (void *)DPORT_PRO_FLASH_MMU_TABLE;
	unsigned int *real_page_table = (unsigned int *)void_pointer_to_page_table;
	// void *void_pointer_to_page table = (void *)DPORT_PRO_FLASH_MMU_TABLE;
	// unsigned int *real_page_table = (unsigned int *)void_pointer_to_page_table;
	int pages_needed;
	// switch the lines above and below to use the page args to get nu pages later on in testing.
	pages_needed = 1;
	// pages_needed = cur_page_args.num_pages;
	DPORT_INTERRUPT_DISABLE();

	// void esp_dport_access_stall_other_cpu_start(void);
	// spi_flash_disable_interrupts_caches_and_other_cpu(); // old version before espressif api update

	DPORT_STALL_OTHER_CPU_START();
	// Replace the constant in the loop with this and deal witht he possibility of type mismatch -- Not sure if an int or unsigned long should be used.
	unsigned int flash_address;
	flash_address = 0x110000;

	//  spi_flash_disable_interrupts_caches_and_other_cpu();

	for (int i = 0; i < pages_needed; i++)
	{
		DPORT_APP_FLASH_MMU_TABLE[64 + i] = 0x110000 + SPI_FLASH_MMU_PAGE_SIZE * i;
		PORT_PRO_FLASH_MMU_TABLE[64 + i] = 0x110000 + SPI_FLASH_MMU_PAGE_SIZE * i;
	}
	/*
		if (esp_get_revision() > 0 && (pages_needed) && (true))
		{
			esp_spiram_writeback_cache();
		}

		Cache_Flush(0);
		Cache_Flush(1);
	*/
	DPORT_STALL_OTHER_CPU_END();
	DPORT_INTERRUPT_RESTORE();
}
// Which table entry is the first to write to??

// PRO_IRAM0_FIRST_USABLE_PAGE
// 0x110000

void IRAM_ATTR my_set_pages(page_args cur_page_args)
{

	void *void_pointer_to_page table = (void *)DPORT_PRO_FLASH_MMU_TABLE;
	unsigned int *real_page_table = (unsigned int *)void_pointer_to_page_table;
	// esp_dport_access_stall_other_cpu_start
	DPORT_INTERRUPT_DISABLE();
	// spi_flash_disable_interrupts_caches_and_other_cpu();

	DPORT_STALL_OTHER_CPU_START();

	for (int i = 0; i < cur_page_args.num_pages; i++)
	{

		real_page_table[cur_page_args.first_page + i] = cur_page_args.first_flash_address + SPI_FLASH_MMU_PAGE_SIZE * i;
	}

	// Something to do with  protecting spi ram. It's included in the normal mmap, I made a copy with a check on the
	// whether or not it's included
	// switch out the true if you don't want it to run
	if (esp_get_revision() > 0 && (page_args.has_spi_ram) && (true))
	{
		esp_spiram_writeback_cache();
	}

	Cache_Flush(0);
	Cache_Flush(1);
	DPORT_STALL_OTHER_CPU_END();
	DPORT_INTERRUPT_RESTORE();

	// spi_flash_enable_interrupts_caches_and_other_cpu();
	return;
}
/*
 * full design for the section load
 */

/*
// get current Page given the section's load VMA etc
// write to the partition

*/