#ifndef Unicorn_ELF
#define Unicorn_ELF
#include "defines.h"
#include "riscv.h"

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

struct Elf32_Ehdr{
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
	void reverse(Elf32_Ehdr *it) {
		for (size_t i = 0;i < 16;++i) it->e_ident[i] = e_ident[i];
		it->e_type = Unicorn::bswap16(e_type);
		it->e_machine = Unicorn::bswap16(e_machine);
		it->e_version = Unicorn::bswap32(e_version);
		it->e_entry = Unicorn::bswap32(e_entry);
		it->e_phoff = Unicorn::bswap32(e_phoff);
		it->e_shoff = Unicorn::bswap32(e_shoff);
		it->e_flags = Unicorn::bswap32(e_flags);
		it->e_ehsize = Unicorn::bswap16(e_ehsize);
		it->e_phentsize = Unicorn::bswap16(e_phentsize);
		it->e_phnum = Unicorn::bswap16(e_phnum);
		it->e_shentsize = Unicorn::bswap16(e_shentsize);
		it->e_shnum = Unicorn::bswap16(e_shnum);
		it->e_shstrndx = Unicorn::bswap16(e_shstrndx);
	}
};
/*-----------------------------------------------------------------------------*/
// Elf32_Phdr
struct Elf32_Phdr {
	Elf32_Word  p_type;              /* Type of segment */
	Elf32_Off   p_offset;            /* Offset in file */
	Elf32_Addr  p_vaddr;             /* Virtual address in memory */
	Elf32_Addr  p_paddr;             /* Physical address in memory (if applicable) */
	Elf32_Word  p_filesz;            /* Size of segment in file */
	Elf32_Word  p_memsz;             /* Size of segment in memory */ 
	Elf32_Word  p_flags;             /* Segment attributes */
	Elf32_Word  p_align;             /* Alignment of segment */
};
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

struct Elf32_Shdr{
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
	void reverse(Elf32_Shdr *it) {
		it->sh_name = Unicorn::bswap32(sh_name);
		it->sh_type = Unicorn::bswap32(sh_type);
		it->sh_flags = Unicorn::bswap32(sh_flags);
		it->sh_addr = Unicorn::bswap32(sh_addr);
		it->sh_offset = Unicorn::bswap32(sh_offset);
		it->sh_size = Unicorn::bswap32(sh_size);
		it->sh_link = Unicorn::bswap32(sh_link);
		it->sh_info = Unicorn::bswap32(sh_info);
		it->sh_addralign = Unicorn::bswap32(sh_addralign);
		it->sh_entsize = Unicorn::bswap32(sh_entsize);
	}
};
/*-----------------------------------------------------------------------------*/
/*-----------------------------------------------------------------------------*/
enum {
	R_RISCV_NONE = 0,                /* xx,       None                         */
	R_RISCV_BRANCH = 16,             /* 32, 12:1  PC-relative branch offset                          SB-Type (beq,bne,blt,bge,bltu,bgeu) */
	R_RISCV_JAL = 17,                /* 32, 20:1  PC-relative jump offset                            UJ-Type (jal) */
	R_RISCV_CALL = 18,               /* 64, 31:0  PC-relative function call                          MACRO call (auipc+jalr) */
	R_RISCV_CALL_PLT = 19,           /* 64, 31:0  PC-relative function call                          MACRO tail (auipc+jalr) */
	R_RISCV_PCREL_HI20 = 23,         /* 32, 31:12 PC-relative reference         %pcrel_hi(symbol)    U-Type (auipc) */
	R_RISCV_PCREL_LO12_I = 24,       /* 32, 11:0  PC-relative reference         %pcrel_lo(label)     I-Type (lb,lbu,lh,lhu,lw,lwu,flw,fld,addi,addiw) */
	R_RISCV_PCREL_LO12_S = 25,       /* 32, 11:0  PC-relative reference         %pcrel_lo(label)     S-Type (sb,sh,sw,fsw,fsd) */
	R_RISCV_HI20 = 26,               /* 32, 31:12 Absolute address              %hi(symbol)          U-Type (lui,auipc) */
	R_RISCV_LO12_I = 27,             /* 32, 11:0  Absolute address              %lo(symbol)          I-Type (lb,lbu,lh,lhu,lw,lwu,flw,fld,addi,addiw) */
	R_RISCV_LO12_S = 28,             /* 32, 11:0  Absolute address              %lo(symbol)          S-Type (sb,sh,sw,fsw,fsd) */
	R_RISCV_RELAX = 51,              /*           Reloc pair can be relaxed */
};
#define ELF32_R_SYM(i)  (i >> 8)
#define ELF32_R_TYPE(i)  (i & 0xff)
#define ELF32_R_INFO(s, t)  ((s << 8) | (t & 0xff))
struct Elf32_Rela{
	Elf32_Addr	r_offset;	
	Elf32_Word	r_info;
	Elf32_Sword	r_addend;
	void reverse(Elf32_Rela *it) {
		it->r_offset = Unicorn::bswap32(r_offset);
		it->r_info = Unicorn::bswap32(r_info);
		it->r_addend = Unicorn::bswap32(r_addend);
	}
};
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
struct Elf32_Sym{
	Elf32_Word	st_name;
    Elf32_Addr	st_value;
    Elf32_Word	st_size;
	Elf32_Byte	st_info;
	Elf32_Byte	st_other;
	Elf32_Half	st_shndx;
	void reverse(Elf32_Sym *it) {
		it->st_name = Unicorn::bswap32(st_name);
		it->st_value = Unicorn::bswap32(st_value);
		it->st_size = Unicorn::bswap32(st_size);
		it->st_info = st_info;
		it->st_other = st_other;
		it->st_shndx = Unicorn::bswap16(st_shndx);
	}
};

#endif