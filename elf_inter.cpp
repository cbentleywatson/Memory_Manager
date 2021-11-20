// If the program is running on the desktop these are needed
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
//#include <typedef.h>
using namespace std;
//

// Type defs for the 32 bit elf header types.
/*
typedef uint32_t	Elf32_Addr;
typedef uint16_t	Elf32_Half;
typedef uint32_t	Elf32_Off;
typedef int	Elf32_Sword;
typedef unint32_t	Elf32_Word;


typedef struct elf32_hdr{
  unsigned char	e_ident[EI_NIDENT];
  Elf32_Half	e_type;
  Elf32_Half	e_machine;
  Elf32_Word	e_version;
  Elf32_Addr	e_entry;
  Elf32_Off	e_phoff;
  Elf32_Off	e_shoff;
  Elf32_Word	e_flags;
  Elf32_Half	e_ehsize;
  Elf32_Half	e_phentsize;
  Elf32_Half	e_phnum;
  Elf32_Half	e_shentsize;
  Elf32_Half	e_shnum;
  Elf32_Half	e_shstrndx;
} Elf32_Ehdr;
*/

typedef struct
{
  unsigned char e_ident[EI_NIDENT];
  uint16_t e_type;
  uint16_t e_machine;
  uint32_t e_version;
  ElfN_Addr e_entry;
  ElfN_Off e_phoff;
  ElfN_Off e_shoff;
  uint32_t e_flags;
  uint16_t e_ehsize;
  uint16_t e_phentsize;
  uint16_t e_phnum;
  uint16_t e_shentsize;
  uint16_t e_shnum;
  uint16_t e_shstrndx;
} ElfN_Ehdr;

/*
typedef struct elf32_phdr{
  Elf32_Word	p_type;
  Elf32_Off	p_offset;
  Elf32_Addr	p_vaddr;
  Elf32_Addr	p_paddr;
  Elf32_Word	p_filesz;
  Elf32_Word	p_memsz;
  Elf32_Word	p_flags;
  Elf32_Word	p_align;
} Elf32_Phdr;

*/
/*
typedef struct elf32_shdr {
  Elf32_Word	sh_name;
  Elf32_Word	sh_type;
  Elf32_Word	sh_flags;
  Elf32_Addr	sh_addr;
  Elf32_Off	sh_offset;
  Elf32_Word	sh_size;
  Elf32_Word	sh_link;
  Elf32_Word	sh_info;
  Elf32_Word	sh_addralign;
  Elf32_Word	sh_entsize;
} Elf32_Shdr;

*/

/* Note header in a PT_NOTE section */
/*
typedef struct elf32_note {
  Elf32_Word	n_namesz;	// Name size
  Elf32_Word	n_descsz;	// Content size
  Elf32_Word	n_type;		// Content type
} Elf32_Nhdr;
*/

// There are more things of this type around line 139 of elf.h

/*
typedef struct elf32_rela{
  Elf32_Addr	r_offset;
  Elf32_Word	r_info;
  Elf32_Sword	r_addend;
} Elf32_Rela;
*/
/*
typedef struct elf32_rel {
  Elf32_Addr	r_offset;
  Elf32_Word	r_info;
} Elf32_Rel;
*/
#define elf_header_length 64
// section header defines
/*
#define e_type 0x10 // 2 bytes, type of the eld file being examined
#define e_phoff 0x1C // 4 bytes, program header offset
#define e_shoff 0x20 // 4 bytes section header offset
#define e_phentsize 0x2A // 2b size of a program header entry
#define e_phnum 0x2C // 2b number of entries in the program header table
#define e_shentsize 0x2E // 2b size of a section header entry
#define e_shnum 0x30 // 2b number of section header entries
#define e_shstrndx 0x32 // 2b index of the section header with the section names
*/

/* These constants define the different elf file types */
#define ET_NONE 0
#define ET_REL 1
#define ET_EXEC 2
#define ET_DYN 3
#define ET_CORE 4
#define ET_LOPROC 0xff00
#define ET_HIPROC 0xffff

// Program header definitions
// definitions for the first 4 byte are
#define PT_NULL 0
#define PT_LOAD 1
#define PT_DYNAMIC 2
#define PT_INTERP 3
#define PT_NOTE 4
#define PT_SHLIB 5
#define PT_PHDR 6

