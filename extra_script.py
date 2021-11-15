Import("env")
# short library names may take up less space. There's a limit to the length of wpiff file names.
import os
import subprocess
import shutil
import glob
# Example of how to find time of last modification of a file:
import sys, string, os
from pathlib import Path, PurePath
 #arcgisscripting
#os.('./bash.SH)

 # This is an example of how to copy a compiled file into the data elf directory for automatic upload. Later it can be put in a loop so it can find the files targeted by .
current_windows_directory= os.getcwd

name_of_this_file="extra_script.py"
path_to_project="/mnt/c/Users/cbent/Dropbox/My PC (DESKTOP-BPMMLR8)/Desktop/Senior_Project/Code"
#path_to_project_win = "c:\Users\cbent\Dropbox\My PC (DESKTOP-BPMMLR8)\Desktop\Senior_Project\Code"
project_name ="Firebeetle_Memory_Manager"
path_to_lib_folder=".pio/build/firebeetle32"
library_numeric_name = "liba42"
library_name="simple_lib"
extension="_d.cpp.o"

dynamic_lib_extension ="_d"

data_elf_file_dir="ELF_Files" # no slashes needed here just the name of the subdirectory to stick the .o file in. I guess an empty string would put it in data directly

absolute_library_path = path_to_project+"/"+project_name +"/" +path_to_lib_folder+"/"+library_numeric_name+"/"+library_name+"/"+library_name+ dynamic_lib_extension+extension

copy_lib_elf_to_this_location = path_to_project+"/"+project_name +"/data"+"/"+data_elf_file_dir +"/" + library_name + dynamic_lib_extension
path_to_compiled_lib_directory = path_to_project+"/"+project_name +"/" + path_to_lib_folder
path_to_this_script_file = path_to_project + "/" + name_of_this_file

# use this to reduce recompiles if need be
#last_update_time_of_this_script_file = os.path.getmtime(path_to_this_script_file)

# Search for dynamic libs:

# *_d.cpp.o
print("in script")
print("path to compiled lib: ")
print(path_to_compiled_lib_directory)
print("Current Directory: ")
print(os.getcwd() )
path_to_project_win = Path("C:/Users/cbent/Dropbox/My PC (DESKTOP-BPMMLR8)/Desktop/Senior_Project/Code"+"/"+project_name+"/"+path_to_lib_folder) #Path(os.getcwd())
print("Walk output: ")
# for root, dirs, files in os.walk( path_to_project_win, topdown=False):
#    for name in files:
#       print(os.path.join(root, name))
#    for name in dirs:
#       print(os.path.join(root, name))
# print("Dir lists: ")
#for file in os.listdir(path_to_project_win): # nu
    #print(dir)
    
    #os.path.join(path_to_project_win,file):
rootdir="C:/Users/cbent/Dropbox/My PC (DESKTOP-BPMMLR8)/Desktop/Senior_Project/Code/Firebeetle_Memory_Manager/.pio/build/firebeetle32"
#for rootdir, dirs, files in os.walk(rootdir):
#    for subdir in dirs:
#        print(os.path.join(rootdir, subdir))
lib_extension ="_d.cpp.o"
a=1
def get_sub_dirs(rootdir1):
    a=1
    for rootdir1, dirs, files in os.walk(rootdir1):
        for subdir in dirs:
            get_sub_dirs(subdir)
        for file in files:
            if lib_extension in file:
                #print(file)
                a=a+1
get_sub_dirs(rootdir)


print("\noriginal rootdir path: ")
print(rootdir)
####
# Change dir code:
print("Test Path:")
# this line Works. DO NOT LOSE IT
#test_path= os.getcwd() +"/.pio/build/firebeetle32"
ext = "/.pio/build/firebeetle32"
test_path= os.getcwd() + ext #+"/.pio/build/firebeetle32"
print(test_path) 

