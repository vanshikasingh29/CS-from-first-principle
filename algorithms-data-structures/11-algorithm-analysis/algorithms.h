
/*
============================================================

CS From First Principles

Phase 3 — Algorithms & Data Structures

Topic 11 — Algorithm Analysis & Complexity

File:
algorithms.h

Purpose:
Public interface for algorithm implementations.

============================================================
*/

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <stddef.h>


/*
============================================================
Linear Search

Searches an array sequentially.

Returns:
Index of target if found.
-1 otherwise.

Complexity:
Best case  O(1)
Worst case O(n)
============================================================
*/

int linear_search(
    const int *array,
    size_t size,
    int target
);


/*
============================================================
Binary Search

Searches a sorted array by repeatedly halving
the search interval.

Returns:
Index of target if found.
-1 otherwise.

Complexity:
O(log n)

Precondition:
Array must be sorted in ascending order.
============================================================
*/

int binary_search(
    const int *array,
    size_t size,
    int target
);


/*
============================================================
Nested Loop

Performs a simple O(n²) computation.

Used to demonstrate quadratic growth.
============================================================
*/

long long quadratic_work(
    size_t n
);


/*
============================================================
Recursive Sum

Calculates the sum of an integer array recursively.

Complexity:
Time:  O(n)
Space: O(n) call stack
============================================================
*/

long long recursive_sum(
    const int *array,
    size_t size
);

#endif