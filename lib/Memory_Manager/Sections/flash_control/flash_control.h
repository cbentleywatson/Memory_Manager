/*
 * CRUCIAL !!! Example code came from Her!
 * https://github.com/pycom/pycom-esp-idf/blob/master/components/spi_flash/flash_mmap.c#L50
 */
/*
 * Default values for the location of iram02_segment which is the the set of virtual adresses used rn
 * to hold the virtual addresses of the sections
 */

#define VADDR0_START_ADDR 0x3F400000
#define VADDR1_START_ADDR 0x40000000
#define VADDR1_FIRST_USABLE_ADDR 0x400D0000
#define PRO_IRAM0_FIRST_USABLE_PAGE ((VADDR1_FIRST_USABLE_ADDR - VADDR1_START_ADDR) / SPI_FLASH_MMU_PAGE_SIZE + 64)
//
/*
extern int _loadable_start;
extern int _loadable_end;
extern int _data_start;
extern int _data_end;
*/
#include "../Sections.h"
#include <soc/dport_reg.h>
#include "esp_spi_flash.h"
//#include "spi_flash_types.h"
#include "cache.h"			  // This file DOES have Cache_Flush in it
#include "esp_dport_access.h" // correct

/*
 * SPDX-FileCopyrightText: 2015-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <freertos/semphr.h>
#include "soc/soc.h"
#include "soc/soc_memory_layout.h"
#include "soc/dport_access.h"
#include "sdkconfig.h"
#include "esp_attr.h"
#include "esp_spi_flash.h"
#include "esp_flash_encrypt.h"
#include "esp_rom_spiflash.h"
#include "esp_log.h"
#include "cache_utils.h"
#include "esp32/dport_access.h"
#if CONFIG_IDF_TARGET_ESP32
#include "soc/dport_reg.h"
#include "esp32/rom/cache.h"
#include "esp32/spiram.h"
#include "soc/mmu.h"
// TODO: IDF-3821
#define INVALID_PHY_PAGE 0xffff
#elif CONFIG_IDF_TARGET_ESP32S2
#include "esp32s2/rom/cache.h"
#include "esp_private/mmu_psram.h"
#include "soc/extmem_reg.h"
#include "soc/ext_mem_defs.h"
#include "soc/mmu.h"
#elif CONFIG_IDF_TARGET_ESP32S3
#include "esp32s3/rom/cache.h"
#include "esp32s3/spiram.h"
#include "soc/extmem_reg.h"
#include "soc/ext_mem_defs.h"
#include "soc/mmu.h"
#elif CONFIG_IDF_TARGET_ESP32C3
#include "esp32c3/rom/cache.h"
#include "soc/ext_mem_defs.h"
#include "soc/mmu.h"
#elif CONFIG_IDF_TARGET_ESP32H2
#include "esp32h2/rom/cache.h"
#include "soc/ext_mem_defs.h"
#include "soc/mmu.h"
#elif CONFIG_IDF_TARGET_ESP32C2
#include "esp32c2/rom/cache.h"
#include "soc/ext_mem_defs.h"
#include "soc/mmu.h"
#endif

/*
page args reference

*/

/*
#include <soc/dport_access.h>
#include "soc/cache_utils.h"
#include <freertos/FreeRTOS.h>

#include <freertos/task.h>
#include <freertos/semphr.h>
#include <rom/spi_flash.h>
#include <rom/cache.h>
#include <soc/soc.h>
#include <soc/dport_reg.h>
#include "sdkconfig.h"
#include "esp_ipc.h"
#include "esp_attr.h"
#include "esp_spi_flash.h"
#include "esp_flash_encrypt.h"
#include "esp_log.h"
#include "cache_utils.h"
#include "esp_spiram.h"
#include <esp32>

#include <stdio.h>
#include "esp_types.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/periph_ctrl.h"
#include "driver/timer.h"
#include "freertos/portmacro.h"


*/
// address

/*void IRAM_ATTR set_pages(page_args);*/
