
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

#define MAX_INTERNAL_IRAM 0x3FFFFFFF // SRAM1  ends here, it can go both ways...
#define MIN_INTERNAL_IRAM 0x3FFAE000
#define NORMAL_IRAM_INTERNAL_END 0x3FFDFFFF
// #define IRAM1_END 0x3FFD_FFFF

//#define MAX_INTERNAL_IRAM 0x3FFF_FFFF // SRAM1  ends here, it can go both ways...
//#define MIN_INTERNAL_IRAM 0x3FFA_E000

// #define NORMAL_IRAM_INTERNAL_END 0x3FFD_FFFF