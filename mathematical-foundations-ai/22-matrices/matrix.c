/*
============================================================

CS From First Principles

Phase 5 — Mathematical Foundations for AI

Topic 22 — Matrices

File:
matrix.c

Purpose:
Implements fundamental matrix operations from scratch.

============================================================
*/

#include "matrix.h"

#include <stdio.h>
#include <stdlib.h>


/*
============================================================
Internal Helper
============================================================
*/

/*
Calculate the position of an element inside the
one-dimensional data array.

For a matrix:

rows × columns

the element at:

(row, column)

is stored at:

row * columns + column
*/
static size_t matrix_index(
    const Matrix *matrix,
    size_t row,
    size_t column
)
{
    return row * matrix->columns + column;
}


/*
============================================================
Create Matrix
============================================================
*/

Matrix matrix_create(
    size_t rows,
    size_t columns
)
{
    Matrix matrix;

    matrix.rows = rows;
    matrix.columns = columns;
    matrix.data = NULL;


    /*
    Prevent meaningless zero-sized allocation.
    */

    if (rows == 0 || columns == 0)
    {
        return matrix;
    }


    /*
    Allocate contiguous memory.

    rows × columns elements are required.
    */

    matrix.data =
        calloc(
            rows * columns,
            sizeof(double)
        );


    /*
    If allocation fails, return an empty matrix.
    */

    if (matrix.data == NULL)
    {
        matrix.rows = 0;
        matrix.columns = 0;
    }


    return matrix;
}


/*
============================================================
Identity Matrix
============================================================
*/

Matrix matrix_identity(
    size_t size
)
{
    Matrix matrix =
        matrix_create(
            size,
            size
        );


    if (matrix_is_empty(&matrix))
    {
        return matrix;
    }


    /*
    Identity matrix:

    1 0 0
    0 1 0
    0 0 1

    Only diagonal elements are 1.
    */

    for (size_t i = 0; i < size; i++)
    {
        matrix_set(
            &matrix,
            i,
            i,
            1.0
        );
    }


    return matrix;
}


/*
============================================================
Free Matrix
============================================================
*/

void matrix_free(
    Matrix *matrix
)
{
    if (matrix == NULL)
    {
        return;
    }


    free(matrix->data);


    matrix->data = NULL;
    matrix->rows = 0;
    matrix->columns = 0;
}


/*
============================================================
Get Element
============================================================
*/

double matrix_get(
    const Matrix *matrix,
    size_t row,
    size_t column
)
{
    if (matrix == NULL ||
        matrix->data == NULL)
    {
        return 0.0;
    }


    if (row >= matrix->rows ||
        column >= matrix->columns)
    {
        return 0.0;
    }


    return matrix->data[
        matrix_index(
            matrix,
            row,
            column
        )
    ];
}


/*
============================================================
Set Element
============================================================
*/

int matrix_set(
    Matrix *matrix,
    size_t row,
    size_t column,
    double value
)
{
    if (matrix == NULL ||
        matrix->data == NULL)
    {
        return 0;
    }


    if (row >= matrix->rows ||
        column >= matrix->columns)
    {
        return 0;
    }


    matrix->data[
        matrix_index(
            matrix,
            row,
            column
        )
    ] = value;


    return 1;
}


/*
============================================================
Matrix Addition
============================================================
*/

Matrix matrix_add(
    const Matrix *a,
    const Matrix *b
)
{
    Matrix result =
        matrix_create(0, 0);


    if (a == NULL || b == NULL)
    {
        return result;
    }


    /*
    Matrix addition requires
    identical dimensions.
    */

    if (a->rows != b->rows ||
        a->columns != b->columns)
    {
        return result;
    }


    result =
        matrix_create(
            a->rows,
            a->columns
        );


    if (matrix_is_empty(&result))
    {
        return result;
    }


    for (size_t i = 0;
         i < a->rows;
         i++)
    {
        for (size_t j = 0;
             j < a->columns;
             j++)
        {
            double value =
                matrix_get(
                    a,
                    i,
                    j
                )
                +
                matrix_get(
                    b,
                    i,
                    j
                );


            matrix_set(
                &result,
                i,
                j,
                value
            );
        }
    }


    return result;
}


/*
============================================================
Scalar Multiplication
============================================================
*/

