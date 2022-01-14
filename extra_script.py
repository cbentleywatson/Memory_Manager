Import("env")
# short library names may take up less space. There's a limit to the length of wpiff file names.
from logging import root
import os
import subprocess
import shutil
import glob
# Example of how to find time of last modification of a file:
import sys, string, os
from pathlib import Path, PurePath

# Each library that is to be moved into long term storage is going to be give a descriptor in the form of a dictionary.
# Right now the onlu thing that matters is the name of the folder the library source code is located which will be used to hunt down the compiled object file

board_folder_name = "firebeetle32"
test_1_lib_data = {
	"folder_name" : "test_void_func_load"
	 }
simple_lib ={
    "folder_name" : "simple_lib_d"
}



libs_to_load = [ 
	test_1_lib_data, simple_lib
]
# Next, you would look for the corresponding compiled library in .pio/build/firebeetle32



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

# For each name in the lib dict



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


def get_lib_path(rootdir1, lib_folder):
    print("get_lib test:")
	# for folder each numerical library, check if there is a sub folder corresponding to the lib_name we're loooking for

    for path in glob.glob(f'{rootdir}/*/*',recursive=True):
        if lib_folder in path:
            print(path)
    
    for rootdir1, dirs, files in os.walk(rootdir1):
        for subdir in dirs:
            print(subdir)
            for rootdir2, dirs2, files2 in os.walk(rootdir + "/" +subdir):
                print("this is sub dir 2")
                for subdirs2 in dirs2:
                    print(subdirs2)
                    # this is successfully giving us the name of the 

                    if subdirs2 == lib_folder:
                        # this is the library we are looking for
                        
                        path_to_lib_binary = rootdir + "/" + subdir + "/" +  subdirs2
                        return path_to_lib_binary
            
    return ""
            #get_sub_dirs(subdir)
lib_path = get_lib_path(rootdir,"simple_lib_d")
print("lib_path after test : " + lib_path)
# Once you have the actual library path, you can start grabbing the files from that folder and manipulating them.
# Get file for use, call loader function, place the output in the correct location
def loader(ELF_Contents):
    return {"data" : "" , "Exec" : ""}
def place_exec(content, final_location):
    onboard_extension_for_executable = "_e"
    place(content, final_location, onboard_extension_for_executable)
    print("IN PLACE EXEC")
    return
def place_data(content, final_location):
    onboard_extension_for_data = "_d"
    place(content, final_location, onboard_extension_for_data)
    print("IN PLACE DATA")
    return
def place(content, final_location, extension):
    # if this is modified so that 
    new_elf= open(final_location + extension, "wb")
    n = new_elf.write(content) 
    new_elf.close()
    return 
def get_exec(contents):
    size =0
    offset =0
    return contents[offset, offset+size] 
def read2(content, offset):
    rb = 2^8
    a =  rb^0 * content[offset+ 0]
    b = rb^1 *content[offset +1]
    return a + b
def read4 (content, offset):
    rb = 2^8
    a =  rb^0 * content[offset+ 0]
    b = rb^1 *content[offset +1]
    c = rb^2 * content[offset +2]
    d = rb^3 + content[offset +3]
    return a + b + c + d
 # ELF Header Data
entry_point = 0x18
p_header_start = 0x1C
s_header_offset  = 0x20
size_pheader_entry = 0x2A
size_sheader_entry = 0x3E
pheader_num = 0x2C
num_sec_headers = 0x30

# Pheader data
# all of these are 4 bytes
seg_type =0x00
seg_offset = 0x04
v_addr = 0x08
phys_addr = 0x0C
segment_size_in_file = 0x10
seg_size_in_mem = 0x14
seg_align = 0x1C

def get_text(contents):
    pheader_loc = read4(contents, p_header_start)
    number_of_p_headers = read4(contents,pheader_num)
    


def basic_move(rootdir1, libfolder, file_name, extension_of_compiled_file, path_to_data_folder, loc_files_on_device, onboard_file_name):
    print("\n Begin Basic Move:")
    path_to_lib_binaries = get_lib_path(rootdir1, libfolder)
    if path_to_lib_binaries == "":
        print("Basic Move did nt locate the library: " +path_to_lib_binaries  )
        return -1
    #name_of_cpp_file = libfolder # By default the name of the file to upload will be the same as the name of the folder we want 
    #extension_of_compiled_file = ".o"
    main_object_file_path = path_to_lib_binaries  + "/" + file_name + extension_of_compiled_file

    try:
        ELF_File = open(main_object_file_path, "rb")

    except FileNotFoundError:
        print("Elf file "+ main_object_file_path + "Not FOUND!")
        return -1 
    #ELF_File = open(main_object_file_path, "r")

    #relative_path = path_to_data_folder + loc_files_on_device # if you finish a path to a directory with a slash and a file without it, you can make ell the difference between a  directory and a file
    # Path to data folder tells the function which folder gets loaded onto the device
    # loc_file_s on the device gives the location in the devices file directory where the files will be saved. "/" puts it in root, "/some_dir/child_dir/" puts the the file in the child dir directory. Note the trailing slash.
    # File_name gives the name of the file as it will be seen on the device 
    # you can modify this with so that you can place a string into a file
    # final location
    #ELF_File = open(main_object_file_path, "r") 
    all_contents = ELF_File.read()
    #ELF_File.close()
    onboard_lib_name = path_to_data_folder + loc_files_on_device + onboard_file_name
    print("Final Location: " + onboard_lib_name)  
    # this Still has _d.cpp.o attached. 
    #new_elf= open(final_location , "wb")
    #all_contents ="a"
    #n = new_elf.write(all_contents) 
    #new_elf.close()
    print("Before Place_exec")
    
    # Final Location actually gives the name file as it will be seen on the device
     
    # Modify final location to remove .cpp 
    n = place_exec(content=all_contents, final_location=onboard_lib_name)
    place_data(all_contents, onboard_lib_name)


    # place exec place executable stuff in a labeled executable file, so now the focus can moe to building the functions that will slice up the elf file into useable pieces. 



    #place exec now 
    
    
    # Could be simplified to a place function
    # the entire contents of the elf file has been moved into a single file in the data directory.
    # We need to split the file up into more files 
    return n
    # Create a new file
        # copy all the lines into a string.
    # Check if the file is present and if so, process and load the file
    # Load the ex code into the elf thing, then load the data in; 

def default_move(rootdir1, libfolder):
    name_of_cpp_file = libfolder + ".cpp" # By default the name of the file to upload will be the same as the name of the folder we want 
    extension_of_compiled_file = ".o"
    # You Need to put the elf file in their own directory on the device
    # onboard name
    default_onboard_name = libfolder
    basic_move(rootdir1, libfolder, name_of_cpp_file, extension_of_compiled_file, path_to_data_folder = "data",  loc_files_on_device="/ELF_Files/",onboard_file_name=default_onboard_name)
    return ""


#default_move(rootdir, "simple_lib_d")
def load_all_libs(list_of_libs, project_root):
    for lib in list_of_libs:
        default_move(project_root, lib["folder_name"])

load_all_libs(libs_to_load, rootdir)
# You can call Default move on every member of the load libs list and tety

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