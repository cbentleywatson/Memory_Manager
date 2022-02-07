Import("env")
# short library names may take up less space. There's a limit to the length of wpiff file names.
from http.server import executable
from logging import root
from operator import truediv
import os
import subprocess
import shutil
import glob
from symtable import symtable
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
single_func_lib = {
    "folder_name" : "single"
}



libs_to_load = [ 
	test_1_lib_data, simple_lib, single_func_lib
]
# Next, you would look for the corresponding compiled library in .pio/build/firebeetle32



 #arcgisscripting
#os.('./bash.SH)

 # This is an example of how to copy a compiled file into the data elf directory for automatic upload. Later it can be put in a loop so it can find the files targeted by .
current_windows_directory= os.getcwd

name_of_this_file="extra_script.py"
tools_path = "Linker_Experiments/"
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

#def loader(ELF_Contents):
#    return {"data" : "" , "Exec" : ""}
def place_exec(content, final_location):
    onboard_extension_for_executable = "_e"
    place(content, final_location, onboard_extension_for_executable)
    print("IN PLACE EXEC")
    return
def place_relocation_table(content, final_location):
    onboard_extension_for_rtable = "_r"
    place(content, final_location, onboard_extension_for_rtable)
    print("IN PLACE EXEC")
    return
def place_data(content, final_location):
    onboard_extension_for_data = "_d"
    place(content, final_location, onboard_extension_for_data)
    print("IN PLACE DATA")
    return
def place_symbol_table(content, final_location):
    onboard_extension_for_symbol_table = "_s"
    place(content, final_location, onboard_extension_for_symbol_table)
    print("IN PLACE SYM")
    return
def place_full_elf(content, final_location):
    onboard_extension = "_all"
    
    print("IN PLACE ALL")
    return place(content, final_location, onboard_extension)
def place(content, final_location, extension):
    # if this is modified so that 
    # Shouldn't this not place an empty file?

    new_elf= open(final_location + extension, "wb")
    n = new_elf.write(content) 
    new_elf.close()
    return final_location +extension
def get_exec(contents):
    size =0
    offset =0
    return contents[offset, offset+size] 
def read2(content, offset):
    rb = 256
    a =  1 *content[offset+ 0]
    #print("a = " + hex(a))
    b = rb * content[offset +1]
    #print("b byte value = " + hex(content[offset+1]) )
    #print("b total  value: " + hex(b) )
    final = a +b 
    #print("Sum final hex: " + hex(final) + " Sum final Dec: " + str(final) )
    return final
def read4 (content, offset):

    rb = 256
    a =  rb^1 * content[offset+ 0]
    e = content [offset : offset+4]
    retval2 = int.from_bytes(e, "little")
    
    a1 = b'x\21'
    a1 =content[offset +0]
    #int_val_a  = int.from_bytes(content[
   
    b = rb^1 * content[offset +1]
    c = rb^2 * content[offset +2]
    d = rb^3 * content[offset +3]
    #print("a: " +hex (content[offset[0]]) + " b: "+ hex(b) + " c: " + hex(c) + " d: " + hex(d))
    final = a + b + c + d
    return retval2
 # ELF Header Data


entry_point_offset = 0x18
p_header_start = 0x1C
s_header_offset_offset  = 0x20 #0x28
size_pheader_entry_offset = 48 #0x30

pheader_num_offset = 0x2C
size_sheader_entry_offset = 0x2E
num_sec_headers_offset = 0x30
elf_header_flags_offset = 0x20

# Pheader data
# all of these are 4 bytes
seg_type =0x00
p_offset_offset = 0x04
v_addr = 0x08
phys_addr = 0x0C
segment_size_in_file_offset = 0x10
seg_size_in_mem = 0x14
seg_align = 0x1C
# program headers have a type, with options for loadable segments, but also for null segments, for the header itself etc.
# We want to get the loadable segments, which have value PT_LOAD
LOADABLE_SEGMENT = 1


# Section Header Info
sflags = 0x08


