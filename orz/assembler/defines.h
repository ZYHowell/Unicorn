
enum sectionType {text, rodata, data, bss};
enum lineType {Label, Inst, PseudoInst, Directive};
enum symbolType {Function, Object, Error};


typedef unsigned char Elf32_Byte;
typedef unsigned int Elf32_Addr;
typedef unsigned short int Elf32_Half;
typedef unsigned int Elf32_Off;
typedef int Elf32_Sword;
typedef unsigned int Elf32_Word;
typedef unsigned long long Elf64_Addr;
typedef unsigned short int Elf64_Half;
typedef unsigned long long Elf64_Off;
typedef int Elf64_Sword;
typedef unsigned int Elf64_Word;