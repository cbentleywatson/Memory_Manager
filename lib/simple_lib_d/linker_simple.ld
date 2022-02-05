SECTIONS { 
	ENTRY(start)
   .text : { 
	   /*LONGADDR and ADDR are different somehow */
	. = ALIGN(4);
	. =0x4000;
	/*LONG(ADDR(.text));
	LONG(SIZEOF(.text));
	LONG(ADDR(.data));
	LONG(SIZEOF(.data));
	LONG(ADDR(.bss));
	LONG(SIZEOF(.bss));
	
	text_offset = .  ;
	*/
	/*text_length = len(.text );
	//data_offset
	data_length = len(.data);
	bss_offset
	bss_length = len(.bss)
	*/

	start = . ;

	*(.text)  } 
  .data : { *(.data) } 
  .bss :  { *(.bss)  *(COMMON) } 

} 