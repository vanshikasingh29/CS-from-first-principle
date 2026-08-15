/*
============================================================

CS From First Principles

Phase 3 — Algorithms & Data Structures

Topic 11 — Algorithm Analysis & Complexity

File:
algorithms.c

Purpose:
Implementations used to study algorithm complexity.

============================================================
*/

#include "algorithms.h"


/*
============================================================
Linear Search
============================================================
*/

int linear_search(
    const int *array,
    size_t size,
    int target
)
{
    for (size_t i = 0; i < size; i++)
    {
        if (array[i] == target)
        {
            return (int)i;
        }
    }

    return -1;
}


/*
============================================================
Binary Search

The search interval is repeatedly divided in half.

This is the practical reason for logarithmic complexity.
============================================================
*/

int binary_search(
    const int *array,
    size_t size,
    int target
)
{
    size_t left = 0;

    size_t right = size;


    while (left < right)
    {
        size_t middle =
            left + (right - left) / 2;


        if (array[middle] == target)
        {
            return (int)middle;
        }


        if (array[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle;
        }
    }


    return -1;
}


/*
============================================================
Quadratic Work

Two nested loops execute approximately n² iterations.

Complexity:
O(n²)
============================================================
*/

long long quadratic_work(
    size_t n
)
{
    long long operations = 0;


    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            operations++;
        }
    }


    return operations;
}


/*
============================================================
Recursive Sum

Recurrence:

T(n) = T(n - 1) + O(1)

Therefore:

T(n) = O(n)

The recursion depth is also O(n).
============================================================
*/

long long recursive_sum(
    const int *array,
    size_t size
)
{
    if (size == 0)
    {
        return 0;
    }


    return array[size - 1]
           + recursive_sum(
                array,
                size - 1
             );
}