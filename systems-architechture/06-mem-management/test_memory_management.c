/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 6 — Manual Memory Management

File:
test_memory_management.c

Purpose:
Basic automated tests for the memory-management exercises.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>


/*
============================================================
Functions under test

These are implemented in memory_management.c.

============================================================
*/

int *create_integer(int value);

int *create_array(size_t size);

int *create_zero_array(size_t size);

int *resize_array(
    int *array,
    size_t new_size
);

long calculate_sum(
    const int *array,
    size_t size
);


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
Test malloc() single allocation
============================================================
*/

static void test_integer_allocation(void)
{
    int *number =
        create_integer(42);


    int passed =
        number != NULL &&
        *number == 42;


    assert_test(
        passed,
        "Single integer allocation"
    );


    free(number);
}


/*
============================================================
Test dynamic array
============================================================
*/

static void test_dynamic_array(void)
{
    size_t size = 5;


    int *array =
        create_array(size);


    int passed =
        array != NULL &&
        array[0] == 0 &&
        array[4] == 4;


    assert_test(
        passed,
        "Dynamic array allocation"
    );


    free(array);
}


/*
============================================================
Test calloc()
============================================================
*/

static void test_zero_array(void)
{
    size_t size = 5;


    int *array =
        create_zero_array(size);


    int passed =
        array != NULL &&
        array[0] == 0 &&
        array[1] == 0 &&
        array[4] == 0;


    assert_test(
        passed,
        "calloc zero initialisation"
    );


    free(array);
}


/*
============================================================
Test array sum
============================================================
*/

static void test_array_sum(void)
{
    size_t size = 4;


    int *array =
        create_array(size);


    int passed =
        array != NULL &&
        calculate_sum(
            array,
            size
        ) == 6;


    assert_test(
        passed,
        "Dynamic array sum"
    );


    free(array);
}


/*
============================================================
Test realloc()
============================================================
*/

static void test_array_resize(void)
{
    size_t original_size = 3;


    int *array =
        create_array(
            original_size
        );


    if (array == NULL)
    {
        assert_test(
            0,
            "Dynamic array resize"
        );

        return;
    }


    int *resized =
        resize_array(
            array,
            6
        );


    int passed =
        resized != NULL &&
        resized[0] == 0 &&
        resized[1] == 1 &&
        resized[2] == 2;


    assert_test(
        passed,
        "Dynamic array resize"
    );


    free(resized);
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
    printf(" Memory Management Test Suite\n");
    printf("========================================\n\n");


    test_integer_allocation();

    test_dynamic_array();

    test_zero_array();

    test_array_sum();

    test_array_resize();


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
            "\nAll memory management tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome memory management tests failed.\n"
    );


    return EXIT_FAILURE;
}