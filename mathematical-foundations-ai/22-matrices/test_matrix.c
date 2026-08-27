/*
============================================================

CS From First Principles

Phase 5 — Mathematical Foundations for AI

Topic 22 — Matrices

File:
test_matrix.c

Purpose:
Automated tests for the matrix implementation.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"


/*
============================================================
Test Framework
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
Compare floating-point values safely.
*/

static int approximately_equal(
    double a,
    double b
)
{
    return fabs(a - b) < 0.000001;
}


/*
============================================================
Test Matrix Creation
============================================================
*/

static void test_creation(void)
{
    Matrix matrix =
        matrix_create(
            2,
            3
        );


    int passed =
        matrix.rows == 2 &&
        matrix.columns == 3 &&
        matrix.data != NULL &&
        approximately_equal(
            matrix_get(
                &matrix,
                0,
                0
            ),
            0.0
        );


    assert_test(
        passed,
        "Matrix creation"
    );


    matrix_free(&matrix);
}


/*
============================================================
Test Element Access
============================================================
*/

static void test_element_access(void)
{
    Matrix matrix =
        matrix_create(
            2,
            2
        );


    matrix_set(
        &matrix,
        0,
        1,
        42.0
    );


    int passed =
        approximately_equal(
            matrix_get(
                &matrix,
                0,
                1
            ),
            42.0
        );


    assert_test(
        passed,
        "Matrix element access"
    );


    matrix_free(&matrix);
}


/*
============================================================
Test Addition
============================================================
*/

static void test_addition(void)
{
    Matrix a =
        matrix_create(
            2,
            2
        );


    Matrix b =
        matrix_create(
            2,
            2
        );


    matrix_set(&a, 0, 0, 1);
    matrix_set(&a, 0, 1, 2);
    matrix_set(&a, 1, 0, 3);
    matrix_set(&a, 1, 1, 4);


    matrix_set(&b, 0, 0, 5);
    matrix_set(&b, 0, 1, 6);
    matrix_set(&b, 1, 0, 7);
    matrix_set(&b, 1, 1, 8);


    Matrix result =
        matrix_add(
            &a,
            &b
        );


    int passed =
        approximately_equal(
            matrix_get(
                &result,
                0,
                0
            ),
            6
        )
        &&
        approximately_equal(
            matrix_get(
                &result,
                1,
                1
            ),
            12
        );


    assert_test(
        passed,
        "Matrix addition"
    );


    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&result);
}


/*
============================================================
Test Scalar Multiplication
============================================================
*/

static void test_scalar_multiplication(void)
{
    Matrix matrix =
        matrix_create(
            2,
            2
        );


    matrix_set(&matrix, 0, 0, 1);
    matrix_set(&matrix, 0, 1, 2);
    matrix_set(&matrix, 1, 0, 3);
    matrix_set(&matrix, 1, 1, 4);


    Matrix result =
        matrix_scalar_multiply(
            &matrix,
            2.0
        );


    int passed =
        approximately_equal(
            matrix_get(
                &result,
                0,
                0
            ),
            2
        )
        &&
        approximately_equal(
            matrix_get(
                &result,
                1,
                1
            ),
            8
        );


    assert_test(
        passed,
        "Scalar multiplication"
    );


    matrix_free(&matrix);
    matrix_free(&result);
}


/*
============================================================
Test Matrix Multiplication
============================================================
*/

