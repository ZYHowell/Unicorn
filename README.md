# Unicorn
MS208 homework in ACM class, another part, an assembler of RISCV. Named after the ELF files it produces. 

However, only test on my own computer(the OS and hardware may make it useless)

The error is not complete either. 

後方支援は任せて…ユニコーン…頑張る！

### Detail standard of ELF used in Unicorn

🙌Nobody 

👐Knows about

👌Assembler 

☝Better than me

​			——D.J.Trump

see http://www.sco.com/developers/gabi for more details about the standard. 

#### Format for linking view

ELF Header(ehdr)

optional program header table

section 1

...

section n

required section header table

#### File metadata

this is the e_ident of ehdr

there are 16 chars in all. 

the first 4 chars are: 127 69('E') 76('L') 70('F'), which is the magic number of ELF file. 

then a char, 1 for 32bit and 2 for 64 bit(ei_class)

then a char, 1 for little endian and 2 for big endian(ei_data)

then a char for file version, 1 for current(that is, available)

then a char for OSABI identification, 0 for unknown-elf, 3 for linux-gnu(so this one). 

then a char for ABI version

then start of padding bytes

#### Header Format

##### ehdr(ELF header)

e_ident: see above

e_phoff: program header offset

e_phnum: program header number

e_shoff: section header offset

e_shnum: section header number(sepcial judge for the number geq 0xff00, but I do not have such kind of consideration so...)

by definition, phdr_end=e_phoff + e_phnum * sizeof(phdr), so is shdr_end

e_phentsize, e_shentsize: size of program header/section header

e_ehsize: size of extension header

e_version: 0 for invalid and 1 for valid

e_type: 1 for relocatable(always this), 2 for executable, 3 for shared object, 4 for core, 0xff00 and oxffff for processor specific

e_flags: 0x1, 0x2, 0x4, 0x6, 0x8, 0x10: RVC(c-extension), FLOAT_ABI_SINGLE, FLOAT_ABI_DOUBLE(simply use this is OK for our output.s), FLOAT_ABI_QUAD, RVE(e-extension), TSO. 

e_machine: 243 for riscv(btw, 62 for x86, and RISCV is so special that any other machine code is not greater than 224)

e_entry: the address from where the process starts executing

e_shstrndx: index of section name string table. (special judge if the file has no section name string table, but... )

##### phdr(program header)

This is optional for linking view. (so no such one)

p_type: type of segment: 1 is loadable segment; 2 is dynamic linking tables; 6 is program header table; ...

p_flag: 1 for execute permission, 2 for write permission, 4 for read permission; ... and specific use. 

since no such one...

##### shdr(section header)

```C
typedef struct {
	Elf32_Word	sh_name;	
    	//the value is an index into the section header string table section
	Elf32_Word	sh_type;
    	//1 for PROGBITS(information defined by program, .text, .data, .rodata), 
    	//2 for SYMTAB(symbol table), 3 for STRTAB
    	//4 for RELA(the relation entries with explicit addends)
    	//8 for NOBITS(information occupies no space in the file but otherwise resembles PROGBITS)
	Elf32_Word	sh_flags;
    	//1 for write, 2 for alloc, 4 for exec, so 3 for write+alloc, so does the rest. 
	Elf32_Addr	sh_addr;
    	//if put in memory, this member gives the address of the section's first byte. 0 otherwise. (but seems like that in link view it is always 0?)
	Elf32_Off	sh_offset;
    	//the offset from the beginning of the file to the first byte in the section
	Elf32_Word	sh_size;
    	//the size in bytes
	Elf32_Word	sh_link;
    	//only for .rela.text and .symtab in Unicorn
    	//the section header index of the associated symbol/string table; so .rela.text->.symtab, .symtab->.strtab
	Elf32_Word	sh_info;
    	//only for .rela.text and .symtab in Unicorn
     	//In rela, the section header index of the section to which the relocation applies. 
    	//In symtab, the number 1 greater than the symbol table index of the last local symbol. (0-base)
	Elf32_Word	sh_addralign;
    	//alignment constraints. 0 and 1 means no alignment constraints. (but always 0x4 except for.strtab and .shstrtab)
	Elf32_Word	sh_entsize;
    	//only for .rela.text and .symtab in Unicorn
    	//the size of each entry. (only the two section has "entry")
} Elf32_Shdr;
```

