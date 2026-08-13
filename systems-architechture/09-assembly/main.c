/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 9 — Assembly Language

File:

main.c

Purpose:

Runs the x86-64 assembly demonstrations.

============================================================
*/

#include <stdio.h>


/*
============================================================
Assembly functions

Implemented in:

assembly_basics.asm
============================================================
*/

long add_numbers(
    long a,
    long b
);


long multiply_numbers(
    long a,
    long b
);


long factorial(
    long n
);


long stack_demo(void);


/*
============================================================
Main
============================================================
*/

int main(void)
{
    printf("\n");

    printf(
        "========================================\n"
    );

    printf(
        " x86-64 Assembly Demonstration\n"
    );

    printf(
        "========================================\n\n"
    );


    /*
    --------------------------------------------------------
    1. Register arithmetic
    --------------------------------------------------------
    */

    printf(
        "1. Register arithmetic\n"
    );

    printf(
        "10 + 5 = %ld\n",
        add_numbers(10, 5)
    );


    /*
    --------------------------------------------------------
    2. Integer multiplication
    --------------------------------------------------------
    */

    printf(
        "\n2. Integer multiplication\n"
    );

    printf(
        "6 * 7 = %ld\n",
        multiply_numbers(6, 7)
    );


    /*
    --------------------------------------------------------
    3. Loop and conditional branching
    --------------------------------------------------------
    */

    printf(
        "\n3. Loop and conditional branching\n"
    );

    printf(
        "5! = %ld\n",
        factorial(5)
    );


    /*
    --------------------------------------------------------
    4. Stack operation
    --------------------------------------------------------
    */

    printf(
        "\n4. Stack operation\n"
    );

    printf(
        "Value restored from stack: %ld\n",
        stack_demo()
    );


    printf(
        "\nAssembly demonstration complete.\n"
    );


    return 0;
}