entry_offset = 0x18
# Section Attributes.  What can this thing do? May be a bit wise comparison
exec_sec = 4
writable_sec = 1
allocatable_sec = 2
shf_strings = 0x20 # Contains null terminated strings
shf_info_link = 0x40 # contains sht index
shf_link_order = 0x80 # Preserve order after combining
shf_group = 0x200 # section is member of a group
shf_tls = 0x400 # Thread local storage
# there are three more processor specific options

# Section Header Types. What type of section is this
shnull = 0  # Unused
sh_progbits = 1 # Program Data
sht_symtab = 2 # Symbol Table
sht_strab = 3 # string table
sht_rela_with_addend = 4  # Relocation Entries WITH addend
sht_hash = 5 # Symbol Hash table
sht_dyanmic = 6 # Dynamic Linking Information
sht_note = 7 # notes
sht_nobits = 8 # program space with no data  i.e. bss
sht_relocation_no_addend = 9 # Relocation entries _NO_
sht_slib = 10 # reserved
sht_dynsym = 0x0B # dynamic linker symbol tabele
sht_init_array = 0x0E # array of constructors
sht_fini_array = 0x0F # array of destructors
sht_preinit_array = 0x10 # array of pre constructors
sht_group =  0x11 # section group
sht_symtab_shndx = 0x12 # extended section indices
sht_num = 0x13 # number of defined types
# sht_loos = 6 0000000


section_offset_offset = 0x10 #sh_offset
section_size_offset = 0x14 #sh_size
elf_type_offset = 0x10
def get_elf_header (contents):
    print ("magic 2: " +str(read2(contents, 0)) )
    pheader_loc = read4(contents, p_header_start)
    number_of_p_headers = read2(contents, pheader_num_offset)
    print("Number of p_headers: "+ str(number_of_p_headers))
    
    size_of_sec_headers = read2(contents, size_sheader_entry_offset )

    num_sec_headers_for_loop = read2(contents, num_sec_headers_offset)
    #
    loc_sec_header_table = read4(contents, s_header_offset_offset)
    size_pheader_entry = read4(contents, size_pheader_entry_offset)
    elf_type = read2(contents, elf_type_offset)
    print("elf type is: " + str(elf_type))
    elf_flags = read4(contents, elf_header_flags_offset)
    header={"number_program_headers": number_of_p_headers, "p_header_offset" : pheader_loc, "number_section_headers" : num_sec_headers_for_loop, "section_header_offset" : loc_sec_header_table, "size_sec_headers": size_of_sec_headers, "ELF_Flags": elf_flags}
    return header

# this Hasn't been included yet
def get_str(contents, offset):
    return ""

    all = contents[offset:]
    
    i =offset
    size = len(contents)
    found = False
    e1 = contents[offset : offset+1]

    while(i<size):
        new_char = contents[i]
        e1 = contents[i:i+1]
        
        new_char_val = int.from_bytes(e1, "little", signed=False)
        print("New Char Val: " + str(new_char_val) + " Hex val: " + hex(new_char_val))
        #a = new_char.decode('ascii')
        if(new_char_val > 127):
            if(i == offset):

                 # print("New char val FAILLL:"+ str(new_char_val) )
                return ""
                i = i+1
                  #return contents[offset:i-1].decode('ascii')

            else:
                found =True
                i = i+1
                break 
        if( new_char_val == 0):
            found = True
            i = i+1
            break
        i = i +1
    if found == True:
        return contents[offset:i].decode('ascii')
    else:
        return ""

    return contents[offset:].partition('\n')[0]

