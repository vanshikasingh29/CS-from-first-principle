/*
============================================================

CS From First Principles

Phase 5 — Mathematical Foundations for AI

Topic 22 — Matrices

File:
main.c

Purpose:
Demonstrates matrix operations.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Matrix Operations Demonstration\n");
    printf("========================================\n");


    /*
    --------------------------------------------------------
    Create Matrix A
    --------------------------------------------------------
    */

    Matrix a =
        matrix_create(
            2,
            2
        );


    matrix_set(&a, 0, 0, 1);
    matrix_set(&a, 0, 1, 2);
    matrix_set(&a, 1, 0, 3);
    matrix_set(&a, 1, 1, 4);


    printf("\nMatrix A:\n");

    matrix_print(&a);


    /*
    --------------------------------------------------------
    Create Matrix B
    --------------------------------------------------------
    */

    Matrix b =
        matrix_create(
            2,
            2
        );


    matrix_set(&b, 0, 0, 5);
    matrix_set(&b, 0, 1, 6);
    matrix_set(&b, 1, 0, 7);
    matrix_set(&b, 1, 1, 8);


    printf("\nMatrix B:\n");

    matrix_print(&b);


    /*
    --------------------------------------------------------
    Addition
    --------------------------------------------------------
    */

    Matrix sum =
        matrix_add(
            &a,
            &b
        );


    printf("\nA + B:\n");

    matrix_print(&sum);


    /*
    --------------------------------------------------------
    Matrix Multiplication
    --------------------------------------------------------
    */

    Matrix product =
        matrix_multiply(
            &a,
            &b
        );


    printf("\nA × B:\n");

    matrix_print(&product);


    /*
    --------------------------------------------------------
    Transpose
    --------------------------------------------------------
    */

    Matrix transpose =
        matrix_transpose(
            &a
        );


    printf("\nTranspose of A:\n");

    matrix_print(&transpose);


    /*
    --------------------------------------------------------
    Identity Matrix
    --------------------------------------------------------
    */

    Matrix identity =
        matrix_identity(3);


    printf("\n3 × 3 Identity Matrix:\n");

    matrix_print(&identity);


    /*
    --------------------------------------------------------
    Matrix × Vector
    --------------------------------------------------------
    */

    double vector[] =
    {
        3,
        4
    };


    double *result =
        matrix_vector_multiply(
            &a,
            vector,
            2
        );


    printf("\nA × vector [3, 4]:\n");

    if (result != NULL)
    {
        printf(
            "[ %.2f, %.2f ]\n",
            result[0],
            result[1]
        );
    }


    /*
    --------------------------------------------------------
    Release Memory
    --------------------------------------------------------
    */

    free(result);

    matrix_free(&a);
    matrix_free(&b);
    matrix_free(&sum);
    matrix_free(&product);
    matrix_free(&transpose);
    matrix_free(&identity);


    printf(
        "\nMatrix laboratory complete.\n"
    );


    return EXIT_SUCCESS;
}