	/*Start -32 gives the LMA of the segment.  The first function starts at zero in the segment Now. Do Not Modify this Script. *?
	/*VMA Variable -LMA segment = offset to modify the variable */
	/*  load func struct is the starting  function. Replace both references with the new variable to specify a new start*/
ENTRY(load_func_struct);
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
   .text : {
	   
	   load_func_struct = . ;
	   start = load_func_struct ;
	   
	   /*  the function we want to make the entry is assigned to "." and . represents the current address  The entry point is then set equal to the address of . which is now equal to the first address in the section. Since the text section is the only thing in the executable segment the starting function can be loacted by loading the header and finding the correct segment, or by calling the first bytes in the executable code file/segment */
	
	/* These Start and call things are the moset questionable. They're suppo*/
	
	/*call = . ;*/ 
	/*start = load_func_struct +56;*/
	/*start = call ;*/
	/*call;*/

	/* 8c +34 =10C *?
	/*c4-34 =8c;  offset - header size = LMA; Symbol table lists offset as VMA, which means to find the address after cutting, you need to subtract the LMA on segment table from the LMA listed in the symbol table. That gives you 8c -8c, which is zero */   

	/* SNip From Physical offset. R */
	
	
	*(.text*) 

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
  .data : { 	*(.data*) } :data_ram
    .bss :  { *(.bss*)  *(COMMON) } :data_ram
  /DISCARD/ : { *(.xt.prop) *(.comment) *(.eh_frame) *(.xt.lit) *(.dynstr) }

  	/*
	_ele[0] = ADDR(.text);
	_ele[1] = SIZEOF(.text);

*/
} 