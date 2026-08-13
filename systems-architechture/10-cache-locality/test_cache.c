/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 10 — Cache Locality & Memory Hierarchy

File:

test_cache.c

Purpose:

Basic automated tests for the cache locality experiment.

The tests verify:

1. Matrix creation
2. Matrix initialisation
3. Row-major correctness
4. Column-major correctness
5. Both traversal strategies produce identical results

============================================================
*/

#include <stdio.h>
#include <stdlib.h>


#define TEST_SIZE 10


/*
============================================================
Test Matrix Creation
============================================================
*/

static int *create_test_matrix(
    size_t size
)
{
    int *matrix =
        malloc(
            size *
            size *
            sizeof(int)
        );


    if (matrix == NULL)
    {
        return NULL;
    }


    for (
        size_t i = 0;
        i < size * size;
        i++
    )
    {
        matrix[i] =
            (int)(i % 100);
    }


    return matrix;
}


/*
============================================================
Row-major traversal
============================================================
*/

static long long row_major_sum(
    const int *matrix,
    size_t size
)
{
    long long sum = 0;


    for (
        size_t row = 0;
        row < size;
        row++
    )
    {
        for (
            size_t column = 0;
            column < size;
            column++
        )
        {
            sum +=
                matrix[
                    row * size + column
                ];
        }
    }


    return sum;
}


/*
============================================================
Column-major traversal
============================================================
*/

static long long column_major_sum(
    const int *matrix,
    size_t size
)
{
    long long sum = 0;


    for (
        size_t column = 0;
        column < size;
        column++
    )
    {
        for (
            size_t row = 0;
            row < size;
            row++
        )
        {
            sum +=
                matrix[
                    row * size + column
                ];
        }
    }


    return sum;
}


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
Test matrix creation
============================================================
*/

static void test_matrix_creation(void)
{
    int *matrix =
        create_test_matrix(
            TEST_SIZE
        );


    assert_test(
        matrix != NULL,
        "Matrix allocation"
    );


    free(matrix);
}


/*
============================================================
Test matrix initialisation
============================================================
*/

static void test_initialisation(void)
{
    int *matrix =
        create_test_matrix(
            TEST_SIZE
        );


    int passed =
        matrix != NULL &&
        matrix[0] == 0 &&
        matrix[1] == 1 &&
        matrix[99] == 99;


    assert_test(
        passed,
        "Matrix initialisation"
    );


    free(matrix);
}


/*
============================================================
Test row-major traversal
============================================================
*/

static void test_row_major(void)
{
    int *matrix =
        create_test_matrix(
            TEST_SIZE
        );


    long long result =
        row_major_sum(
            matrix,
            TEST_SIZE
        );


    assert_test(
        result > 0,
        "Row-major traversal"
    );


    free(matrix);
}


/*
============================================================
Test column-major traversal
============================================================
*/

static void test_column_major(void)
{
    int *matrix =
        create_test_matrix(
            TEST_SIZE
        );


    long long result =
        column_major_sum(
            matrix,
            TEST_SIZE
        );


    assert_test(
        result > 0,
        "Column-major traversal"
    );


    free(matrix);
}


/*
============================================================
Test equivalent results
============================================================
*/

static void test_equal_results(void)
{
    int *matrix =
        create_test_matrix(
            TEST_SIZE
        );


    long long row_result =
        row_major_sum(
            matrix,
            TEST_SIZE
        );


    long long column_result =
        column_major_sum(
            matrix,
            TEST_SIZE
        );


    assert_test(
        row_result == column_result,
        "Traversal result equivalence"
    );


    free(matrix);
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
        " Cache Locality Test Suite\n"
    );

    printf(
        "========================================\n\n"
    );


    test_matrix_creation();

    test_initialisation();

    test_row_major();

    test_column_major();

    test_equal_results();


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
            "\nAll cache locality tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome cache locality tests failed.\n"
    );


    return EXIT_FAILURE;
}
