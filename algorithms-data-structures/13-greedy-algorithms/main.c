#include <stdio.h>

#include "greedy_algorithms.h"


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Greedy Algorithms Demonstration\n");
    printf("========================================\n");


    /*
     * --------------------------------------------------------
     * Activity Selection
     * --------------------------------------------------------
     */

    printf("\n1. Activity Selection\n");


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


    printf(
        "Maximum compatible activities: %d\n",
        activity_selection(
            start,
            finish,
            6
        )
    );


    /*
     * --------------------------------------------------------
     * Fractional Knapsack
     * --------------------------------------------------------
     */

    printf("\n2. Fractional Knapsack\n");


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


    printf(
        "Maximum value: %.2f\n",
        fractional_knapsack(
            weights,
            values,
            3,
            50
        )
    );


    /*
     * --------------------------------------------------------
     * Kruskal's MST
     * --------------------------------------------------------
     */

    printf("\n3. Kruskal Minimum Spanning Tree\n");


    int edges[][3] =
    {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };


    printf(
        "MST total weight: %d\n",
        kruskal_mst(
            edges,
            5,
            4
        )
    );


    printf(
        "\nGreedy algorithms demonstration complete.\n"
    );


    return 0;
}