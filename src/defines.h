#ifndef Unicorn_DEF
#define Unicorn_DEF
enum sectionType {text, rodata, data, bss};
enum lineType {Label, Inst, PseudoInst, Directive};
enum symbolType {Function, Object, Error};

typedef unsigned char      _elf_u8;
typedef unsigned short int _elf_u16;
typedef signed int         _elf_s32;
typedef unsigned int       _elf_u32;
typedef signed long long   _elf_s64;
typedef unsigned long long _elf_u64;

// Elf32 types
typedef _elf_u32 Elf32_Addr;
typedef _elf_u16 Elf32_Half;
typedef _elf_u32 Elf32_Off;
typedef _elf_s32 Elf32_Sword;
typedef _elf_u32 Elf32_Word;
typedef _elf_u8  Elf32_Byte;
#endif