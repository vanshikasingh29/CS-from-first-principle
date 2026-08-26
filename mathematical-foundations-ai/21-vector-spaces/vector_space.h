
#ifndef VECTOR_SPACE_H
#define VECTOR_SPACE_H

#include <stddef.h>

/*
 * Dynamic mathematical vector.
 */
typedef struct
{
    double *data;
    size_t size;

} Vector;


/* Create a vector from an array of values. */
Vector vector_create(
    const double *values,
    size_t size
);


/* Release vector memory. */
void vector_destroy(Vector *vector);


/* Add two vectors. */
Vector vector_add(
    const Vector *a,
    const Vector *b
);


/* Multiply a vector by a scalar. */
Vector vector_scale(
    const Vector *vector,
    double scalar
);


/* Calculate the dot product. */
double vector_dot(
    const Vector *a,
    const Vector *b
);


/* Calculate the Euclidean norm. */
double vector_norm(
    const Vector *vector
);


/* Print a vector. */
void vector_print(
    const Vector *vector
);

#endif