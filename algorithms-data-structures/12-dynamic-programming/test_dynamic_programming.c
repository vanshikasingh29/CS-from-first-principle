#include <stdio.h>
#include <stdlib.h>

#include "dynamic_programming.h"


static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf("[PASS] %s\n", name);
        tests_passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        tests_failed++;
    }
}


/*
 * ============================================================
 * Fibonacci Tests
 * ============================================================
 */

static void test_fibonacci_memoised(void)
{
    assert_test(
        fibonacci_memoised(0) == 0,
        "Memoised Fibonacci F(0)"
    );

    assert_test(
        fibonacci_memoised(1) == 1,
        "Memoised Fibonacci F(1)"
    );

    assert_test(
        fibonacci_memoised(10) == 55,
        "Memoised Fibonacci F(10)"
    );
}


static void test_fibonacci_tabulated(void)
{
    assert_test(
        fibonacci_tabulated(0) == 0,
        "Tabulated Fibonacci F(0)"
    );

    assert_test(
        fibonacci_tabulated(1) == 1,
        "Tabulated Fibonacci F(1)"
    );

    assert_test(
        fibonacci_tabulated(10) == 55,
        "Tabulated Fibonacci F(10)"
    );
}


/*
 * ============================================================
 * Knapsack Tests
 * ============================================================
 */

static void test_knapsack(void)
{
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

    assert_test(
        knapsack_01(
            weights,
            values,
            4,
            5
        ) == 7,
        "0/1 Knapsack optimal value"
    );
}


/*
 * ============================================================
 * LCS Tests
 * ============================================================
 */

static void test_lcs(void)
{
    assert_test(
        longest_common_subsequence(
            "ABCBDAB",
            "BDCABA"
        ) == 4,
        "LCS standard example"
    );

    assert_test(
        longest_common_subsequence(
            "",
            "ABC"
        ) == 0,
        "LCS empty sequence"
    );

    assert_test(
        longest_common_subsequence(
            "ABC",
            "ABC"
        ) == 3,
        "LCS identical sequences"
    );
}


/*
 * ============================================================
 * Main
 * ============================================================
 */

int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Dynamic Programming Test Suite\n");
    printf("========================================\n\n");


    test_fibonacci_memoised();

    test_fibonacci_tabulated();

    test_knapsack();

    test_lcs();


    printf("\n");
    printf("Results\n");
    printf("--------------------\n");

    printf(
        "Passed: %d\n",
        tests_passed
    );

    printf(
        "Failed: %d\n",
        tests_failed
    );


    if (tests_failed == 0)
    {
        printf(
            "\nAll dynamic programming tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome dynamic programming tests failed.\n"
    );

    return EXIT_FAILURE;
}