def get_sections(lib_path):
    
    
    try:
        ELF_File = open(lib_path, "rb")
    except FileNotFoundError:
        print("Elf file "+ lib_path + "Not FOUND!")
        return -1 
    
    contents =  ELF_File.read()
    str_contents = bytes(contents)
    ELF_File.close()
    #print ("magic 2: " +str(read2(contents, 0)) )
    pheader_loc = read4(contents, p_header_start)
    number_of_p_headers = read2(contents, pheader_num_offset)
    #print("Number of p_headers: "+ str(number_of_p_headers))
    size_of_sec_headers = read2(contents, size_sheader_entry_offset )
    
    #print("size of Sec header "+ hex(size_of_sec_headers) )

    num_sec_headers_for_loop = read2(contents, num_sec_headers_offset)
    #
    #s_header_offset_offset  = 0x20 #0x28
    loc_sec_header_table = read4(contents, 32)
    size_pheader_entry = read2(contents, size_pheader_entry_offset)
    elf_type = read2(contents, elf_type_offset)
    #print("elf type is: " + str(elf_type))
    elf_flags = read4(contents, elf_header_flags_offset)
    #print("elf flags are: " + str(elf_flags))
    # only segments will be returned
    
    print ("Number of Sections: " + str(num_sec_headers_for_loop))
    print("S Header Offset: "+ str(read4(contents, 32)) )
    sections =[]
    
    for i in range (0, num_sec_headers_for_loop):
        print("i in loop: " + str(i))
        entry_start = loc_sec_header_table + i*size_of_sec_headers
        sflags = 0x10
        section_type_offset =0x04
        section_type =read4(contents, entry_start + section_type_offset)
        section_flags = read4(contents,entry_start + sflags)
        #print ("Section Table Start "+str(loc_sec_header_table ) + " Hex: " + hex(loc_sec_header_table)+  " Entry start: " + str(entry_start))
        # 16 is the offset of the location from the beginning of the section entry
        section_offset = read4(contents, entry_start + section_offset_offset)
        #entry_start = loc_sec_header_table + i*size_of_sec_headers
        section_size =  read4(contents, entry_start +   section_size_offset )

        section_contents = contents[section_offset: section_offset+section_size]
        cur_section = {"section_size" : section_size, "section_offset": section_offset, "section_contents" : section_contents, "section_flags" : section_flags, "section_type" : section_type }
        sections.append(cur_section)
        #print("section offset: " + str(section_offset), "Hex: " + hex(section_offset))
        #print( "Section Flags: " + str(section_flags))
        #Section Name is the firt entry so it doesn't need an additional offset
        section_name_offset = read4(contents, entry_start)
        #print ("Section Name: " + get_str(contents, section_name_offset )) # no strictly needed
        
        executable_instr = 4
        if(section_offset == 52):
            print("First Section Found!!!!!")
        if(section_flags == executable_instr):
            print("Section Contents Found")
            return section_contents
    print("Finished Section Loop")

    return sections

def get_sections_content(contents):
    
    """
    try:
        ELF_File = open(lib_path, "rb")
    except FileNotFoundError:
        print("Elf file "+ lib_path + "Not FOUND!")
        return -1 
    
    contents =  ELF_File.read()
    str_contents = bytes(contents)
    ELF_File.close()
    """
    #print ("magic 2: " +str(read2(contents, 0)) )
    pheader_loc = read4(contents, p_header_start)
    number_of_p_headers = read2(contents, pheader_num_offset)
    #print("Number of p_headers: "+ str(number_of_p_headers))
    size_of_sec_headers = read2(contents, size_sheader_entry_offset )
    
    #print("size of Sec header "+ hex(size_of_sec_headers) )

    num_sec_headers_for_loop = read2(contents, num_sec_headers_offset)
    #
    #s_header_offset_offset  = 0x20 #0x28
    loc_sec_header_table = read4(contents, 32)
    size_pheader_entry = read2(contents, size_pheader_entry_offset)
    elf_type = read2(contents, elf_type_offset)
    #print("elf type is: " + str(elf_type))
    elf_flags = read4(contents, elf_header_flags_offset)
    #print("elf flags are: " + str(elf_flags))
    # only segments will be returned
    
    print ("Number of Sections: " + str(num_sec_headers_for_loop))
    print("S Header Offset: "+ str(read4(contents, 32)) )
    sections =[]
    
    for i in range (0, num_sec_headers_for_loop):
        print("i in loop: " + str(i))
        entry_start = loc_sec_header_table + i*size_of_sec_headers
        sflags = 0x10
        section_type_offset =0x04
        section_type =read4(contents, entry_start + section_type_offset)
        section_flags = read4(contents,entry_start + sflags)
        #print ("Section Table Start "+str(loc_sec_header_table ) + " Hex: " + hex(loc_sec_header_table)+  " Entry start: " + str(entry_start))
        # 16 is the offset of the location from the beginning of the section entry
        section_offset = read4(contents, entry_start + section_offset_offset)
        #entry_start = loc_sec_header_table + i*size_of_sec_headers
        section_size =  read4(contents, entry_start +   section_size_offset )

        section_contents = contents[section_offset: section_offset+section_size]
        cur_section = {"section_size" : section_size, "section_offset": section_offset, "section_contents" : section_contents, "section_flags" : section_flags, "section_type" : section_type }
        sections.append(cur_section)
        #print("section offset: " + str(section_offset), "Hex: " + hex(section_offset))
        #print( "Section Flags: " + str(section_flags))
        #Section Name is the firt entry so it doesn't need an additional offset
        section_name_offset = read4(contents, entry_start)
        print ("Section Name: " + get_str(contents, section_name_offset ))
        
        executable_instr = 4
        if(section_offset == 52):
            print("First Section Found!!!!!")
        if(section_flags == executable_instr):
            print("Section Contents Found")
            return section_contents
    print("Finished Section Loop")

    return sections

