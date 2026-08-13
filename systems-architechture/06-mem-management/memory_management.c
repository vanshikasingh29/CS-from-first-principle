/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 6 — Manual Memory Management

File:
memory_management.c

Purpose:
Implements dynamic memory management operations
using malloc(), calloc(), realloc(), and free().

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


/*
============================================================
Create Integer

Allocates one integer on the heap.

The caller becomes responsible for freeing
the returned memory.

============================================================
*/

int *create_integer(int value)
{
    int *number = malloc(sizeof(int));

    if (number == NULL)
    {
        return NULL;
    }

    *number = value;

    return number;
}


/*
============================================================
Create Dynamic Array

Allocates an integer array using malloc().

The array is initialised with values:

0, 1, 2, ..., size - 1

============================================================
*/

int *create_array(size_t size)
{
    /*
    malloc(0) has implementation-defined behaviour,
    so reject zero-sized allocations explicitly.
    */

    if (size == 0)
    {
        return NULL;
    }

    int *array =
        malloc(
            size * sizeof(int)
        );

    if (array == NULL)
    {
        return NULL;
    }

    for (size_t i = 0; i < size; i++)
    {
        array[i] = (int)i;
    }

    return array;
}


/*
============================================================
Create Zero-Initialised Array

Uses calloc() to allocate an array whose bytes
are initialised to zero.

============================================================
*/

int *create_zero_array(size_t size)
{
    if (size == 0)
    {
        return NULL;
    }

    int *array =
        calloc(
            size,
            sizeof(int)
        );

    return array;
}


/*
============================================================
Resize Array

Uses realloc() to change the size of an existing
heap allocation.

Important:

realloc() may move the allocation to a new memory
location.

The original pointer must therefore only be replaced
after realloc() succeeds.

============================================================
*/

int *resize_array(
    int *array,
    size_t new_size
)
{
    if (array == NULL || new_size == 0)
    {
        return NULL;
    }

    int *resized =
        realloc(
            array,
            new_size * sizeof(int)
        );

    if (resized == NULL)
    {
        /*
        The original allocation remains valid
        when realloc() fails.
        */

        return NULL;
    }

    return resized;
}


/*
============================================================
Calculate Sum

Demonstrates traversal of dynamically allocated memory.

============================================================
*/

long calculate_sum(
    const int *array,
    size_t size
)
{
    if (array == NULL)
    {
        return 0;
    }

    long sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += array[i];
    }

    return sum;
}


/*
============================================================
Print Array

Displays the contents of an integer array.

============================================================
*/

void print_array(
    const int *array,
    size_t size
)
{
    if (array == NULL)
    {
        printf("[]\n");
        return;
    }

    printf("[");

    for (size_t i = 0; i < size; i++)
    {
        printf(
            "%d",
            array[i]
        );

        if (i + 1 < size)
        {
            printf(", ");
        }
    }

    printf("]\n");
}