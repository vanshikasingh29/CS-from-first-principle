/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 6 — Manual Memory Management

File:
main.c

Purpose:
Runs the manual memory management demonstration.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>


int *create_integer(int value);

int *create_array(size_t size);

int *create_zero_array(size_t size);

int *resize_array(
    int *array,
    size_t new_size
);

long calculate_sum(
    const int *array,
    size_t size
);

void print_array(
    const int *array,
    size_t size
);


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Manual Memory Management Demonstration\n");
    printf("========================================\n\n");


    /*
    --------------------------------------------------------
    1. Single heap allocation
    --------------------------------------------------------
    */

    printf("1. Single heap allocation\n");


    int *number =
        create_integer(42);


    if (number == NULL)
    {
        fprintf(
            stderr,
            "Failed to allocate integer.\n"
        );

        return EXIT_FAILURE;
    }


    printf(
        "Allocated integer: %d\n",
        *number
    );


    free(number);


    /*
    --------------------------------------------------------
    2. malloc() dynamic array
    --------------------------------------------------------
    */

    printf("\n2. malloc() dynamic array\n");


    size_t size = 5;


    int *array =
        create_array(size);


    if (array == NULL)
    {
        fprintf(
            stderr,
            "Failed to allocate array.\n"
        );

        return EXIT_FAILURE;
    }


    print_array(
        array,
        size
    );


    printf(
        "Sum: %ld\n",
        calculate_sum(
            array,
            size
        )
    );


    /*
    --------------------------------------------------------
    3. realloc() dynamic resizing
    --------------------------------------------------------
    */

    printf("\n3. realloc() resize\n");


    size_t new_size = 8;


    int *resized =
        resize_array(
            array,
            new_size
        );


    if (resized == NULL)
    {
        free(array);

        fprintf(
            stderr,
            "Failed to resize array.\n"
        );

        return EXIT_FAILURE;
    }


    array = resized;


    for (size_t i = size; i < new_size; i++)
    {
        array[i] = (int)i;
    }


    size = new_size;


    print_array(
        array,
        size
    );


    /*
    --------------------------------------------------------
    4. calloc()
    --------------------------------------------------------
    */

    printf("\n4. calloc() zero initialisation\n");


    size_t zero_size = 5;


    int *zero_array =
        create_zero_array(
            zero_size
        );


    if (zero_array == NULL)
    {
        free(array);

        fprintf(
            stderr,
            "Failed to allocate zero array.\n"
        );

        return EXIT_FAILURE;
    }


    print_array(
        zero_array,
        zero_size
    );


    /*
    --------------------------------------------------------
    5. Release heap allocations
    --------------------------------------------------------
    */

    free(array);

    free(zero_array);


    printf(
        "\nMemory management demonstration complete.\n"
    );


    return EXIT_SUCCESS;
}