def get_segments(lib_path):
    try:
        ELF_File = open(lib_path, "rb")
    except FileNotFoundError:
        print("Elf file "+ lib_path + "Not FOUND!")
        return -1 
    
    contents =  ELF_File.read()
    str_contents = bytes(contents)
    ELF_File.close()
    #print ("magic 2: " +str(read2(contents, 0)) )
    pheader_loc = read4(contents, p_header_start)
    number_of_p_headers = read2(contents, pheader_num_offset)
    #print("Number of p_headers: "+ str(number_of_p_headers))
    size_of_sec_headers = read2(contents, size_sheader_entry_offset )
    
    #print("size of Sec header "+ hex(size_of_sec_headers) )

    num_sec_headers_for_loop = read2(contents, num_sec_headers_offset)
    #
    #s_header_offset_offset  = 0x20 #0x28
    loc_sec_header_table = read4(contents, 32)
    size_pheader_entry = read2(contents, size_pheader_entry_offset)
    elf_type = read2(contents, elf_type_offset)
    #print("elf type is: " + str(elf_type))
    elf_flags = read4(contents, elf_header_flags_offset)
    #print("elf flags are: " + str(elf_flags))
    # only segments will be returned
    """
    print ("Number of Sections: " + str(num_sec_headers_for_loop))
    print("S Header Offset: "+ str(read4(contents, 32)) )
    sections =[]
    
    for i in range (0, num_sec_headers_for_loop):
        print("i in loop: " + str(i))
        entry_start = loc_sec_header_table + i*size_of_sec_headers
        sflags = 0x10
        section_flags = read4(contents,entry_start + sflags)
        #print ("Section Table Start "+str(loc_sec_header_table ) + " Hex: " + hex(loc_sec_header_table)+  " Entry start: " + str(entry_start))
        # 16 is the offset of the location from the beginning of the section entry
        section_offset = read4(contents, entry_start + section_offset_offset)
        #entry_start = loc_sec_header_table + i*size_of_sec_headers
        section_size =  read4(contents, entry_start +   section_size_offset )

        section_contents = contents[section_offset: section_offset+section_size]
        cur_section = {"section_size" : section_size, "section_offset": section_offset, "section_contents" : section_contents}
        sections.append(cur_section)
        #print("section offset: " + str(section_offset), "Hex: " + hex(section_offset))
        #print( "Section Flags: " + str(section_flags))
        #Section Name is the firt entry so it doesn't need an additional offset
        section_name_offset = read4(contents, entry_start)
        print ("Section Name: " + get_str(contents, section_name_offset ))
        
        executable_instr = 4
        if(section_offset == 52):
            print("First Section Found!!!!!")
        if(section_flags == executable_instr):
            print("Section Contents Found")
            return section_contents
    print("Finished Section Loop")
    """
    segments = []
    for i in range (0, number_of_p_headers):
        print("In Segmentation Search loop with index = " +str(i) )
        entry_start = pheader_loc + i * size_pheader_entry
        segment_type = read4(contents, entry_start + 0)
        segment_offset = read4(contents, entry_start + p_offset_offset )
        segment_size_in_file = read4(contents, entry_start +segment_size_in_file_offset)
        this_segment = contents[segment_offset: segment_offset +segment_size_in_file]
        
        a = {"contents": this_segment, "segment type": segment_type, "segment offset" : segment_offset }
        segments.append(a)
        #if(segment_type == LOADABLE_SEGMENT):
        #   print("Found a Loadable Segment")
            #
            #return this_segment
    # if we're here, nothing was returned. 
    
    return segments

