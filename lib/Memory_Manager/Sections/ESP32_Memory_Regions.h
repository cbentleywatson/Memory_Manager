
// _iram_text_start and _iram_text_end
// 0x40078000–0x4007FFFF // cpu1 cache memory
// _data_start // DRAM0	start
// _data_end // end of dram0
//  _bss_end to 0x3FFF_FFFF
// _bss_start = ABSOLUTE(.);
//  _rodata_start = ABSOLUTE(.);
// _stext = .;
//_text_start = ABSOLUTE(.);
//  _text_end = ABSOLUTE(.);
//     _etext = .; // from >iram0_2_seg memory region in ld
// SPIRAM data addresses : 0x3F80_0000 to 0x3FBF_FFFF
//
// 	FROM MEMORY REGIONS FILE:
// iram0_0_seg (RX) : org = 0x40080000, len = 0x20000
#define SRAM1 0
#define SRAM2 1
#define EXTERNAL_DATA_START 0x3F800000 // 0x3F80_0000
#define EXTERNAL_DATA_END 0x3FBFFFFF   // 0x3FBF_FFFF
#define EXTERNAL_INS_START 0x40078000
#define EXTERNAL_INS_END 0x4007FFFF