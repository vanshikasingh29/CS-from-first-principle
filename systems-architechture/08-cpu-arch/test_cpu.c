/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 8 — CPU Architecture

File:
test_cpu.c

Purpose:
Automated tests for the CPU simulator.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>

#include "cpu.h"


static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char *test_name
)
{
    if (condition)
    {
        printf(
            "[PASS] %s\n",
            test_name
        );

        tests_passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            test_name
        );

        tests_failed++;
    }
}


/*
============================================================
CPU Initialisation
============================================================
*/

static void test_cpu_initialisation(void)
{
    CPU cpu;


    cpu_init(&cpu);


    int passed =
        cpu.program_counter == 0 &&
        cpu.accumulator == 0 &&
        cpu.zero_flag == 0 &&
        cpu.halted == 0 &&
        cpu.registers[0] == 0 &&
        cpu.registers[1] == 0;


    assert_test(
        passed,
        "CPU initialisation"
    );
}


/*
============================================================
Load Immediate
============================================================
*/

static void test_load_immediate(void)
{
    CPU cpu;


    const Instruction program[] =
    {
        {
            OP_LOAD_IMMEDIATE,
            42
        },

        {
            OP_HALT,
            0
        }
    };


    cpu_init(&cpu);


    cpu_run(
        &cpu,
        program,
        2
    );


    assert_test(
        cpu.accumulator == 42,
        "Load immediate instruction"
    );
}


/*
============================================================
Store and Load
============================================================
*/

static void test_register_operations(void)
{
    CPU cpu;


    const Instruction program[] =
    {
        {
            OP_LOAD_IMMEDIATE,
            25
        },

        {
            OP_STORE,
            0
        },

        {
            OP_LOAD_IMMEDIATE,
            0
        },

        {
            OP_LOAD,
            0
        },

        {
            OP_HALT,
            0
        }
    };


    cpu_init(&cpu);


    cpu_run(
        &cpu,
        program,
        5
    );


    assert_test(
        cpu.registers[0] == 25,
        "Store to register"
    );


    assert_test(
        cpu.accumulator == 25,
        "Load from register"
    );
}


/*
============================================================
Arithmetic
============================================================
*/

static void test_arithmetic(void)
{
    CPU cpu;


    const Instruction program[] =
    {
        {
            OP_LOAD_IMMEDIATE,
            10
        },

        {
            OP_STORE,
            0
        },

        {
            OP_LOAD_IMMEDIATE,
            20
        },

        {
            OP_STORE,
            1
        },

        {
            OP_LOAD,
            0
        },

        {
            OP_ADD,
            1
        },

        {
            OP_STORE,
            2
        },

        {
            OP_HALT,
            0
        }
    };


    cpu_init(&cpu);


    cpu_run(
        &cpu,
        program,
        8
    );


    assert_test(
        cpu.registers[2] == 30,
        "CPU addition"
    );
}


/*
============================================================
Subtraction
============================================================
*/

static void test_subtraction(void)
{
    CPU cpu;


    const Instruction program[] =
    {
        {
            OP_LOAD_IMMEDIATE,
            30
        },

        {
            OP_STORE,
            0
        },

        {
            OP_LOAD_IMMEDIATE,
            10
        },

        {
            OP_STORE,
            1
        },

        {
            OP_LOAD,
            0
        },

        {
            OP_SUB,
            1
        },

        {
            OP_HALT,
            0
        }
    };


    cpu_init(&cpu);


    cpu_run(
        &cpu,
        program,
        7
    );


    assert_test(
        cpu.accumulator == 20,
        "CPU subtraction"
    );
}


/*
============================================================
HALT
============================================================
*/

static void test_halt(void)
{
    CPU cpu;


    const Instruction program[] =
    {
        {
            OP_HALT,
            0
        }
    };


    cpu_init(&cpu);


    cpu_run(
        &cpu,
        program,
        1
    );


    assert_test(
        cpu.halted == 1,
        "HALT instruction"
    );
}


/*
============================================================
Main Test Runner
============================================================
*/

int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" CPU Architecture Test Suite\n");
    printf("========================================\n\n");


    test_cpu_initialisation();

    test_load_immediate();

    test_register_operations();

    test_arithmetic();

    test_subtraction();

    test_halt();


    printf("\n");
    printf("Results\n");
    printf("--------------------\n");


    printf(
        "Passed: %d\n",
        tests_passed
    );


    printf(
        "Failed: %d\n",
        tests_failed
    );


    if (tests_failed == 0)
    {
        printf(
            "\nAll CPU architecture tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome CPU architecture tests failed.\n"
    );


    return EXIT_FAILURE;
}