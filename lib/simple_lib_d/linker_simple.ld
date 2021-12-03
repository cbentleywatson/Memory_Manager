SECTIONS { 
	ENTRY(load_func_struct)
   .text : { 
	   /*LONGADDR and ADDR are different somehow */
	. = ALIGN(4);
	
	LONG(ADDR(.text));
	LONG(SIZEOF(.text));
	LONG(ADDR(.data));
	LONG(SIZEOF(.data));
	LONG(ADDR(.bss));
	LONG(SIZEOF(.bss));
	
	text_offset = .  ;
	/*text_length = len(.text );
	//data_offset
	data_length = len(.data);
	bss_offset
	bss_length = len(.bss)
	*/

	load_func_struct = . ;

	*(.text)  } 
  .data : { *(.data) } 
  .bss :  { *(.bss)  *(COMMON) } 

} 