# Memory_Manager
The Memory Manager is designed to circumvent the limits on program size on the esp-32 due to the flash capacity.

It's designed to be integrated into the PlatformIO IDE in VSCode, where it's connected to the conected to the automatic build system. Target libraries (the ones that should not be part of the main program located on flash)are compiled into the main program at a specific virtual address, and then the section is taken out of the elf file containing the main program so that the section doesn't take up flash space. PlatfomIO includes the option to automatically place files from  the /data directory into the file system when the build system is activated, so the sections are placed in this folder. When the project is finished there will be another folder that automatically loads onto the SD cards file system, but the SPIFFS file system can also be used. 

Dynamically loaded files are typically split into two files, one with data and bss, and the other with executable code. When a dynamic library is loaded these two files are labeled with a pseudo extension, meaning that _e is added to the name of the exectuable section and _d is added to data section.

 The end result is that the section containing the exectuable code for the library is stored in a file but doesn't take up space in the flash. If the library section is loaded onto an SD card the maximum code space is basically infite compared to the current maximum code size on the ESP-32. Current test boards use 64 gigabyte SD cards, so the increase in code space is a factor of four thousand. Most programs that use this system will probbly need a lot of long term storage capacity and so this is an over estimate.

The main use case right now is data analysis on systems with cameras and other sensors that collect a lot of data. An example is a program that includes an AI algorithm based on the Tensor Flow Embedded system and uses a camera to collect video. The ESP-32 Cam board is an example of that type of system.

The shared library functions are ideally used with boards that have external PSRAM. When the memory manager's dynamic library are loaded they're placed into IRAM, which is only 500 KB on ESP-32s without external RAM. Placing the dynamically loaded code sections into flash will also be possible, but since flash memory can be worn out if too many writes are performed (about 100K) this isn't ideal.

Using external PSRAM also increases the maximum possible code memory; up to 4 MB can be used on boards with 8MB flash chips because the first 4MB are typically mapped into data ram address space. Using the 4MB external instruction ram is only possible if external flash is disabled when during RAM use (as of now) because the two chips used the same SPI cache.  
 
 The system is also designed to load the dynamic code sections as c++ objects. It's also possible to create wrapper functions on a memory manager object so that individual functions can be loaded into the system. 
 
 The system uses an extra script specified in platformioIO.ini file. This file will be given a better name in the future, but right now it's just called extra_script.py.
 
 You should modify the memory manager object file as little as possible because it's very easy to make changes to the memory functions that cause FreeRTOS core panics. These core panics are usually due to accessing exec memory with out 4 byte alignments. Memcopy can cause this easily and so can some single byte accesses. If the exec ram functions are called in the wrong place the system will load a 4 byte instruction that may not exist which also causes a core panic. Use the memory managers built in memory management functions to prevent this; they wrap up the details of proper memory accesses so that the memory can be accessed as safely as possible.
 
 
 





