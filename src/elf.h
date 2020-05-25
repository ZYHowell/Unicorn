#ifndef SJTU_ELF
#define SJTU_ELF
#include "defines.h"
typedef struct {
	Elf32_Byte  e_ident[16];  /* ELF identification */
	Elf32_Half  e_type;              /* Object file type */
	Elf32_Half  e_machine;           /* Machine type */
	Elf32_Word  e_version;           /* Object file version */
	Elf32_Addr  e_entry;             /* Entry point address */
	Elf32_Off   e_phoff;             /* Program header offset */
	Elf32_Off   e_shoff;             /* Section header offset */
	Elf32_Word  e_flags;             /* Processor-specific flags */
	Elf32_Half  e_ehsize;            /* ELF header size */
	Elf32_Half  e_phentsize;         /* Size of program header entry */
	Elf32_Half  e_phnum;             /* Number of program header entries */
	Elf32_Half  e_shentsize;         /* Size of section header entry */
	Elf32_Half  e_shnum;             /* Number of section header entries */
	Elf32_Half  e_shstrndx;          /* Section name string table index */
} Elf32_Ehdr;

typedef struct {
	Elf32_Word  sh_name;             /* Section name */
	Elf32_Word  sh_type;             /* Section type */
	Elf32_Word  sh_flags;            /* Section attributes */
	Elf32_Addr  sh_addr;             /* Virtual memory address */
	Elf32_Off   sh_offset;           /* Offset in file */
	Elf32_Word  sh_size;             /* Size of section */
	Elf32_Word  sh_link;             /* Link to other section */
	Elf32_Word  sh_info;             /* Miscellaneous information */
	Elf32_Word  sh_addralign;        /* Address alignment boundary */
	Elf32_Word  sh_entsize;          /* Size of entries, if section has table */
} Elf32_Shdr;

typedef struct {
	Elf32_Addr	r_offset;	
	Elf32_Word	r_info;
	Elf32_Sword	r_addend;
} Elf32_Rela;

#define ELF32_ST_BIND(i)   ((i)>>4)	//1 for global
#define ELF32_ST_TYPE(i)   ((i)&0xf)
#define ELF32_ST_INFO(b,t) (((b)<<4)+((t)&0xf))	
//BIND: LOCAL-0, GLOBAL-1; 
//TYPE: NOTYPE-0, OBJECT-1, FUNC-2, SECTION-3, FILE-4, COMMON-5

#define ELF32_ST_VISIBILITY(o) ((o)&0x3)
//visibility: DEFAULT-0
typedef struct {
	Elf32_Word	st_name;
    Elf32_Addr	st_value;
    Elf32_Word	st_size;
	unsigned char	st_info;
	unsigned char	st_other;
	Elf32_Half	st_shndx;
} Elf32_Sym;

#endif