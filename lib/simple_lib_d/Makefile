# removed the -s flag to put the symbol table back in the file.
# Call linker Script: -Wl,-T linker_simple.txt ; This was removed because with visible symbold you can find all the functions without breaking them into different sections and reloting everything piece by piece.
# Flags from old version: "-Wl,--gc-sections", "-Wl,-flto", "-fpermissive"     "unflags": [ "-g3",   "-g"

# the gc sections version won't load 
# Goal: Allow inclusion of headers with many fuct

# , -Wl,-flto
#-Wl,-T linker_simple.txt -Wl,-static -Wl,-flto 
# the additional flags may not actually be needed

# This deals with the extra includes fine as long as there aren't any 
#  -mlongcalls -mtext-section-literals 
# the long call flags converted ld function into a single lsi 
#  -Wl,-T linker_simple.txt
# 
output_name=simple_lib_d.o
input_files=simple_lib.cpp
std_pio_flags=-fno-rtti -fno-exceptions -std=gnu++11 -fpic -Os -Wall -nostdlib -Wpointer-arith -Wno-error=unused-but-set-variable -Wno-error=unused-variable -mlongcalls -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -Wno-error=deprecated-declarations -Wno-error=unused-function -Wno-unused-parameter -Wno-sign-compare -fstack-protector -fexceptions -Werror=reorder  
inclusion_flags=-fno-rtti -fno-exceptions -std=gnu++11 -Os -Wall -nostdlib -Wpointer-arith -Wno-error=unused-but-set-variable -Wno-error=unused-variable -mlongcalls -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -Wno-error=deprecated-declarations -Wno-error=unused-function -Wno-unused-parameter -Wno-sign-compare -fstack-protector -fexceptions -Werror=reorder  

manager_specific_flags=-fpermissive  -Wl,-static,  -Wl,-flto  -mlongcalls -mtext-section-literals
g++_version=xtensa-esp32-elf-g++.exe
# Just symbols includes the 
junk_funcs: junk_func.cpp junk_funcs.h
	$(g++_version) -o junk_lib.o $(std_pio_flags) junk_func.cpp junk_funcs.h
	ar crv junk_lib.a junk_lib.o
test_inclusion: test_inclusion Makefile simple_lib.h
	$(g++_version) -o include_lib.o $(inclusion_flags) $(manager_specific_flags) -Wl,-no-pie test_inclusion.cpp  -L junk_lib.a

simple_lib: simple_lib.cpp junk_func.cpp junk_funcs.h Makefile simple_lib.h
	$(g++_version) -o $(output_name) $(std_pio_flags) $(manager_specific_flags) -Wl,-T linker_simple.ld -Wl,--just-symbols=include_lib.o $(input_files) -L junk_lib.a
