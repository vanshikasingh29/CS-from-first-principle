#ifndef DYNAMIC_PROGRAMMING_H
#define DYNAMIC_PROGRAMMING_H

/*
 * Fibonacci using top-down dynamic programming.
 * Results are stored in a memoisation table.
 */
long long fibonacci_memoised(int n);

/*
 * Fibonacci using bottom-up tabulation.
 */
long long fibonacci_tabulated(int n);

/*
 * 0/1 Knapsack.
 *
 * weights  - item weights
 * values   - item values
 * n        - number of items
 * capacity - maximum allowed weight
 *
 * Returns the maximum achievable value.
 */
int knapsack_01(
    const int weights[],
    const int values[],
    int n,
    int capacity
);

/*
 * Longest Common Subsequence length.
 *
 * Returns the length of the longest subsequence
 * common to both strings.
 */
int longest_common_subsequence(
    const char *a,
    const char *b
);

#endif