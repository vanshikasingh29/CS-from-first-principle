#include "dynamic_programming.h"

#include <stdlib.h>
#include <string.h>


/*
 * ============================================================
 * Fibonacci — Memoisation
 * ============================================================
 *
 * Top-down dynamic programming.
 *
 * Instead of recalculating the same subproblems,
 * previously calculated results are stored.
 *
 * Time:  O(n)
 * Space: O(n)
 * ============================================================
 */

static long long fibonacci_memo_helper(
    int n,
    long long memo[]
)
{
    if (n <= 1)
    {
        return n;
    }

    if (memo[n] != -1)
    {
        return memo[n];
    }

    memo[n] =
        fibonacci_memo_helper(n - 1, memo) +
        fibonacci_memo_helper(n - 2, memo);

    return memo[n];
}


long long fibonacci_memoised(int n)
{
    if (n < 0)
    {
        return -1;
    }

    long long *memo =
        malloc(
            (size_t)(n + 1) *
            sizeof(long long)
        );

    if (memo == NULL)
    {
        return -1;
    }

    for (int i = 0; i <= n; i++)
    {
        memo[i] = -1;
    }

    long long result =
        fibonacci_memo_helper(n, memo);

    free(memo);

    return result;
}


/*
 * ============================================================
 * Fibonacci — Tabulation
 * ============================================================
 *
 * Bottom-up dynamic programming.
 *
 * We solve the smallest subproblems first and build
 * the final solution from them.
 *
 * Time:  O(n)
 * Space: O(n)
 * ============================================================
 */

long long fibonacci_tabulated(int n)
{
    if (n < 0)
    {
        return -1;
    }

    if (n <= 1)
    {
        return n;
    }

    long long *table =
        malloc(
            (size_t)(n + 1) *
            sizeof(long long)
        );

    if (table == NULL)
    {
        return -1;
    }

    table[0] = 0;
    table[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        table[i] =
            table[i - 1] +
            table[i - 2];
    }

    long long result = table[n];

    free(table);

    return result;
}


/*
 * ============================================================
 * 0/1 Knapsack
 * ============================================================
 *
 * Each item can either be:
 *
 *     0 = not selected
 *     1 = selected
 *
 * State:
 *
 * dp[i][w] =
 * maximum value obtainable using the first i items
 * with capacity w.
 *
 * Recurrence:
 *
 * dp[i][w] = dp[i-1][w]
 *
 * or
 *
 * value[i-1] + dp[i-1][w-weight[i-1]]
 *
 * Time:  O(n * capacity)
 * Space: O(n * capacity)
 * ============================================================
 */

int knapsack_01(
    const int weights[],
    const int values[],
    int n,
    int capacity
)
{
    if (
        weights == NULL ||
        values == NULL ||
        n <= 0 ||
        capacity < 0
    )
    {
        return 0;
    }

    int *dp =
        calloc(
            (size_t)(n + 1) *
            (size_t)(capacity + 1),
            sizeof(int)
        );

    if (dp == NULL)
    {
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            int without_item =
                dp[(i - 1) * (capacity + 1) + w];

            int best =
                without_item;

            if (weights[i - 1] <= w)
            {
                int with_item =
                    values[i - 1] +
                    dp[
                        (i - 1) * (capacity + 1)
                        + w - weights[i - 1]
                    ];

                if (with_item > best)
                {
                    best = with_item;
                }
            }

            dp[
                i * (capacity + 1) + w
            ] = best;
        }
    }

    int result =
        dp[n * (capacity + 1) + capacity];

    free(dp);

    return result;
}


/*
 * ============================================================
 * Longest Common Subsequence
 * ============================================================
 *
 * Example:
 *
 * A = "ABCBDAB"
 * B = "BDCABA"
 *
 * LCS length = 4
 *
 * State:
 *
 * dp[i][j] =
 * LCS length of the first i characters of A
 * and first j characters of B.
 *
 * If characters match:
 *
 *     dp[i][j] = dp[i-1][j-1] + 1
 *
 * Otherwise:
 *
 *     dp[i][j] =
 *         max(dp[i-1][j], dp[i][j-1])
 *
 * Time:  O(m * n)
 * Space: O(m * n)
 * ============================================================
 */

int longest_common_subsequence(
    const char *a,
    const char *b
)
{
    if (a == NULL || b == NULL)
    {
        return 0;
    }

    int m = (int)strlen(a);
    int n = (int)strlen(b);

    int *dp =
        calloc(
            (size_t)(m + 1) *
            (size_t)(n + 1),
            sizeof(int)
        );

    if (dp == NULL)
    {
        return 0;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[
                    i * (n + 1) + j
                ] =
                    dp[
                        (i - 1) * (n + 1)
                        + j - 1
                    ] + 1;
            }
            else
            {
                int top =
                    dp[
                        (i - 1) * (n + 1) + j
                    ];

                int left =
                    dp[
                        i * (n + 1) + j - 1
                    ];

                dp[
                    i * (n + 1) + j
                ] =
                    top > left ? top : left;
            }
        }
    }

    int result =
        dp[
            m * (n + 1) + n
        ];

    free(dp);

    return result;
}