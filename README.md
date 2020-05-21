# Unicorn
MS208 homework in ACM class, another part, an assembler of RISCV. Named after the ELF files it produces. 

後方支援は任せて…ユニコーン…頑張る！

### Detailed standard of ELF files

🙌Nobody

👐Knows more

👌About assembler

☝Better than me

​			——D.J.Trump

#### file metadata

this is the e_ident of ehdr

there are 16 chars in all. 

the first 4 chars are: 127 69('E') 76('L') 70('F'), which is the magic number of ELF file. 

then a char, 1 for 32bit and 2 for 64 bit(ei_class)

then a char, 1 for little endian and 2 for big endian(ei_data)

then a char for file version, 1 for current(or available/reliable)

then a char for OS/ABI identification, 0 for unknown-elf, 3 for linux-gnu and 9 for freebsd

then a char for ABI version

then start of padding bytes

#### symbol table

##### ehdr(extension header)

e_ident: see above

e_phoff: program header offset

e_phnum: program header number

e_shoff: section header offset

e_shnum: section header number

by definition, phdr_end=e_phoff + e_phnum * sizeof(phdr), so is shdr_end

e_phentsize, e_shentsize: size of program header/section header

e_ehsize: size of extension header

e_version: 0 for invalid and 1 for valid

e_type: 1 for relocatable(always this), 2 for executable, 3 for shared object, 4 for core, 0xff00 and oxffff for processor specific

e_flags: 0x1, 0x2, 0x4, 0x6, 0x8, 0x10: RVC(c-extension), FLOAT_ABI_SINGLE, FLOAT_ABI_DOUBLE(simply use this is OK for our output.s), FLOAT_ABI_QUAD, RVE(e-extension), TSO. 

e_machine: 243 for riscv(btw, 62 for x86)

e_entry: the address from where the process starts executing

e_shstrndx: index of section name string table. 

##### phdr(program header)

p_type: type of segment: 0 is unused entry; 1 is loadable segment; 2 is dynamic linking tables; 3 is program interpreter path name; 4 is note sections; 5 is reserved; 6 is program header table; 7 is thread local storage header table; ...and some specific use. 

p_flag: 1 for execute permission, 2 for write permission, 4 for read permission; ... and specific use.

##### shdr(section header)