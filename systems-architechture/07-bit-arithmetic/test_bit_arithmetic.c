/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 7 — Bit-Level Arithmetic

File:
test_bit_arithmetic.c

Purpose:
Automated tests for bit-level operations.

============================================================
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "bit_arithmetic.h"


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
Bitwise operation tests
============================================================
*/

static void test_bitwise_operations(void)
{
    assert_test(
        bitwise_and(12, 10) == 8,
        "Bitwise AND"
    );


    assert_test(
        bitwise_or(12, 10) == 14,
        "Bitwise OR"
    );


    assert_test(
        bitwise_xor(12, 10) == 6,
        "Bitwise XOR"
    );
}


/*
============================================================
Shift tests
============================================================
*/

static void test_shifts(void)
{
    assert_test(
        shift_left(3, 2) == 12,
        "Left shift"
    );


    assert_test(
        shift_right(12, 2) == 3,
        "Right shift"
    );
}


/*
============================================================
Individual bit tests
============================================================
*/

static void test_individual_bits(void)
{
    uint32_t value = 0;


    value = set_bit(value, 3);


    assert_test(
        value == 8,
        "Set bit"
    );


    assert_test(
        test_bit(value, 3) == 1,
        "Test set bit"
    );


    value = toggle_bit(value, 3);


    assert_test(
        value == 0,
        "Toggle bit"
    );


    value = set_bit(
        value,
        4
    );


    value = clear_bit(
        value,
        4
    );


    assert_test(
        value == 0,
        "Clear bit"
    );
}


/*
============================================================
Set-bit counting test
============================================================
*/

static void test_bit_count(void)
{
    assert_test(
        count_set_bits(0) == 0,
        "Count zero set bits"
    );


    assert_test(
        count_set_bits(29) == 4,
        "Count set bits"
    );


    assert_test(
        count_set_bits(UINT32_MAX) == 32,
        "Count all set bits"
    );
}


/*
============================================================
Boundary tests
============================================================
*/

static void test_boundaries(void)
{
    uint32_t value = 42;


    assert_test(
        set_bit(value, 32) == value,
        "Reject invalid set-bit position"
    );


    assert_test(
        clear_bit(value, 32) == value,
        "Reject invalid clear-bit position"
    );


    assert_test(
        toggle_bit(value, 32) == value,
        "Reject invalid toggle-bit position"
    );


    assert_test(
        test_bit(value, 32) == 0,
        "Reject invalid test-bit position"
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
    printf(" Bit-Level Arithmetic Test Suite\n");
    printf("========================================\n\n");


    test_bitwise_operations();

    test_shifts();

    test_individual_bits();

    test_bit_count();

    test_boundaries();


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
            "\nAll bit-level arithmetic tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome bit-level arithmetic tests failed.\n"
    );


    return EXIT_FAILURE;
}