#define p_type 0x00   // 4 bytes
#define p_offset 0x04 // 4 bytes
#define p_filesz 0x10 // 4 bytes size of segment in file memory
#define p_memesz 0x14 // 4 bytes, size of the segment in memory
#define p_align 0x1C  // 4 bytes  specifies alignment; o and 1 are no alignment
// others are more complex

// Section header constants:

#define sh_name 0x00 // 4b offset to a string in .shrstab section with sec.'s name
#define sh_type 0x04 // 4b type of section here

// Meaning of the sh_type given

#define SHT_NULL 0     // unused
#define SHT_PROGBITS 1 // program data
#define SHT_SYMTAB 2   // Symbol Table
#define SHT_STRTAB 3   // string table
#define SHT_RELA 4     // relocation table with addend
#define SHT_HASH 5
#define SHT_DYNAMIC 6 // Dynamic Linking stuff
#define SHT_NOTE 7
#define SHT_NOBITS 8
#define SHT_REL 9
#define SHT_SHLIB 10
#define SHT_DYNSYM 11
#define SHT_NUM 12
#define SHT_LOPROC 0x70000000
#define SHT_HIPROC 0x7fffffff
#define SHT_LOUSER 0x80000000
#define SHT_HIUSER 0xffffffff

// Section Header Flags,  basic version
/* sh_flags */
#define SHF_WRITE 0x1     // writable
#define SHF_ALLOC 0x2     // occupies memory during execution
#define SHF_EXECINSTR 0x4 // executable instructions
#define SHF_RELA_LIVEPATCH 0x00100000
#define SHF_RO_AFTER_INIT 0x00200000
#define SHF_MASKPROC 0xf0000000

// added by me for section header relocation info:
#define sh_offset 0x0C  // 4b  offset of section in file image
#define sh_size 0x14    //  4b size of section in the file image
#define sh_link 0x18    // 4b section link
#define sh_entsize 0x24 // contains the size in bytes of each entry for

// For each entry in the section header, if the section flag is executable (SHF_EXEC_INST)
// copy the section into the struct
// Check the name
// load the section into executable
// In the case of the run thing

// with simple lib_d getting section with ALLOC, CODE, and a non zero
// size would return the actual function being recommended
// The alignment is specified as 2**2

// Strategy #1: In place jumps
// Strategy #2: Read data into structs interpret and then pull

// S1:
// Pull the p header sheader into variables
// get the # entries in each
// for loop to get the types of each entry sh
// for loop to get the types of each entry in ph
// Get the actual code section, data section etc.

// int progr_header loc
// int section header loc
//

// Elf Interpreter Dummy
// read file into array
//
// Pull the num section headers, size function headers, start funct headers...
// go to sect headers, program headers
// get offsets of .rela, .data, .bss, .txt
// get offset of key functions
int main()
{
  std::cout << "hello" << std::endl;
  int arraysize = 100000;
  char myArray[arraysize];
  char current_char;
  int num_characters = 0;
  int i = 0;

  ifstream myfile("data/ELF_Files/simple_lib_d");

  if (myfile.is_open())
  {
    while (!myfile.eof())
    {
      myfile >> myArray[i];
      i++;
      num_characters++;
    }

    for (int i = 0; i <= num_characters; i++)
    {
      std::cout << myArray[i];
    }
    // myArray contains the full contents of the file
    // memcpy header into elf header
    // save data
    // release section header
    // memcpy pheader, sect header
    // memcpy header entries
    // save
    /*
    elf32_hdr *elf_header =  new elf32_hdr;
    memcpy((void *) elf_header, (void *) myArray, elf_header_length );
    }

    mk 4 byte pointer, half byte pointer
    Elf32_Off program_header_offset =elf_header.e_phoff; // expansion
    Elf32_Off section_header_offset = elf_header.e_shoff;
    Elf32_Half number_of_prog_header_entries = elf_header.phnum;
    Elf32_Half size_prog_entries =elf_header.ephent_size;
    Elf32_Half number_of_sec_header_entries = elf_header.e_shnum;
    Elf32_Half size_sec_entries = elf_header.e_shentsize;
    for (int i = 0; i<number_of_sec_header_entries; i++){
    */
  }
}