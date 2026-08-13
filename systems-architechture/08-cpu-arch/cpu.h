/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 8 — CPU Architecture

File:
cpu.h

Purpose:
Defines the CPU simulator interface.

============================================================
*/

#ifndef CPU_H
#define CPU_H

#include <stdint.h>


/*
============================================================
CPU Configuration
============================================================
*/

#define CPU_REGISTER_COUNT 4
#define CPU_MEMORY_SIZE 256


/*
============================================================
Instruction Set

Each instruction contains:

opcode
operand

============================================================
*/

typedef enum
{
    OP_HALT,
    OP_LOAD,
    OP_STORE,
    OP_ADD,
    OP_SUB,
    OP_LOAD_IMMEDIATE,
    OP_JUMP,
    OP_JUMP_IF_ZERO

} Opcode;


typedef struct
{
    Opcode opcode;
    uint8_t operand;

} Instruction;


/*
============================================================
CPU State

Registers:
general-purpose registers used by instructions.

program_counter:
address of next instruction.

instruction_register:
currently fetched instruction.

accumulator:
simple arithmetic register.

zero_flag:
records whether the last result was zero.

halted:
indicates whether execution has stopped.

============================================================
*/

typedef struct
{
    int registers[CPU_REGISTER_COUNT];

    uint8_t program_counter;

    Instruction instruction_register;

    int accumulator;

    int zero_flag;

    int halted;

} CPU;


/*
============================================================
CPU Operations
============================================================
*/

void cpu_init(
    CPU *cpu
);


void cpu_load_program(
    CPU *cpu,
    const Instruction *program,
    uint8_t program_size
);


int cpu_fetch(
    CPU *cpu,
    const Instruction *program,
    uint8_t program_size
);


void cpu_decode_execute(
    CPU *cpu
);


void cpu_run(
    CPU *cpu,
    const Instruction *program,
    uint8_t program_size
);


void cpu_print_state(
    const CPU *cpu
);

#endif