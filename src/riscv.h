#ifndef Unicorn_riscv_h
#define Unicorn_riscv_h
#include"includes.h"
namespace Unicorn{
std::map<std::string, Elf32_Word> instFormat = {
    {"lui", 0x37}, {"auipc", 0x17}, {"jal", 0x6f}, {"jalr", 0x67}, 
    {"beq", 0x63}, {"bne", 0x1063}, {"blt", 0x4063}, {"bge", 0x5063}, 
    {"bltu", 0x6063}, {"bgeu", 0x7063}, 
    {"lb", 0x3}, {"lh", 0x1003}, {"lw", 0x2003}, {"lbu", 0x4003}, {"lhu", 0x5003}, 
    {"sb", 0x23}, {"sh", 0x1023}, {"sw", 0x2023}, 
    {"addi", 0x13}, {"slti", 0x2013}, {"sltiu", 0x3013}, {"xori", 0x4013}, 
    {"ori", 0x6013}, {"andi", 0x7013}, {"slli", 0x1013}, {"srli", 0x5013}, {"srai", 0x40005013}, 
    {"add", 0x33}, {"sub", 0x40000033}, {"sll", 0x1033}, {"slt", 0x2033}, {"sltu", 0x3033}, 
    {"xor", 0x4033}, {"srl", 0x5033}, {"sra", 0x40005033}, {"or", 0x6033}, {"and", 7033}, 
    {"mul", 0x2000033}, {"div", 0x2004033}, {"rem", 0x2006033}
};
std::map<std::string, Elf32_Word> regMap = {
    {"zero", 0}, {"ra", 1}, {"sp", 2}, {"gp", 3}, {"tp", 4}, {"t0", 5}, {"t1", 6}, {"t2", 7}, 
    {"s0", 8}, {"s1", 9}, {"a0", 10}, {"a1", 11}, {"a2", 12}, {"a3", 13}, {"a4", 14}, 
    {"a5", 15}, {"a6", 16}, {"a7", 17}, {"s2", 18}, {"s3", 19}, {"s4", 20}, {"s5", 21}, 
    {"s6", 22}, {"s7", 23}, {"s8", 24}, {"s9", 25}, {"s10", 26}, {"s11", 27}, 
    {"t3", 28}, {"t4", 29}, {"t5", 30}, {"t6", 31}
};
inline Elf32_Word apply(Elf32_Word origin, Elf32_Word add, unsigned int offset, size_t size) {
    return origin |= (add & ((1 << size) - 1)) << offset;
} 
inline Elf32_Word slice(Elf32_Word src, unsigned int L, unsigned R) {
    return (src >> R) & ((1 << (L - R + 1)) - 1);
}
inline Elf32_Word ImmIformat(Elf32_Word origin) {
    return slice(origin, 11, 0);
}
inline Elf32_Word ImmSformatA(Elf32_Word origin) {
    return slice(origin, 11, 5);
}
inline Elf32_Word ImmSformatB(Elf32_Word origin) {
    return slice(origin, 4, 0);
}
inline Elf32_Word ImmBformatA(Elf32_Word origin) {
    return (slice(origin, 12, 12) << 6) | 
            (slice(origin, 10, 5));
}
inline Elf32_Word ImmBformatB(Elf32_Word origin) {
    return (slice(origin, 4, 1) << 1) | 
            (slice(origin, 11, 11));
}
inline Elf32_Word ImmUformat(Elf32_Word origin) {
    return slice(origin, 31, 12);
}
inline Elf32_Word ImmJformat(Elf32_Word origin) {
    return ((slice(origin, 20, 20) << 18) | 
            (slice(origin, 10, 1) << 8) | 
            (slice(origin, 11, 11) << 7) | 
            (slice(origin, 19, 12))
            ) & ((1 << 20) - 1);
}
inline Elf32_Word addRd(Elf32_Word inst, Elf32_Word rd) {
    return apply(inst, rd, 7, 5);
}
inline Elf32_Word addR1(Elf32_Word inst, Elf32_Word r1) {
    return apply(inst, r1, 15, 5);
}
inline Elf32_Word addR2(Elf32_Word inst, Elf32_Word r2) {
    return apply(inst, r2, 20, 5);
}
inline Elf32_Word addIImm(Elf32_Word inst, Elf32_Word imm) {
    return apply(inst, ImmIformat(imm), 12, 20);
}
inline Elf32_Word addSImm(Elf32_Word inst, Elf32_Word imm) {
    return apply(
            apply(inst, ImmSformatA(imm), 25, 7), 
            ImmSformatB(imm), 7, 5
            );
}
inline Elf32_Word addBImm(Elf32_Word inst, Elf32_Word imm) {
    return apply(
            apply(inst, ImmBformatA(imm), 25, 7), 
            ImmBformatB(imm), 7, 5
            );
}
inline Elf32_Word addUImm(Elf32_Word inst, Elf32_Word imm) {
    return apply(inst, ImmUformat(imm), 12, 20);
}
inline Elf32_Word addJImm(Elf32_Word inst, Elf32_Word imm) {
    return apply(inst, ImmJformat(imm), 12, 20);
}
inline Elf32_Word bswap32(Elf32_Word src) {
    return (slice(src, 7, 0) << 24) | 
            (slice(src, 15, 8) << 16) | 
            (slice(src, 23, 16) << 8) | 
            (slice(src, 31, 24) << 0);
}
inline Elf32_Half bswap16(Elf32_Half src) {
    return (slice(src, 7, 0) << 8) | 
            (slice(src, 15, 8) <<0);
}
};
#endif