/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 8 — CPU Architecture

File:
main.c

Purpose:
Demonstrates a simplified CPU executing instructions.

============================================================
*/

#include <stdio.h>

#include "cpu.h"


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" CPU Architecture Demonstration\n");
    printf("========================================\n\n");


    /*
    --------------------------------------------------------
    Program

    The simulated program performs:

        R0 = 10
        R1 = 20
        accumulator = R0
        accumulator = accumulator + R1
        R2 = accumulator
        HALT

    Therefore:

        R2 = 30

    --------------------------------------------------------
    */

    const Instruction program[] =
    {
        /*
        LOAD 10 into accumulator
        */

        {
            OP_LOAD_IMMEDIATE,
            10
        },


        /*
        Store accumulator in R0
        */

        {
            OP_STORE,
            0
        },


        /*
        LOAD 20 into accumulator
        */

        {
            OP_LOAD_IMMEDIATE,
            20
        },


        /*
        Store accumulator in R1
        */

        {
            OP_STORE,
            1
        },


        /*
        Load R0 into accumulator
        */

        {
            OP_LOAD,
            0
        },


        /*
        Add R1
        */

        {
            OP_ADD,
            1
        },


        /*
        Store result in R2
        */

        {
            OP_STORE,
            2
        },


        /*
        Stop execution
        */

        {
            OP_HALT,
            0
        }
    };


    const uint8_t program_size =
        sizeof(program) /
        sizeof(program[0]);


    /*
    --------------------------------------------------------
    Create CPU
    --------------------------------------------------------
    */

    CPU cpu;


    cpu_init(&cpu);


    cpu_load_program(
        &cpu,
        program,
        program_size
    );


    /*
    --------------------------------------------------------
    Execute program

    This performs the repeated:

        FETCH
        DECODE
        EXECUTE

    cycle.

    --------------------------------------------------------
    */

    cpu_run(
        &cpu,
        program,
        program_size
    );


    /*
    --------------------------------------------------------
    Display final state
    --------------------------------------------------------
    */

    cpu_print_state(&cpu);


    printf(
        "\nExpected result: R2 = 30\n"
    );


    printf(
        "CPU architecture demonstration complete.\n"
    );


    return 0;
}