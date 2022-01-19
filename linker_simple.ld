PHDRS
{
	
	data_ram PT_LOAD ;
	mine PT_LOAD ;
	
}

SECTIONS { 
	/*_dummy =*/ 
/*	. = SIZEOF_HEADERS;*/
	. = 60; 
   start = load_func_struct;
   /*ENTRY(load_func_struct);*/
	. = ALIGN(4);
	  
  .bss :  { *(.bss)  *(COMMON) } :data_ram
  .data : { 	*(.data) } :data_ram
   .text : { 
	
	*(.text) 

	/*LONG(ADDR(.data));*/

	
	/*_text_offset_from_linker= LONG(SIZEOF(.text));*/
	_text_offset = ADDR(.text);
	/*
	_data_offset = ADDR(.data);
	_data_length = SIZEOF(.data);
	*/
	_text_length = SIZEOF(.text);
	 } :mine

  /DISCARD/ : { *(.xt.prop) *(.comment) *(.eh_frame) *(.xt.lit) *(.dynstr) }

  	/*
	_ele[0] = ADDR(.text);
	_ele[1] = SIZEOF(.text);

*/
} 