Notice: the index 0 section is special. its sh_size is either 0 or actual number of section header entries(but in my case it is always 0: no such many sections); its sh_link is either 0 or index of section header string table section(still, in my case it is always 0)

Notice: global variables in .bss is NOBITS so no space in the file. 

#### Relocation rule

```C
typedef struct {
	Elf32_Addr	r_offset;	
    	//location at which to allpy the relocation action
    	//that is, the byte offset from the beginning of the section
	Elf32_Word	r_info;
    	//the symbol table index of the symbol the reloction made
	Elf32_Sword	r_addend;
    	//a constant addend to compute the value to be stored into the relocatable field. 
} Elf32_Rela;
```

Used relocations. 

Enum | ELF Reloc Type       | Description                         | Details
:--- | :------------------  | :---------------                    | :-----------
16   | R_RISCV_BRANCH       | PC-relative branch offset           | SB-Type
17   | R_RISCV_JAL          | PC-relative jump offset             | UJ-Type
18   | R_RISCV_CALL         | PC-relative function call           | MACRO call,tail (auipc+jalr pair)
26   | R_RISCV_HI20         | Absolute address (U-Type)           | %hi(symbol)
27   | R_RISCV_LO12_I       | Absolute address (I-Type)           | %lo(symbol)
28   | R_RISCV_LO12_S       | Absolute address (S-Type)           | %lo(symbol)
33   | R_RISCV_ADD8         | 8-bit label addition                | word8 = S + A
51   | R_RISCV_RELAX        | Instruction pair can be relaxed     | (auipc+jalr pair)

Variable       | Description
:------------- | :----------------
A              | Addend field in the relocation entry associated with the symbol
B              | Base address of a shared object loaded into memory
G              | Offset of the symbol into the GOT (Global Offset Table)
S              | Value of the symbol in the symbol table
GP             | Global Pointer register (x3)

p.s.: interesting that the second table is not used...So I add 33 to show how it is used. 

Relaxation is to give chance to let a pair of relocation reduce to one. (if the high address is 0, can only use %lo relocation to get the address)

#### Symbol table

```C
#define ELF32_ST_BIND(i)   ((i)>>4)	//1 for global
#define ELF32_ST_TYPE(i)   ((i)&0xf)
#define ELF32_ST_INFO(b,t) (((b)<<4)+((t)&0xf))	
//BIND: LOCAL-0, GLOBAL-1; 
//TYPE: NOTYPE-0, OBJECT-1, FUNC-2, SECTION-3, FILE-4, COMMON-5

#define ELF32_ST_VISIBILITY(o) ((o)&0x3)
//visibility: DEFAULT-0
typedef struct {
	Elf32_Word	st_name;
    	//index into the file's symbol string table
	Elf32_Addr	st_value;
    	//In relocatable files, alignment constraints for a symbol whose section index is SHN_COMMON. 
	Elf32_Word	st_size;
    	//associated size
	unsigned char	st_info;
    	//info about BIND, TYPE
	unsigned char	st_other;
    	//info about visibility
	Elf32_Half	st_shndx;
    	//a symbol table is defined in relation to some section, this is the relevant section header table index. 
    	//ABS: absolute value, so not changed by relocation; UNDEF: undefined
    	//COMMON: a common block that has not yet been allocated. 
} Elf32_Sym;
```

| **Name**        | **Value** |
| --------------- | --------- |
| `SHN_UNDEF`     | `0`       |
| `SHN_ABS`       | `0xfff1`  |
| `SHN_COMMON`    | `0xfff2`  |

#### String table

here is an example: 

String table is: 

| Index  | +0   | +1   | +2   | +3   | +4   | +5   | +6   | +7   | +8   | +9   |
| ------ | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| **0**  | `\0` | `n`  | `a`  | `m`  | `e`  | `.`  | `\0` | `V`  | `a`  | `r`  |
| **10** | `i`  | `a`  | `b`  | `l`  | `e`  | `\0` | `a`  | `b`  | `l`  | `e`  |
| **20** | `\0` |  |  |  |  |   |      |      |      |      |

meaning is: 

| Index | String   |
| ----- | -------- |
| 0     | *none*   |
| 1     | name.    |
| 7     | Variable |
| 11    | able     |
| 16    | able     |
