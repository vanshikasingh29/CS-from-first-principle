#include <stdio.h>
#include <stdlib.h>

#include "greedy_algorithms.h"


static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf(
            "[PASS] %s\n",
            name
        );

        tests_passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            name
        );

        tests_failed++;
    }
}


/*
 * ============================================================
 * Activity Selection Tests
 * ============================================================
 */

static void test_activity_selection(void)
{
    int start[] =
    {
        1,
        3,
        0,
        5,
        8,
        5
    };


    int finish[] =
    {
        2,
        4,
        6,
        7,
        9,
        9
    };


    assert_test(
        activity_selection(
            start,
            finish,
            6
        ) == 4,
        "Activity selection"
    );
}


/*
 * ============================================================
 * Fractional Knapsack Tests
 * ============================================================
 */

static void test_fractional_knapsack(void)
{
    int weights[] =
    {
        10,
        20,
        30
    };


    int values[] =
    {
        60,
        100,
        120
    };


    double result =
        fractional_knapsack(
            weights,
            values,
            3,
            50
        );


    assert_test(
        result > 239.99 &&
        result < 240.01,
        "Fractional knapsack"
    );
}


/*
 * ============================================================
 * Kruskal Tests
 * ============================================================
 */

static void test_kruskal(void)
{
    int edges[][3] =
    {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };


    int result =
        kruskal_mst(
            edges,
            5,
            4
        );


    assert_test(
        result == 19,
        "Kruskal minimum spanning tree"
    );
}


/*
 * ============================================================
 * Edge Case Tests
 * ============================================================
 */

static void test_empty_inputs(void)
{
    assert_test(
        activity_selection(
            NULL,
            NULL,
            0
        ) == 0,
        "Activity selection empty input"
    );


    assert_test(
        fractional_knapsack(
            NULL,
            NULL,
            0,
            10
        ) == 0.0,
        "Fractional knapsack empty input"
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
    printf(" Greedy Algorithms Test Suite\n");
    printf("========================================\n\n");


    test_activity_selection();

    test_fractional_knapsack();

    test_kruskal();

    test_empty_inputs();


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
            "\nAll greedy algorithm tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome greedy algorithm tests failed.\n"
    );


    return EXIT_FAILURE;
}