Matrix matrix_scalar_multiply(
    const Matrix *matrix,
    double scalar
)
{
    Matrix result =
        matrix_create(0, 0);


    if (matrix == NULL)
    {
        return result;
    }


    result =
        matrix_create(
            matrix->rows,
            matrix->columns
        );


    if (matrix_is_empty(&result))
    {
        return result;
    }


    for (size_t i = 0;
         i < matrix->rows;
         i++)
    {
        for (size_t j = 0;
             j < matrix->columns;
             j++)
        {
            double value =
                matrix_get(
                    matrix,
                    i,
                    j
                )
                * scalar;


            matrix_set(
                &result,
                i,
                j,
                value
            );
        }
    }


    return result;
}


/*
============================================================
Matrix Multiplication
============================================================
*/

Matrix matrix_multiply(
    const Matrix *a,
    const Matrix *b
)
{
    Matrix result =
        matrix_create(0, 0);


    if (a == NULL || b == NULL)
    {
        return result;
    }


    /*
    Matrix multiplication requires:

    A columns == B rows

    If:

    A = m × n

    B = n × p

    result = m × p
    */

    if (a->columns != b->rows)
    {
        return result;
    }


    result =
        matrix_create(
            a->rows,
            b->columns
        );


    if (matrix_is_empty(&result))
    {
        return result;
    }


    /*
    Standard O(n^3) matrix multiplication.

    result[i][j] =
        Σ A[i][k] × B[k][j]
    */

    for (size_t i = 0;
         i < a->rows;
         i++)
    {
        for (size_t j = 0;
             j < b->columns;
             j++)
        {
            double sum = 0.0;


            for (size_t k = 0;
                 k < a->columns;
                 k++)
            {
                sum +=
                    matrix_get(
                        a,
                        i,
                        k
                    )
                    *
                    matrix_get(
                        b,
                        k,
                        j
                    );
            }


            matrix_set(
                &result,
                i,
                j,
                sum
            );
        }
    }


    return result;
}


/*
============================================================
Transpose
============================================================
*/

Matrix matrix_transpose(
    const Matrix *matrix
)
{
    Matrix result =
        matrix_create(0, 0);


    if (matrix == NULL)
    {
        return result;
    }


    /*
    Rows become columns.

    m × n

    becomes

    n × m
    */

    result =
        matrix_create(
            matrix->columns,
            matrix->rows
        );


    if (matrix_is_empty(&result))
    {
        return result;
    }


    for (size_t i = 0;
         i < matrix->rows;
         i++)
    {
        for (size_t j = 0;
             j < matrix->columns;
             j++)
        {
            matrix_set(
                &result,
                j,
                i,
                matrix_get(
                    matrix,
                    i,
                    j
                )
            );
        }
    }


    return result;
}


/*
============================================================
Matrix × Vector
============================================================
*/

double *matrix_vector_multiply(
    const Matrix *matrix,
    const double *vector,
    size_t vector_size
)
{
    if (matrix == NULL ||
        vector == NULL ||
        matrix->data == NULL)
    {
        return NULL;
    }


    /*
    Matrix:

        m × n

    Vector:

        n

    Result:

        m
    */

    if (matrix->columns != vector_size)
    {
        return NULL;
    }


    double *result =
        calloc(
            matrix->rows,
            sizeof(double)
        );


    if (result == NULL)
    {
        return NULL;
    }


    for (size_t i = 0;
         i < matrix->rows;
         i++)
    {
        for (size_t j = 0;
             j < matrix->columns;
             j++)
        {
            result[i] +=
                matrix_get(
                    matrix,
                    i,
                    j
                )
                *
                vector[j];
        }
    }


    return result;
}


/*
============================================================
Print Matrix
============================================================
*/

void matrix_print(
    const Matrix *matrix
)
{
    if (matrix == NULL ||
        matrix->data == NULL)
    {
        printf("[empty matrix]\n");
        return;
    }


    for (size_t i = 0;
         i < matrix->rows;
         i++)
    {
        printf("[ ");


        for (size_t j = 0;
             j < matrix->columns;
             j++)
        {
            printf(
                "%.2f",
                matrix_get(
                    matrix,
                    i,
                    j
                )
            );


            if (j + 1 < matrix->columns)
            {
                printf("  ");
            }
        }


        printf(" ]\n");
    }
}


/*
============================================================
Check Empty Matrix
============================================================
*/

int matrix_is_empty(
    const Matrix *matrix
)
{
    if (matrix == NULL)
    {
        return 1;
    }


    return matrix->data == NULL ||
           matrix->rows == 0 ||
           matrix->columns == 0;
}