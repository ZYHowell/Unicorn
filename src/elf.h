#ifndef Unicorn_ELF
#define Unicorn_ELF
#include "defines.h"

/*-----------------------------------------------------------------------------*/
// e_type
enum {
	ET_NONE = 0,                     /* No file type */
	ET_REL = 1,                      /* Relocatable file */
	ET_EXEC = 2,                     /* Executable file */
	ET_DYN = 3,                      /* Shared object file */
	ET_CORE = 4,                     /* Core file */
	ET_LOPROC = 0xff00,              /* Processor-specific */
	ET_HIPROC = 0xffff
};

// e_machine
enum {
	EM_NONE = 0,                     /* Unknown machine */
	EM_X86_64 = 62,                  /* x86-64 */
	EM_RISCV = 243                   /* RISC-V */
};

// e_version
enum {
	EV_NONE = 0,                     /* Invalid version */
	EV_CURRENT = 1                   /* Current version */
};

// e_ident
enum {
	EI_MAG0 = 0,                     /* File identification */
	EI_MAG1 = 1,
	EI_MAG2 = 2,
	EI_MAG3 = 3,
	EI_CLASS = 4,                    /* File class */ 
	EI_DATA = 5,                     /* Data encoding */ 
	EI_VERSION = 6,                  /* File version */ 
	EI_OSABI = 7,                    /* OS/ABI identification */
	EI_ABIVERSION = 8,               /* ABI version */
	EI_PAD = 9,                      /* Start of padding bytes */
	EI_NIDENT = 16                   /* Size of e_ident[] */
};

// e_magic
enum {
	ELFMAG0 = 0x7f,                  /* e_ident[EI_MAG0] == ELFMAG0 */
	ELFMAG1 = 'E',                   /* e_ident[EI_MAG1] == ELFMAG1 */
	ELFMAG2 = 'L',                   /* e_ident[EI_MAG2] == ELFMAG2 */
	ELFMAG3 = 'F'                    /* e_ident[EI_MAG3] == ELFMAG3 */
};

// EI_CLASS
enum {
	ELFCLASSNONE = 0,
	ELFCLASS32 = 1,                  /* e_ident[EI_CLASS] - 32-bit objects */
	ELFCLASS64 = 2,                  /* e_ident[EI_CLASS] - 64-bit objects */
	ELFCLASS128 = 3                  /* e_ident[EI_CLASS] - 128-bit objects */
};

// EI_DATA
enum {
	ELFDATANONE = 0,
	ELFDATA2LSB = 1,                 /* e_ident[EI_DATA] - Data is little-endian */
	ELFDATA2MSB = 2                  /* e_ident[EI_DATA] - Data is big-endian */
};

// EI_OSABI
enum {
	ELFOSABI_SYSV = 0,               /* e_ident[EI_OSABI] == ELFOSABI_SYSV */
	ELFOSABI_LINUX = 3,              /* e_ident[EI_OSABI] == ELFOSABI_LINUX */
	ELFOSABI_SOLARIS = 6,            /* e_ident[EI_OSABI] == ELFOSABI_SOLARIS */
	ELFOSABI_FREEBSD = 9             /* e_ident[EI_OSABI] == ELFOSABI_FREEBSD */
};

// EI_ABIVERSION
enum {
	ELFABIVERSION_NONE = 0
};

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
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
// sh_name
enum {
	SHN_UNDEF = 0,                   /* Used to mark an undefined or meaningless section reference */
	SHN_LOPROC = 0xff00,             /* Processor-specific use */
	SHN_HIPROC = 0xff1f,
	SHN_LOOS = 0xff20,               /* Environment-specific use */
	SHN_HIOS = 0xff3f,
	SHN_ABS = 0xfff1,                /* Indicates that the corresponding reference is an absolute value */
	SHN_COMMON = 0xfff2,             /* Indicates a symbol that has been declared as a common block */
	SHN_XINDEX = 0xffff,             /* Indicates section header has additional date in SHT_SYMTAB_SHNDX section */
	SHN_HIRESERVE = 0xffff,          /* Upper bound of the range of reserved indexes */
};

// sh_type
enum {
	SHT_NULL = 0,                    /* Marks an unused section header */
	SHT_PROGBITS = 1,                /* Contains information defined by the program */
	SHT_SYMTAB = 2,                  /* Contains a linker symbol table */
	SHT_STRTAB = 3,                  /* Contains a string table */
	SHT_RELA = 4,                    /* Contains "Rela" type relocation entries */
	SHT_NOBITS = 8,                  /* Contains uninitialized space; does not take up space in file */
	SHT_GNU_VERDEF = 0x6ffffffd,
	SHT_GNU_VERNEED = 0x6ffffffe,
	SHT_GNU_VERSYM = 0x6fffffff
};

// sh_flags
enum {
	SHF_WRITE = 0x1,                 /* Section contains writable data */
	SHF_ALLOC = 0x2,                 /* Section is allocated in memory image of program */
	SHF_EXECINSTR = 0x4,             /* Section contains executable instructions */
	SHF_MERGE = 0x10,                /* Section contains data that may be merged to eliminate duplication */
	SHF_STRINGS = 0x20,              /* Section consist of null-terminated character strings */
	SHF_INFO_LINK = 0x40,            /* Section sh_info holds a section header table index */
	SHF_LINK_ORDER = 0x80,           /* Section has link ordering requirement with sh_link pointing to next section */
};

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
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
typedef struct {
	Elf32_Addr	r_offset;	
	Elf32_Word	r_info;
	Elf32_Sword	r_addend;
} Elf32_Rela;
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
// st_info bind
enum {
	STB_LOCAL = 0,                   /* Not visible outside the object file */
	STB_GLOBAL = 1,                  /* Global symbol, visible to all object files */
	STB_WEAK = 2,                    /* Global scope, but with lower precedence than global symbols */
	STB_LOOS = 10,                   /* Environment-specific use */
	STB_HIOS = 12,
	STB_LOPROC = 13,                 /* Processor-specific use */
	STB_HIPROC = 15
};

// st_info type
enum {
	STT_NOTYPE = 0,                  /* No type specified (e.g., an absolute symbol) */
	STT_OBJECT = 1,                  /* Data object */
	STT_FUNC = 2,                    /* Function entry point */
	STT_SECTION = 3,                 /* Symbol is associated with a section */
	STT_FILE = 4,                    /* Source file associated with the object file */
	STT_LOOS = 10,                   /* Environment-specific use */
	STT_HIOS = 12,
	STT_LOPROC = 13,                 /* Processor-specific use */
	STT_HIPROC = 15
};

// st_other visibility
enum {
	STV_DEFAULT = 0,
	STV_INTERNAL = 1,
	STV_HIDDEN = 2,
	STV_PROTECTED = 3
};

#define ELF32_ST_BIND(i)   ((i)>>4)	
#define ELF32_ST_TYPE(i)   ((i)&0xf)
#define ELF32_ST_INFO(b,t) (((b)<<4)+((t)&0xf))	
//BIND: LOCAL-0, GLOBAL-1; 
//TYPE: NOTYPE-0, OBJECT-1, FUNC-2, SECTION-3, FILE-4, COMMON-5

#define ELF32_ST_VISIBILITY(o) ((o)&0x3)	//only keep the last 2 bits
//visibility: DEFAULT-0
typedef struct {
	Elf32_Word	st_name;
    Elf32_Addr	st_value;
    Elf32_Word	st_size;
	Elf32_Byte	st_info;
	Elf32_Byte	st_other;
	Elf32_Half	st_shndx;
} Elf32_Sym;

#endif