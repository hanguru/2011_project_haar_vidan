/*STARTUP(crt0.o)*/
ENTRY(_start)
/*OUTPUT_ARCH(or32)*/
OUTPUT_ARCH(ba:ba2) 
/*GROUP(-lor32 -lc -lgcc)*/
GROUP(-lc -lgcc)
SEARCH_DIR(.)
__DYNAMIC  =  0;

MEMORY
{
   vectors      : ORIGIN = 0, LENGTH = 0x2000
   vectors2     : ORIGIN = 0xf10a4000, LENGTH = 0x00000080
   rom          : ORIGIN = 0xf10a4080, LENGTH = 0x0002ff80
   ram          : ORIGIN = 0x02008000, LENGTH = 0x00018000
   internalrom  : ORIGIN = 0x02000000, LENGTH = 0x00008000
}


/*
 * Allocate the stack to be at the top of memory, since the stack
 * grows down.
 */
PROVIDE (_stack = 0x02008000 + 0x00018000 -4);
PROVIDE (__stack = 0x02008000 + 0x00018000 -4);

SECTIONS
{  
   .vectors :
   {
      *(.vectors)
   } > vectors
                              
   .vectors2 :
   {
      *(.vectors2)
   } > vectors2

   .internalrom :
   {
      *(.internalrom)
   } > internalrom

   .text : {
      stext = .;
      _stext = .;
      common/crt0.o(.text)
      *(.text)
      _etext  =  .;
      __CTOR_LIST__ = .;
      LONG((__CTOR_END__ - __CTOR_LIST__) / 4 - 2)
      *(.ctors)
      LONG(0)
      __CTOR_END__ = .;
      __DTOR_LIST__ = .;
      LONG((__DTOR_END__ - __DTOR_LIST__) / 4 - 2)
      *(.dtors)
      LONG(0)
      __DTOR_END__ = .;
      *(.lit)
      *(.shdata)
      _endtext = .;
   }  > rom

   .rodata : {
      *(.rodata);
   } > rom

   .rodata.cst4 : {
      *(.rodata.cst4);
   } > rom

   .rodata.str1.1 : {
      *(.rodata.str1.1);
   } > rom
   
   .shbss :
   {
      *(.shbss)
   } > rom
   
   .talias :
   { 
      _RO_Limit  =  ALIGN(0x4);
   }  > rom
   
   .data : {
      sdata  =  .;
      _sdata  =  .;
      *(.data)
      edata  =  .;
      _edata  =  .;
   } > ram
   
   .end_mark SIZEOF(.data) + ADDR(.data) :
   {
      *(.end_mark)
   } > ram
   
   .rwlimit :
   {
      _RW_Limit  =  ALIGN(0x4);
   } > ram
  
   .bss SIZEOF(.data) + ADDR(.data) + SIZEOF(.end_mark) :
   /*.bss :*/
   {
      /*_start_data_dest = .;
      . += SIZEOF(.data);
      _end_data_dest = .;  */
      
      sbss = . ;
      _sbss = . ;
      __bss_start = ALIGN(0x8);
      ___bss_start = ALIGN(0x8);
      *(.bss)
      *(COMMON)
      *(.scommon) 
      end = ALIGN(0x8);
      _end = ALIGN(0x8);
      __end = ALIGN(0x8);
      ebss = .;
      _ebss = .;
   } > ram
   
   .stab  0 (NOLOAD) : 
   {
      [ .stab ]
   }
   
   .stabstr  0 (NOLOAD) :
   {
      [ .stabstr ]
   }


}
