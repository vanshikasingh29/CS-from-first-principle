#include <stdio.h>
#include <stdlib.h>

#include "graph_algorithms.h"


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
 * Dijkstra Test
 * ============================================================
 */

static void test_dijkstra(void)
{
    int graph[10][10] =
    {
        {0,   4,   1,   INF, INF},
        {4,   0,   2,   5,   INF},
        {1,   2,   0,   8,   10},
        {INF, 5,   8,   0,   2},
        {INF, INF, 10, 2,   0}
    };


    int distances[10];


    int result =
        dijkstra(
            graph,
            5,
            0,
            distances
        );


    assert_test(
        result == 0 &&
        distances[0] == 0 &&
        distances[1] == 3 &&
        distances[2] == 1 &&
        distances[3] == 8 &&
        distances[4] == 10,
        "Dijkstra shortest paths"
    );
}


/*
 * ============================================================
 * Bellman-Ford Test
 * ============================================================
 */

static void test_bellman_ford(void)
{
    int edges[][3] =
    {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -2},
        {1, 3, 6},
        {2, 3, 3}
    };


    int distances[10];


    int result =
        bellman_ford(
            edges,
            5,
            4,
            0,
            distances
        );


    assert_test(
        result == 0 &&
        distances[0] == 0 &&
        distances[1] == 4 &&
        distances[2] == 2 &&
        distances[3] == 5,
        "Bellman-Ford shortest paths"
    );
}


/*
 * ============================================================
 * Negative Cycle Test
 * ============================================================
 */

static void test_negative_cycle(void)
{
    int edges[][3] =
    {
        {0, 1, 1},
        {1, 2, -2},
        {2, 0, 0}
    };


    int distances[10];


    int result =
        bellman_ford(
            edges,
            3,
            3,
            0,
            distances
        );


    assert_test(
        result == -1,
        "Bellman-Ford negative cycle detection"
    );
}


/*
 * ============================================================
 * Floyd-Warshall Test
 * ============================================================
 */

static void test_floyd_warshall(void)
{
    int graph[10][10] =
    {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };


    int result =
        floyd_warshall(
            graph,
            4
        );


    assert_test(
        result == 0 &&
        graph[0][2] == 5 &&
        graph[0][3] == 6 &&
        graph[1][3] == 3,
        "Floyd-Warshall all-pairs shortest paths"
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
    printf(" Advanced Graph Algorithms Test Suite\n");
    printf("========================================\n\n");


    test_dijkstra();

    test_bellman_ford();

    test_negative_cycle();

    test_floyd_warshall();


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
            "\nAll graph algorithm tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome graph algorithm tests failed.\n"
    );


    return EXIT_FAILURE;
}