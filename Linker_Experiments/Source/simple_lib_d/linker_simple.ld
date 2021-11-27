SECTIONS { 
	ENTRY(load_func_struct)
   .text : { 
	LONG();
	. = ALIGN(4);
	. = text_offset = .  ;
	/*text_length = len(.text );
	//data_offset
	data_length = len(.data);
	bss_offset
	bss_length = len(.bss)
	*/

	load_func_struct = .;

	   *(.text)  } 
  .data : { *(.data) } 
  .bss :  { *(.bss)  *(COMMON) } 

} 