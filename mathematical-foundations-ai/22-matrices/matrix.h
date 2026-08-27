/*
============================================================

CS From First Principles

Phase 5 — Mathematical Foundations for AI

Topic 22 — Matrices

File:
matrix.h

Purpose:
Defines the matrix data structure and matrix operations.

============================================================
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <stddef.h>


/*
============================================================
Matrix Structure
============================================================
*/

typedef struct
{
    size_t rows;
    size_t columns;

    double *data;

} Matrix;


/*
============================================================
Matrix Creation
============================================================
*/

/*
Create a matrix with the specified dimensions.

All elements are initialised to zero.
*/
Matrix matrix_create(
    size_t rows,
    size_t columns
);


/*
Create an identity matrix.

Example for size 3:

1 0 0
0 1 0
0 0 1
*/
Matrix matrix_identity(
    size_t size
);


/*
============================================================
Memory Management
============================================================
*/

/*
Release memory owned by a matrix.
*/
void matrix_free(
    Matrix *matrix
);


/*
============================================================
Element Access
============================================================
*/

/*
Get an element from a matrix.

Returns 0.0 if the position is invalid.
*/
double matrix_get(
    const Matrix *matrix,
    size_t row,
    size_t column
);


/*
Set an element in a matrix.

Returns 1 on success.
Returns 0 if the position is invalid.
*/
int matrix_set(
    Matrix *matrix,
    size_t row,
    size_t column,
    double value
);


/*
============================================================
Matrix Operations
============================================================
*/

/*
Add two matrices.

Returns an empty matrix if dimensions do not match.
*/
Matrix matrix_add(
    const Matrix *a,
    const Matrix *b
);


/*
Multiply every element by a scalar.
*/
Matrix matrix_scalar_multiply(
    const Matrix *matrix,
    double scalar
);


/*
Matrix multiplication.

A must have the same number of columns
as B has rows.
*/
Matrix matrix_multiply(
    const Matrix *a,
    const Matrix *b
);


/*
Transpose a matrix.
*/
Matrix matrix_transpose(
    const Matrix *matrix
);


/*
============================================================
Matrix-Vector Multiplication
============================================================
*/

/*
Calculate:

A × x

The vector is represented as an array.

Returns NULL on failure.

The caller owns the returned memory.
*/
double *matrix_vector_multiply(
    const Matrix *matrix,
    const double *vector,
    size_t vector_size
);


/*
============================================================
Output
============================================================
*/

void matrix_print(
    const Matrix *matrix
);


/*
============================================================
Validation
============================================================
*/

int matrix_is_empty(
    const Matrix *matrix
);

#endif