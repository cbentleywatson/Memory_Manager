# removed the -s flag to put the symbol table back in the file.
# Call linker Script: -Wl,-T linker_simple.txt ; This was removed because with visible symbold you can find all the functions without breaking them into different sections and reloting everything piece by piece.
output_name=simple_lib.o
std_pio_flags=-fno-rtti -fno-exceptions -std=gnu++11 -fpic -Os -Wall -nostdlib -Wpointer-arith -Wno-error=unused-but-set-variable -Wno-error=unused-variable -mlongcalls -ffunction-sections -fdata-sections -fstrict-volatile-bitfields -Wno-error=deprecated-declarations -Wno-error=unused-function -Wno-unused-parameter -Wno-sign-compare -fstack-protector -fexceptions -Werror=reorder  
manager_specific_flags=-fpermissive  -Wl,-T linker_simple.txt -fwhole-program 
g++_version=xtensa-esp32-elf-g++.exe
simple_lib: simple_lib.cpp
	$(g++_version) -o $(output_name) $(std_pio_flags) $(manager_specific_flags) simple_lib.cpp