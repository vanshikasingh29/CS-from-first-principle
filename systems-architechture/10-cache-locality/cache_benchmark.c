/*
============================================================

CS From First Principles

Phase 2 — Systems Architecture

Topic 10 — Cache Locality & Memory Hierarchy

File:

cache_benchmark.c

Purpose:

Demonstrate the performance effects of memory access
patterns.

The experiment compares:

1. Row-major traversal
2. Column-major traversal

Both perform approximately the same number of operations.

The difference is the memory access pattern.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*
============================================================
Configuration
============================================================
*/

/*
A large enough matrix makes memory access behaviour
more visible while remaining practical for a Codespace.
*/

#define MATRIX_SIZE 2000


/*
============================================================
Timing Helper
============================================================
*/

static double elapsed_seconds(
    clock_t start,
    clock_t end
)
{
    return
        (double)(end - start)
        / (double)CLOCKS_PER_SEC;
}


/*
============================================================
Initialise Matrix

The matrix is stored in contiguous memory.

C uses row-major layout.

Therefore:

matrix[row][column]

is stored so that neighbouring columns are adjacent
in memory.

============================================================
*/

static int *create_matrix(
    size_t size
)
{
    size_t total_elements =
        size * size;


    int *matrix =
        malloc(
            total_elements *
            sizeof(int)
        );


    if (matrix == NULL)
    {
        return NULL;
    }


    for (
        size_t i = 0;
        i < total_elements;
        i++
    )
    {
        matrix[i] =
            (int)(i % 100);
    }


    return matrix;
}


/*
============================================================
Row-Major Traversal

Memory access:

matrix[0][0]
matrix[0][1]
matrix[0][2]
...

Then the next row.

Adjacent elements are accessed consecutively.

This demonstrates good spatial locality.

============================================================
*/

static long long row_major_sum(
    const int *matrix,
    size_t size
)
{
    long long sum = 0;


    for (
        size_t row = 0;
        row < size;
        row++
    )
    {
        for (
            size_t column = 0;
            column < size;
            column++
        )
        {
            sum +=
                matrix[
                    row * size + column
                ];
        }
    }


    return sum;
}


/*
============================================================
Column-Major Traversal

Memory access:

matrix[0][0]
matrix[1][0]
matrix[2][0]
...

Elements are separated by an entire row.

This generally provides poorer spatial locality.

============================================================
*/

static long long column_major_sum(
    const int *matrix,
    size_t size
)
{
    long long sum = 0;


    for (
        size_t column = 0;
        column < size;
        column++
    )
    {
        for (
            size_t row = 0;
            row < size;
            row++
        )
        {
            sum +=
                matrix[
                    row * size + column
                ];
        }
    }


    return sum;
}


/*
============================================================
Main Benchmark
============================================================
*/

int main(void)
{
    printf("\n");

    printf(
        "========================================\n"
    );

    printf(
        " Cache Locality Benchmark\n"
    );

    printf(
        "========================================\n\n"
    );


    printf(
        "Matrix size: %zu x %zu\n",
        (size_t)MATRIX_SIZE,
        (size_t)MATRIX_SIZE
    );


    printf(
        "Total elements: %zu\n\n",
        (size_t)MATRIX_SIZE *
        (size_t)MATRIX_SIZE
    );


    /*
    --------------------------------------------------------
    Allocate matrix
    --------------------------------------------------------
    */

    int *matrix =
        create_matrix(
            MATRIX_SIZE
        );


    if (matrix == NULL)
    {
        fprintf(
            stderr,
            "Failed to allocate matrix.\n"
        );

        return EXIT_FAILURE;
    }


    /*
    --------------------------------------------------------
    Row-major benchmark
    --------------------------------------------------------
    */

    clock_t row_start =
        clock();


    long long row_sum =
        row_major_sum(
            matrix,
            MATRIX_SIZE
        );


    clock_t row_end =
        clock();


    double row_time =
        elapsed_seconds(
            row_start,
            row_end
        );


    /*
    --------------------------------------------------------
    Column-major benchmark
    --------------------------------------------------------
    */

    clock_t column_start =
        clock();


    long long column_sum =
        column_major_sum(
            matrix,
            MATRIX_SIZE
        );


    clock_t column_end =
        clock();


    double column_time =
        elapsed_seconds(
            column_start,
            column_end
        );


    /*
    --------------------------------------------------------
    Results
    --------------------------------------------------------
    */

    printf(
        "Row-major sum: %lld\n",
        row_sum
    );


    printf(
        "Row-major time: %.6f seconds\n\n",
        row_time
    );


    printf(
        "Column-major sum: %lld\n",
        column_sum
    );


    printf(
        "Column-major time: %.6f seconds\n\n",
        column_time
    );


    /*
    --------------------------------------------------------
    Correctness check
    --------------------------------------------------------
    */

    if (row_sum == column_sum)
    {
        printf(
            "Both traversals produced the same result.\n"
        );
    }
    else
    {
        printf(
            "ERROR: traversal results differ.\n"
        );

        free(matrix);

        return EXIT_FAILURE;
    }


    printf(
        "\nCache locality experiment complete.\n"
    );


    free(matrix);


    return EXIT_SUCCESS;
}