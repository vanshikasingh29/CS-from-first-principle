#include "vector_space.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>


Vector vector_create(
    const double *values,
    size_t size
)
{
    Vector vector;

    vector.size = size;
    vector.data = NULL;

    if (size == 0)
    {
        return vector;
    }

    vector.data =
        malloc(size * sizeof(double));

    if (vector.data == NULL)
    {
        vector.size = 0;
        return vector;
    }

    for (size_t i = 0; i < size; i++)
    {
        vector.data[i] = values[i];
    }

    return vector;
}


void vector_destroy(Vector *vector)
{
    if (vector == NULL)
    {
        return;
    }

    free(vector->data);

    vector->data = NULL;
    vector->size = 0;
}


Vector vector_add(
    const Vector *a,
    const Vector *b
)
{
    Vector result = {NULL, 0};

    if (a == NULL || b == NULL)
    {
        return result;
    }

    if (a->size != b->size)
    {
        return result;
    }

    result.data =
        malloc(a->size * sizeof(double));

    if (result.data == NULL)
    {
        return result;
    }

    result.size = a->size;

    for (size_t i = 0; i < a->size; i++)
    {
        result.data[i] =
            a->data[i] + b->data[i];
    }

    return result;
}


Vector vector_scale(
    const Vector *vector,
    double scalar
)
{
    Vector result = {NULL, 0};

    if (vector == NULL)
    {
        return result;
    }

    result.data =
        malloc(vector->size * sizeof(double));

    if (result.data == NULL)
    {
        return result;
    }

    result.size = vector->size;

    for (size_t i = 0; i < vector->size; i++)
    {
        result.data[i] =
            vector->data[i] * scalar;
    }

    return result;
}


double vector_dot(
    const Vector *a,
    const Vector *b
)
{
    if (a == NULL || b == NULL)
    {
        return 0.0;
    }

    if (a->size != b->size)
    {
        return 0.0;
    }

    double result = 0.0;

    for (size_t i = 0; i < a->size; i++)
    {
        result +=
            a->data[i] * b->data[i];
    }

    return result;
}


double vector_norm(
    const Vector *vector
)
{
    if (vector == NULL)
    {
        return 0.0;
    }

    return sqrt(
        vector_dot(vector, vector)
    );
}


void vector_print(
    const Vector *vector
)
{
    if (vector == NULL)
    {
        return;
    }

    printf("[");

    for (size_t i = 0; i < vector->size; i++)
    {
        printf("%.2f", vector->data[i]);

        if (i + 1 < vector->size)
        {
            printf(", ");
        }
    }

    printf("]\n");
}