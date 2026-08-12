/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 6 — Manual Memory Management

File:

memory_lab.c

Purpose:

Demonstrate fundamental manual memory-management
operations in C.

Concepts demonstrated:

- stack allocation
- malloc
- calloc
- realloc
- free
- pointer ownership
- allocation failure

============================================================
*/

#include <stdio.h>
#include <stdlib.h>


/*
============================================================

Stack Allocation

============================================================

Local variables normally have automatic storage duration.

Their lifetime is associated with the function scope.

============================================================
*/

void demonstrate_stack(void)
{
    int value = 42;

    printf(
        "\n[STACK]\n"
    );

    printf(
        "Value: %d\n",
        value
    );

    printf(
        "Address: %p\n",
        (void *)&value
    );
}


/*
============================================================

malloc

============================================================

malloc allocates a block of memory.

The memory is uninitialised.

============================================================
*/

void demonstrate_malloc(void)
{
    printf(
        "\n[MALLOC]\n"
    );

    int *numbers =
        malloc(
            5 * sizeof(int)
        );


    /*
    Always check whether allocation succeeded.
    */

    if (numbers == NULL)
    {
        fprintf(
            stderr,
            "malloc failed\n"
        );

        return;
    }


    /*
    Initialise the allocated memory ourselves.
    */

    for (int i = 0; i < 5; i++)
    {
        numbers[i] =
            (i + 1) * 10;
    }


    for (int i = 0; i < 5; i++)
    {
        printf(
            "numbers[%d] = %d\n",
            i,
            numbers[i]
        );
    }


    /*
    Release the allocation.

    The program owns this memory, so it is
    responsible for releasing it.
    */

    free(numbers);

    numbers = NULL;
}


/*
============================================================

calloc

============================================================

calloc allocates memory and zero-initialises it.

============================================================
*/

void demonstrate_calloc(void)
{
    printf(
        "\n[CALLOC]\n"
    );


    int *numbers =
        calloc(
            5,
            sizeof(int)
        );


    if (numbers == NULL)
    {
        fprintf(
            stderr,
            "calloc failed\n"
        );

        return;
    }


    /*
    calloc initialises the allocated bytes to zero.
    */

    for (int i = 0; i < 5; i++)
    {
        printf(
            "numbers[%d] = %d\n",
            i,
            numbers[i]
        );
    }


    free(numbers);

    numbers = NULL;
}


/*
============================================================

realloc

============================================================

realloc changes the size of an existing allocation.

We use a temporary pointer so that a failed
reallocation does not destroy the original pointer.

============================================================
*/

void demonstrate_realloc(void)
{
    printf(
        "\n[REALLOC]\n"
    );


    int *numbers =
        malloc(
            3 * sizeof(int)
        );


    if (numbers == NULL)
    {
        fprintf(
            stderr,
            "Initial malloc failed\n"
        );

        return;
    }


    numbers[0] = 10;
    numbers[1] = 20;
    numbers[2] = 30;


    printf(
        "Before resize:\n"
    );


    for (int i = 0; i < 3; i++)
    {
        printf(
            "numbers[%d] = %d\n",
            i,
            numbers[i]
        );
    }


    /*
    Attempt to increase the allocation.
    */

    int *temporary =
        realloc(
            numbers,
            5 * sizeof(int)
        );


    if (temporary == NULL)
    {
        /*
        The original allocation is still valid.

        We must free it before returning.
        */

        fprintf(
            stderr,
            "realloc failed\n"
        );

        free(numbers);

        numbers = NULL;

        return;
    }


    /*
    Reallocation succeeded.

    The new pointer becomes the owner of
    the allocation.
    */

    numbers = temporary;


    numbers[3] = 40;
    numbers[4] = 50;


    printf(
        "After resize:\n"
    );


    for (int i = 0; i < 5; i++)
    {
        printf(
            "numbers[%d] = %d\n",
            i,
            numbers[i]
        );
    }


    free(numbers);

    numbers = NULL;
}


/*
============================================================

Main

============================================================
*/

int main(void)
{
    printf(
        "=====================================\n"
        " Manual Memory Management Laboratory\n"
        "=====================================\n"
    );


    demonstrate_stack();

    demonstrate_malloc();

    demonstrate_calloc();

    demonstrate_realloc();


    printf(
        "\nMemory laboratory completed.\n"
    );


    return 0;
}