/*
============================================================

CS From First Principles

Topic 6 — Manual Memory Management

File:

allocation_examples.c

Purpose:

Small isolated examples of dynamic memory allocation.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>


/*
============================================================

Example 1 — malloc

============================================================
*/

void example_malloc(void)
{
    int *value =
        malloc(
            sizeof(int)
        );


    if (value == NULL)
    {
        printf(
            "Allocation failed.\n"
        );

        return;
    }


    *value = 100;


    printf(
        "malloc value: %d\n",
        *value
    );


    free(value);

    value = NULL;
}


/*
============================================================

Example 2 — calloc

============================================================
*/

void example_calloc(void)
{
    int *values =
        calloc(
            3,
            sizeof(int)
        );


    if (values == NULL)
    {
        printf(
            "Allocation failed.\n"
        );

        return;
    }


    printf(
        "calloc values: %d %d %d\n",
        values[0],
        values[1],
        values[2]
    );


    free(values);

    values = NULL;
}


/*
============================================================

Example 3 — realloc

============================================================
*/

void example_realloc(void)
{
    int *values =
        malloc(
            2 * sizeof(int)
        );


    if (values == NULL)
    {
        return;
    }


    values[0] = 10;
    values[1] = 20;


    int *temporary =
        realloc(
            values,
            4 * sizeof(int)
        );


    if (temporary == NULL)
    {
        free(values);

        return;
    }


    values = temporary;


    values[2] = 30;
    values[3] = 40;


    printf(
        "realloc values: %d %d %d %d\n",
        values[0],
        values[1],
        values[2],
        values[3]
    );


    free(values);

    values = NULL;
}


/*
============================================================

Main

============================================================
*/

int main(void)
{
    printf(
        "Manual Allocation Examples\n"
        "==========================\n"
    );


    example_malloc();

    example_calloc();

    example_realloc();


    return 0;
}