def get_text(lib_path):
    try:
        ELF_File = open(lib_path, "rb")
    except FileNotFoundError:
        print("Elf file "+ lib_path + "Not FOUND!")
        return -1 
    
    contents =  ELF_File.read()
    ELF_File.close()
    str_contents = bytes(contents)
    print ("magic 2: " +str(read2(contents, 0)) )
    pheader_loc = read4(contents, p_header_start)
    number_of_p_headers = read2(contents, pheader_num_offset)
    print("Number of p_headers: "+ str(number_of_p_headers))
    size_of_sec_headers = read2(contents, size_sheader_entry_offset )
    
    print("size of Sec header "+ hex(size_of_sec_headers) )

    num_sec_headers_for_loop = read2(contents, num_sec_headers_offset)
    #
    #s_header_offset_offset  = 0x20 #0x28
    loc_sec_header_table = read4(contents, 32)
    size_pheader_entry = read2(contents, size_pheader_entry_offset)
    elf_type = read2(contents, elf_type_offset)
    print("elf type is: " + str(elf_type))
    elf_flags = read4(contents, elf_header_flags_offset)
    print("elf flags are: " + str(elf_flags))
    # only segments will be returned
    print ("Number of Sections: " + str(num_sec_headers_for_loop))
    print("S Header Offset: "+ str(read4(contents, 32)) )
    sections =[]
    for i in range (0, num_sec_headers_for_loop):
        print("i in loop: " + str(i))
        entry_start = loc_sec_header_table + i*size_of_sec_headers
        sflags = 0x10
        section_flags = read4(contents,entry_start + sflags)
        #print ("Section Table Start "+str(loc_sec_header_table ) + " Hex: " + hex(loc_sec_header_table)+  " Entry start: " + str(entry_start))
        # 16 is the offset of the location from the beginning of the section entry
        section_offset = read4(contents, entry_start + section_offset_offset)
        #entry_start = loc_sec_header_table + i*size_of_sec_headers
        section_size =  read4(contents, entry_start +   section_size_offset )

        section_contents = contents[section_offset: section_offset+section_size]
        cur_section = {"section_size" : section_size, "section_offset": section_offset, "section_contents" : section_contents}
        sections.append(cur_section)
        #print("section offset: " + str(section_offset), "Hex: " + hex(section_offset))
        #print( "Section Flags: " + str(section_flags))
        #Section Name is the firt entry so it doesn't need an additional offset
        section_name_offset = read4(contents, entry_start)
        print ("Section Name: " + get_str(contents, section_name_offset ))
        
        executable_instr = 4
        if(section_offset == 52):
            print("First Section Found!!!!!")
        if(section_flags == executable_instr):
            print("Section Contents Found")
            return section_contents
    print("Finished Section Loop")
    segments = []
    for i in range (0, number_of_p_headers):
        print("In Segmentation Search loop with index = " +str(i) )
        entry_start = pheader_loc + i * size_pheader_entry
        segment_type = read4(contents, entry_start + 0)
        segment_offset = read4(contents, entry_start + p_offset_offset )
        segment_size_in_file = read4(contents, entry_start +segment_size_in_file_offset)
        this_segment = contents[segment_offset: segment_offset +segment_size_in_file]
        
        a = {"contents": this_segment, "segment type": segment_type, "segment offset": segment_offset }
        # all segments ending in one are executable.
        if(segment_type%2== 1 ):
            print("Found an executable segment!")
            return this_segment
            #
            #return this_segment
             
    # if we're here, nothing was returned. 
    default_return = ""
    


        #entry_start = loc_sec_header_table + i*size_of_sec_headers
        #section_flags = read4(contents,entry_start + sflags)

        #section_offset = read4(contents, entry_start + section_offset_offset)
        #section_size =  read4(contents, entry_start +   section_size_offset )
        #print( section_flags)
    return default_return

