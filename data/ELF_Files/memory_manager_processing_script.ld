

	/*Start -32 gives the LMA of the segment.  The first function starts at zero in the segment Now. Do Not Modify this Script. *?
	/*VMA Variable -LMA segment = offset to modify the variable */
	/*  load func struct is the starting  function. Replace both references with the new variable to specify a new start*/
ENTRY(call);


/* This is equivalent to the -d command, which is already in the python flags section */
FORCE_COMMON_ALLOCATION;
PHDRS
{
	exec PT_LOAD ;
	data_ram PT_LOAD ;
	
	
}

SECTIONS {
	
	/*_dummy =*/ 
/*	. = SIZEOF_HEADERS;*/

   
   /*ENTRY(load_func_struct);*/
	. = ALIGN(4);
	  

/* In the original file, start is an actual function; users probably shouldn't need to define a start function to make this work though*/
/* Stick absoe */	
	.text 0x10000 :  {
	   call = . ;

 	*(.literal*)
	*(.text*) 
	*(.rodata*) /* This may need to move if esp32 architecture means these can't be accessed */




	/*LONG(ADDR(.data));*/

	/* Either the function ends up at 11c (on start address) and 10C VMA/LMW and 114 in offset
		PHeader lists offset P4 and LMA/VM 8c and c4 for the offset 8c for LMA and VMA
		If section assigned in text, start address offset 8c, VMA/LMA/PADDR 8c
	*/
	/*_text_offset_from_linker= LONG(SIZEOF(.text));*/
	/*_text_offset = ABSOLUTE(.text);*/

	/*
	_data_offset = ADDR(.data);
	_data_length = SIZEOF(.data);
	*/
	 } :exec
/* Everything  that needs to go in the data ram goes in here */
  .data 0x1000 : { 	*(.data*)
	
	*(.bss*) 
	 *(COMMON) 
	   }  :data_ram
    /* >rom_fake   .bss :  { *(.bss*)  *(COMMON) } :data_ram*/

	   
  /DISCARD/ : { *(.xt.prop) *(.comment) *(.eh_frame) *(.xt.lit) *(.dynstr) }

  	/*
	_ele[0] = ADDR(.text);
	_ele[1] = SIZEOF(.text);

*/
} 

