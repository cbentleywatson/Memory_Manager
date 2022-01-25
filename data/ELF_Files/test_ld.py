#from http.server import executable
#from logging import root
#from operator import truediv
import os
#import subprocess
#import shutil
#import glob
#from symtable import symtable
# Example of how to find time of last modification of a file:
#import sys, string, os
#from pathlib import Path, PurePath


def process_lib():
    # Take a path to a library file and then process it until it's read to be sliced up for loading.
    
    """
    ld_path = "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.exe"
    """
    ld_path  = "../../Linker_Experiments/ld.exe"
    ld_script = "memory_manager_processing_script.ld"
    ld_options = " -r -d "
    entry_name = "call"
    # since the cleaned library replaces the
    lib_path = "simple_lib_d_all"
    temp_lib_path =  lib_path+ "_f"
    total_command = ld_path + " -o "  +temp_lib_path +" -e " + entry_name + " "  + lib_path + " " + ld_options + " -T " + ld_script
    print("Total Command: " + total_command ) 
    os.system(total_command)
    #os.system("mv " + temp_lib_path+ " " + lib )
    return temp_lib_path

process_lib()
