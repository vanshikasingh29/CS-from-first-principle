#include <stdio.h>

#include "dynamic_programming.h"


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Dynamic Programming Demonstration\n");
    printf("========================================\n");


    /*
     * --------------------------------------------------------
     * Fibonacci — Memoisation
     * --------------------------------------------------------
     */

    printf("\n1. Fibonacci — Memoisation\n");

    printf(
        "F(10) = %lld\n",
        fibonacci_memoised(10)
    );


    /*
     * --------------------------------------------------------
     * Fibonacci — Tabulation
     * --------------------------------------------------------
     */

    printf("\n2. Fibonacci — Tabulation\n");

    printf(
        "F(10) = %lld\n",
        fibonacci_tabulated(10)
    );


    /*
     * --------------------------------------------------------
     * 0/1 Knapsack
     * --------------------------------------------------------
     */

    printf("\n3. 0/1 Knapsack\n");

    int weights[] =
    {
        2,
        3,
        4,
        5
    };

    int values[] =
    {
        3,
        4,
        5,
        6
    };

    int capacity = 5;

    printf(
        "Maximum value = %d\n",
        knapsack_01(
            weights,
            values,
            4,
            capacity
        )
    );


    /*
     * --------------------------------------------------------
     * Longest Common Subsequence
     * --------------------------------------------------------
     */

    printf("\n4. Longest Common Subsequence\n");

    printf(
        "LCS(\"ABCBDAB\", \"BDCABA\") = %d\n",
        longest_common_subsequence(
            "ABCBDAB",
            "BDCABA"
        )
    );


    printf(
        "\nDynamic programming demonstration complete.\n"
    );

    return 0;
}