#  These functions get return the sections of the the file that satsify an attribute or type; the options can be see above
def get_section_by_type(section_dict, sec_type):
    # returns all section of the specified type as a list
    cur =[]
    for i in range(len(section_dict) ) :    
        if (section_dict[i].get("section_type") == sec_type):
            r = section_dict[i]
            cur.append(r)
    return cur

def get_section_by_attributes(section_dict, sec_flags):
    # returns all section of the specified type as a list
    cur =[]
    for i in range(len(section_dict) ) :    
        if (section_dict[i].get("section_flags") == sec_flags):
            r = section_dict[i]
            cur.append(r)
    return cur

# These should return exactly what needs to go into the onboard files
def get_sym(all_contents):
    a= get_section_by_type(all_contents, sht_symtab)
    return a[0]
def get_relocation_addends(all_contents):
    a= get_section_by_type(all_contents, sht_rela_with_addend)
    return a[0]
def get_data(all_contents):
    a= get_section_by_type(all_contents, sh_progbits)
    return a[0]
def get_exec(all_contents):
    a= get_section_by_type(all_contents, sh_progbits)
    return a[0]

def process_lib(lib_path):
    # Take a path to a library file and then process it until it's read to be sliced up for loading.
    ld_path = "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.exe"
    ld_script = "memory_manager_processing_script.ld"
    ld_options = " -r " 
    entry_name = "load_func_struct"
    # since the cleaned library replaces the
    temp_lib_path =  lib_path+ "_f"
    total_command = ld_path + " -o "  +temp_lib_path +" -e " + entry_name + " "  + lib_path + " " + ld_options + " -T " + ld_script
    print("Total Command: " + total_command ) 
    os.system(total_command)
    #os.system("mv " + temp_lib_path+ " " + lib )
    return temp_lib_path

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
    print("Before get_text and get_segment")
    # Final Location actually gives the name file as it will be seen on the device
    # Modify final location to remove .cpp
    # puts the whole compiled contents into 
    complete_lib_path = place_full_elf(content=all_contents, final_location=onboard_lib_name )
    # there is now a second file containing the version of the file that hase been manipulated by ld 
    finished_lib_path =  process_lib(complete_lib_path) 

    # You can now run all linking operations and so on in place.
    ld_path = "c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.exe"
    #os.system("c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.exe C:/Users/cbent/a.txt")

    # this is a list holding dictorionaries filled with the contents of the sections and the ascociated section data
    # You have to use the final library path after running the processig functions
    all_sections = get_sections(finished_lib_path)
    executable_segment = get_text(finished_lib_path)
    #if (executable_segment ="" )

    #text_sections = get_section_by_type(all_sections, sh_progbits)
    #data_sections = get_section_by_type
    relocations_addend = get_section_by_type(all_sections,sht_rela_with_addend)
    symtable =  get_section_by_type(all_sections, sht_symtab)
    
    if (executable_segment == ""):
        print("No Text Segment Found")

    else:
        n = place_exec(content=executable_segment, final_location=onboard_lib_name)
        #place_data(all_contents, onboard_lib_name)
    
    # get the section that needs to be uploaded, checking flags and types etc.
    exec_section = get_exec(all_sections)
    data_section = get_data(all_sections)
    relocation_table_addend = get_relocation_addends(all_sections)
    sym_table = get_sym(all_sections)
    # Once the symtable functions are run any additional checks are performed here or 
    # Check 


    exec_section_contents = exec_section.get("section_contents")
    data_section_contents = data_section.get("section_contents")
    relocation_table_addend_content = relocation_table_addend.get("section_contents")
    sym_table_content =sym_table.get("section_contents")
    #
    place_exec(exec_section_contents, onboard_lib_name )
    place_data(data_section_contents,  onboard_lib_name)
    place_relocation_table(relocation_table_addend_content,  onboard_lib_name )
    place_symbol_table(sym_table_content, onboard_lib_name)
    # trigger delete file on finished_lib_path
    # trigger delete file on complete_lib_path because neither of these will actually be on the device




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
        #os.system("c:/users/cbent/.platformio/packages/toolchain-xtensa32/bin/../lib/gcc/xtensa-esp32-elf/5.2.0/../../../../xtensa-esp32-elf/bin/ld.exe C:/Users/cbent/a.txt")
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