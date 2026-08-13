/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 8 — CPU Architecture

File:
cpu.c

Purpose:
Implements a simplified CPU fetch-decode-execute simulator.

============================================================
*/

#include <stdio.h>

#include "cpu.h"


/*
============================================================
CPU Initialisation
============================================================
*/

void cpu_init(
    CPU *cpu
)
{
    if (cpu == NULL)
    {
        return;
    }


    for (int i = 0; i < CPU_REGISTER_COUNT; i++)
    {
        cpu->registers[i] = 0;
    }


    cpu->program_counter = 0;

    cpu->instruction_register.opcode = OP_HALT;

    cpu->instruction_register.operand = 0;

    cpu->accumulator = 0;

    cpu->zero_flag = 0;

    cpu->halted = 0;
}


/*
============================================================
Program Loading

The simulator does not need a separate RAM implementation
for this exercise.

The program array represents instruction memory.

============================================================
*/

void cpu_load_program(
    CPU *cpu,
    const Instruction *program,
    uint8_t program_size
)
{
    if (cpu == NULL || program == NULL || program_size == 0)
    {
        return;
    }

    cpu->program_counter = 0;
    cpu->halted = 0;
}


/*
============================================================
Fetch

Fetches the instruction pointed to by the program counter.

This models:

IR <- Memory[PC]

PC <- PC + 1

============================================================
*/

int cpu_fetch(
    CPU *cpu,
    const Instruction *program,
    uint8_t program_size
)
{
    if (
        cpu == NULL ||
        program == NULL ||
        cpu->program_counter >= program_size
    )
    {
        if (cpu != NULL)
        {
            cpu->halted = 1;
        }

        return 0;
    }


    cpu->instruction_register =
        program[cpu->program_counter];


    cpu->program_counter++;


    return 1;
}


/*
============================================================
Decode + Execute

The instruction register contains the current instruction.

The CPU determines what operation the opcode represents
and modifies its internal state.

============================================================
*/

void cpu_decode_execute(
    CPU *cpu
)
{
    if (cpu == NULL)
    {
        return;
    }


    switch (cpu->instruction_register.opcode)
    {
        /*
        ----------------------------------------------------
        HALT
        ----------------------------------------------------
        */

        case OP_HALT:

            cpu->halted = 1;

            break;


        /*
        ----------------------------------------------------
        LOAD IMMEDIATE

        accumulator <- operand
        ----------------------------------------------------
        */

        case OP_LOAD_IMMEDIATE:

            cpu->accumulator =
                cpu->instruction_register.operand;

            cpu->zero_flag =
                cpu->accumulator == 0;

            break;


        /*
        ----------------------------------------------------
        ADD

        accumulator <- accumulator + register
        ----------------------------------------------------
        */

        case OP_ADD:

            if (
                cpu->instruction_register.operand
                < CPU_REGISTER_COUNT
            )
            {
                cpu->accumulator +=
                    cpu->registers[
                        cpu->instruction_register.operand
                    ];
            }

            cpu->zero_flag =
                cpu->accumulator == 0;

            break;


        /*
        ----------------------------------------------------
        SUB

        accumulator <- accumulator - register
        ----------------------------------------------------
        */

        case OP_SUB:

            if (
                cpu->instruction_register.operand
                < CPU_REGISTER_COUNT
            )
            {
                cpu->accumulator -=
                    cpu->registers[
                        cpu->instruction_register.operand
                    ];
            }

            cpu->zero_flag =
                cpu->accumulator == 0;

            break;


        /*
        ----------------------------------------------------
        STORE

        register <- accumulator
        ----------------------------------------------------
        */

        case OP_STORE:

            if (
                cpu->instruction_register.operand
                < CPU_REGISTER_COUNT
            )
            {
                cpu->registers[
                    cpu->instruction_register.operand
                ] =
                    cpu->accumulator;
            }

            break;


        /*
        ----------------------------------------------------
        LOAD

        accumulator <- register
        ----------------------------------------------------
        */

        case OP_LOAD:

            if (
                cpu->instruction_register.operand
                < CPU_REGISTER_COUNT
            )
            {
                cpu->accumulator =
                    cpu->registers[
                        cpu->instruction_register.operand
                    ];

                cpu->zero_flag =
                    cpu->accumulator == 0;
            }

            break;


        /*
        ----------------------------------------------------
        JUMP

        PC <- operand
        ----------------------------------------------------
        */

        case OP_JUMP:

            cpu->program_counter =
                cpu->instruction_register.operand;

            break;


        /*
        ----------------------------------------------------
        JUMP IF ZERO

        if zero_flag:
            PC <- operand
        ----------------------------------------------------
        */

        case OP_JUMP_IF_ZERO:

            if (cpu->zero_flag)
            {
                cpu->program_counter =
                    cpu->instruction_register.operand;
            }

            break;
    }
}


/*
============================================================
Run CPU

Repeatedly performs:

FETCH
DECODE
EXECUTE

until HALT.

============================================================
*/

void cpu_run(
    CPU *cpu,
    const Instruction *program,
    uint8_t program_size
)
{
    if (cpu == NULL || program == NULL)
    {
        return;
    }


    while (!cpu->halted)
    {
        if (
            !cpu_fetch(
                cpu,
                program,
                program_size
            )
        )
        {
            break;
        }


        cpu_decode_execute(cpu);
    }
}


/*
============================================================
Print CPU State
============================================================
*/

void cpu_print_state(
    const CPU *cpu
)
{
    if (cpu == NULL)
    {
        return;
    }


    printf("\nCPU State\n");
    printf("--------------------\n");


    printf(
        "Program Counter: %u\n",
        cpu->program_counter
    );


    printf(
        "Accumulator: %d\n",
        cpu->accumulator
    );


    printf(
        "Zero Flag: %d\n",
        cpu->zero_flag
    );


    printf(
        "Halted: %d\n",
        cpu->halted
    );


    printf("Registers:\n");


    for (int i = 0; i < CPU_REGISTER_COUNT; i++)
    {
        printf(
            "R%d = %d\n",
            i,
            cpu->registers[i]
        );
    }
}