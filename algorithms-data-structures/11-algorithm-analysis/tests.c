/*
============================================================

CS From First Principles

Phase 3 — Algorithms & Data Structures

Topic 11 — Algorithm Analysis & Complexity

File:
tests.c

Purpose:
Automated correctness tests.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>

#include "algorithms.h"


static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf(
            "[PASS] %s\n",
            name
        );

        tests_passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            name
        );

        tests_failed++;
    }
}


/*
============================================================
Linear search tests
============================================================
*/

static void test_linear_search(void)
{
    int array[] =
    {
        10,
        20,
        30,
        40,
        50
    };


    assert_test(
        linear_search(
            array,
            5,
            30
        ) == 2,
        "Linear search successful lookup"
    );


    assert_test(
        linear_search(
            array,
            5,
            99
        ) == -1,
        "Linear search unsuccessful lookup"
    );
}


/*
============================================================
Binary search tests
============================================================
*/

static void test_binary_search(void)
{
    int array[] =
    {
        10,
        20,
        30,
        40,
        50,
        60
    };


    assert_test(
        binary_search(
            array,
            6,
            40
        ) == 3,
        "Binary search successful lookup"
    );


    assert_test(
        binary_search(
            array,
            6,
            99
        ) == -1,
        "Binary search unsuccessful lookup"
    );
}


/*
============================================================
Quadratic complexity test
============================================================
*/

static void test_quadratic_work(void)
{
    assert_test(
        quadratic_work(10) == 100,
        "Quadratic work for n=10"
    );


    assert_test(
        quadratic_work(20) == 400,
        "Quadratic work for n=20"
    );
}


/*
============================================================
Recursive sum tests
============================================================
*/

static void test_recursive_sum(void)
{
    int array[] =
    {
        1,
        2,
        3,
        4,
        5
    };


    assert_test(
        recursive_sum(
            array,
            5
        ) == 15,
        "Recursive array sum"
    );


    assert_test(
        recursive_sum(
            array,
            0
        ) == 0,
        "Recursive sum empty array"
    );
}


/*
============================================================
Test runner
============================================================
*/

int main(void)
{
    printf("\n");
    printf("=============================================\n");
    printf(" Algorithm Analysis Test Suite\n");
    printf("=============================================\n\n");


    test_linear_search();

    test_binary_search();

    test_quadratic_work();

    test_recursive_sum();


    printf("\n");
    printf("Results\n");
    printf("-----------------------------\n");


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
            "\nAll algorithm analysis tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome algorithm analysis tests failed.\n"
    );


    return EXIT_FAILURE;
}