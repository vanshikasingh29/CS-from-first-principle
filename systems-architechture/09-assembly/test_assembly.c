/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 9 — Assembly Language

File:

test_assembly.c

Purpose:

Automated tests for the x86-64 assembly exercises.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>


/*
============================================================
Assembly functions

These functions are implemented in:

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
Simple Test Framework
============================================================
*/

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
Test addition
============================================================
*/

static void test_addition(void)
{
    long result =
        add_numbers(
            10,
            5
        );


    assert_test(
        result == 15,
        "Assembly addition"
    );
}


/*
============================================================
Test multiplication
============================================================
*/

static void test_multiplication(void)
{
    long result =
        multiply_numbers(
            6,
            7
        );


    assert_test(
        result == 42,
        "Assembly multiplication"
    );
}


/*
============================================================
Test factorial
============================================================
*/

static void test_factorial(void)
{
    long result =
        factorial(5);


    assert_test(
        result == 120,
        "Assembly factorial"
    );
}


/*
============================================================
Test factorial base case
============================================================
*/

static void test_factorial_base_case(void)
{
    long result =
        factorial(1);


    assert_test(
        result == 1,
        "Factorial base case"
    );
}


/*
============================================================
Test stack operation
============================================================
*/

static void test_stack(void)
{
    long result =
        stack_demo();


    assert_test(
        result == 42,
        "Assembly stack operation"
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

    printf(
        "========================================\n"
    );

    printf(
        " Assembly Language Test Suite\n"
    );

    printf(
        "========================================\n\n"
    );


    test_addition();

    test_multiplication();

    test_factorial();

    test_factorial_base_case();

    test_stack();


    printf("\n");

    printf(
        "Results\n"
    );

    printf(
        "--------------------\n"
    );


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
            "\nAll assembly tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome assembly tests failed.\n"
    );


    return EXIT_FAILURE;
}