print("\nmodified root dir: ")
rootdir = test_path
print(rootdir)
proj_root =os.getcwd()
print("\n\n\n globdir")

def move_lib(lib_path, proj_root, elf_dir, final_lib_extension):
    base_file_name_only = os.path.basename(lib_path)
    library_name_no_extension =base_file_name_only.replace("_d.cpp.o", "")
    final_lib_location=proj_root+ "/"+"data"+  "/" + elf_dir +"/"+ library_name_no_extension + final_lib_extension
    print("in move")
    shutil.copyfile(os.path.abspath(lib_path), final_lib_location)
# first gives libs, the numbered ones. Second gives named libs, third gives files
for path in glob.glob(f'{rootdir}/*/*/*_d.cpp.o',recursive=True):
    #print(path)
    if lib_extension in path:
        move_lib(path,proj_root,data_elf_file_dir,dynamic_lib_extension)
        # copy the line from move down so final location is defined here(?)
        # then do the rest of the processing in here as we come to the files.
        print(path)
#for path in glob.glob(f'{rootdir}/*/')

#     for namedir in os.listdir(numdir): 
#         print(namedir)
#         for filename in os.listdir(numdir):
#             if filename.endswith("_d.cpp.o"):
#                 print(filename)
#files = glob.glob(("C:/Users/cbent/Dropbox/My PC (DESKTOP-BPMMLR8)/Desktop/Senior_Project/Code" +"**/*.o", recursive= True )

# for path in glob.glob(current_windows_directory + "/**", recursive=True):
#     print("in loop: My print:")
#     print(path)
#     source = path
#     base_file_name_only = os.path.basename(path)
#     library_name_no_extension =base_file_name_only.replace("_d.cpp.o", "")
#     print(library_name_no_extension)
#     print(base_file_name_only)
# #                                 # I decided to make it possible to make it possible to change the file extensions. It might be better for them to be short
#     print("Copy lib here: ")
#     copy_lib_elf_to_this_location =path_to_project + "/" +project_name + "/"+"data"+  "/" + data_elf_file_dir +"/"+ library_name_no_extension + extension
#     print(copy_lib_elf_to_this_location)
#     shutil.copyfile(path, copy_lib_elf_to_this_location)



#env.Replace(
#    UPLOADER="executable or path to executable",
#    UPLOADCMD="$UPLOADER $UPLOADERFLAGS $SOURCE"
#)

# In-line command with arguments
#env.Replace(
#    UPLOADCMD="executable -arg1 -arg2 $SOURCE"
#)

#code to uploarun
#--target buildfs --environment firebeetle32
#run --target uploadfs --environment firebeetle32

# Python callback
def on_upload(source, target, env):
    print(source, target)
    firmware_path = str(source[0])
    # do something
    env.Execute("executable arg1 arg2")
def after_upload(source, target, env):
    print("after_upload")
    # this line is 
    
    os.system("cp absolute_library_path copy_lib_elf_to_this_location")
    os.system("pio run --target uploadfs --environment firebeetle32")

# this one is the error    

ar_path =       "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ar.exe"
as_path =       "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/as.exe"
ld_bfd_path =   "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.bfd.exe"
ld_path =       "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.exe"
nm_path =       "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/nm.exe"
objcopy_path =  "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/objcopy.exe"
objdump_path =  "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/objdump.exe"
ranlib_path =   "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ranlib.exe"
strip_path =    "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/strip.exe"

os.system("c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.exe C:/Users/cbent/a.txt")
# g++ path
#print(env.compatlib )
# SConsenvironment variable 
# "C:\Users\cbent\.platformio\packages\tool-scons\scons-local-4.2.0\SCons\Script\SConscript.py", line 597:     
#    return _SConscript(self.fs, *files, **subst_kw)
#"C:\\Users\\cbent\\.platformio\\packages\\toolchain-xtensa32\\bin\\xtensa-esp32-elf-g++.exe"