static void test_multiplication(void)
{
    Matrix a =
        matrix_create(
            2,
            2
        );


    Matrix b =
        matrix_create(
            2,
            2
        );


    matrix_set(&a, 0, 0, 1);
    matrix_set(&a, 0, 1, 2);
    matrix_set(&a, 1, 0, 3);
    matrix_set(&a, 1, 1, 4);


    matrix_set(&b, 0, 0, 5);
    matrix_set(&b, 0, 1, 6);
    matrix_set(&b, 1, 0, 7);
    matrix_set(&b, 1, 1, 8);


    Matrix result =
        matrix_multiply(
            &a,
            &b
        );


    /*
    Expected:

    19 22
    43 50
    */

    int passed =
        approximately_equal(
            matrix_get(
                &result,
                0,
                0
            ),
            19
        )
        &&
        approximately_equal(
            matrix_get(
                &result,
                0,
                1
            ),
            22
        )
        &&
        approximately_equal(
            matrix_get(
                &result,
                1,
                0
            ),
            43
        )
        &&
        approximately_equal(
            matrix_get(
                &result,
                1,
                1
            ),
            50
        );


    assert_test(
        passed,
        "Matrix multiplication"
    );


    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&result);
}


/*
============================================================
Test Transpose
============================================================
*/

static void test_transpose(void)
{
    Matrix matrix =
        matrix_create(
            2,
            3
        );


    matrix_set(&matrix, 0, 0, 1);
    matrix_set(&matrix, 0, 1, 2);
    matrix_set(&matrix, 0, 2, 3);

    matrix_set(&matrix, 1, 0, 4);
    matrix_set(&matrix, 1, 1, 5);
    matrix_set(&matrix, 1, 2, 6);


    Matrix result =
        matrix_transpose(
            &matrix
        );


    int passed =
        result.rows == 3 &&
        result.columns == 2 &&
        approximately_equal(
            matrix_get(
                &result,
                2,
                1
            ),
            6
        );


    assert_test(
        passed,
        "Matrix transpose"
    );


    matrix_free(&matrix);
    matrix_free(&result);
}


/*
============================================================
Test Identity Matrix
============================================================
*/

static void test_identity(void)
{
    Matrix identity =
        matrix_identity(3);


    int passed =
        matrix_get(
            &identity,
            0,
            0
        ) == 1.0
        &&
        matrix_get(
            &identity,
            1,
            1
        ) == 1.0
        &&
        matrix_get(
            &identity,
            2,
            2
        ) == 1.0
        &&
        matrix_get(
            &identity,
            0,
            1
        ) == 0.0;


    assert_test(
        passed,
        "Identity matrix"
    );


    matrix_free(&identity);
}


/*
============================================================
Test Matrix-Vector Multiplication
============================================================
*/

static void test_vector_multiplication(void)
{
    Matrix matrix =
        matrix_create(
            2,
            2
        );


    matrix_set(&matrix, 0, 0, 2);
    matrix_set(&matrix, 0, 1, 0);

    matrix_set(&matrix, 1, 0, 0);
    matrix_set(&matrix, 1, 1, 2);


    double vector[] =
    {
        3,
        4
    };


    double *result =
        matrix_vector_multiply(
            &matrix,
            vector,
            2
        );


    int passed =
        result != NULL &&
        approximately_equal(
            result[0],
            6
        )
        &&
        approximately_equal(
            result[1],
            8
        );


    assert_test(
        passed,
        "Matrix-vector multiplication"
    );


    free(result);

    matrix_free(&matrix);
}


/*
============================================================
Test Invalid Multiplication
============================================================
*/

static void test_invalid_multiplication(void)
{
    Matrix a =
        matrix_create(
            2,
            3
        );


    Matrix b =
        matrix_create(
            2,
            2
        );


    Matrix result =
        matrix_multiply(
            &a,
            &b
        );


    assert_test(
        matrix_is_empty(&result),
        "Invalid matrix multiplication rejected"
    );


    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&result);
}


/*
============================================================
Main
============================================================
*/

int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Matrix Operations Test Suite\n");
    printf("========================================\n\n");


    test_creation();

    test_element_access();

    test_addition();

    test_scalar_multiplication();

    test_multiplication();

    test_transpose();

    test_identity();

    test_vector_multiplication();

    test_invalid_multiplication();


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
            "\nAll matrix tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome matrix tests failed.\n"
    );


    return EXIT_FAILURE;
}