/*
============================================================

CS From First Principles

Phase 3 — Algorithms & Data Structures

Topic 11 — Algorithm Analysis & Complexity

File:
main.c

Purpose:
Demonstrates algorithms with different asymptotic
complexities.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "algorithms.h"


/*
============================================================
Timing helper
============================================================
*/

static double elapsed_seconds(
    clock_t start,
    clock_t end
)
{
    return
        (double)(end - start)
        / CLOCKS_PER_SEC;
}


/*
============================================================
Main demonstration
============================================================
*/

int main(void)
{
    printf("\n");
    printf("=============================================\n");
    printf(" Algorithm Analysis & Complexity Laboratory\n");
    printf("=============================================\n\n");


    /*
    ---------------------------------------------------------
    Search demonstration
    ---------------------------------------------------------
    */

    int data[] =
    {
        10,
        20,
        30,
        40,
        50,
        60,
        70,
        80,
        90,
        100
    };


    size_t size =
        sizeof(data) / sizeof(data[0]);


    int target = 70;


    printf("Search target: %d\n\n", target);


    int linear_result =
        linear_search(
            data,
            size,
            target
        );


    int binary_result =
        binary_search(
            data,
            size,
            target
        );


    printf(
        "Linear search result: %d\n",
        linear_result
    );


    printf(
        "Binary search result: %d\n\n",
        binary_result
    );


    /*
    ---------------------------------------------------------
    Recursive computation
    ---------------------------------------------------------
    */

    int values[] =
    {
        1,
        2,
        3,
        4,
        5
    };


    size_t value_count =
        sizeof(values) / sizeof(values[0]);


    long long sum =
        recursive_sum(
            values,
            value_count
        );


    printf(
        "Recursive sum: %lld\n\n",
        sum
    );


    /*
    ---------------------------------------------------------
    Quadratic work demonstration
    ---------------------------------------------------------
    */

    printf("Quadratic work:\n");


    size_t sizes[] =
    {
        10,
        100,
        500
    };


    size_t count =
        sizeof(sizes) / sizeof(sizes[0]);


    for (size_t i = 0; i < count; i++)
    {
        long long operations =
            quadratic_work(
                sizes[i]
            );


        printf(
            "n = %zu -> operations = %lld\n",
            sizes[i],
            operations
        );
    }


    /*
    ---------------------------------------------------------
    Basic empirical timing
    ---------------------------------------------------------
    */

    printf("\nEmpirical timing:\n");


    size_t benchmark_size =
        100000;


    int *benchmark =
        malloc(
            benchmark_size * sizeof(int)
        );


    if (benchmark == NULL)
    {
        fprintf(
            stderr,
            "Memory allocation failed.\n"
        );

        return EXIT_FAILURE;
    }


    for (size_t i = 0; i < benchmark_size; i++)
    {
        benchmark[i] = (int)i;
    }


    clock_t start =
        clock();


    volatile int result =
        linear_search(
            benchmark,
            benchmark_size,
            -1
        );


    clock_t end =
        clock();


    printf(
        "Linear search result: %d\n",
        result
    );


    printf(
        "Linear search time: %.6f seconds\n",
        elapsed_seconds(start, end)
    );


    free(benchmark);


    printf(
        "\nComplexity relationships:\n"
    );

    printf(
        "Linear Search  -> O(n)\n"
    );

    printf(
        "Binary Search  -> O(log n)\n"
    );

    printf(
        "Quadratic Work -> O(n^2)\n"
    );

    printf(
        "Recursive Sum  -> O(n)\n"
    );


    printf(
        "\nAlgorithm analysis laboratory complete.\n\n"
    );


    return EXIT_SUCCESS;
}