#include <stdio.h>

#include "graph_algorithms.h"


static void print_distances(
    const int distances[],
    int vertices
)
{
    for (int i = 0; i < vertices; i++)
    {
        if (distances[i] == INF)
        {
            printf("Vertex %d: INF\n", i);
        }
        else
        {
            printf(
                "Vertex %d: %d\n",
                i,
                distances[i]
            );
        }
    }
}


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Advanced Graph Algorithms\n");
    printf("========================================\n");


    /*
     * --------------------------------------------------------
     * Dijkstra
     * --------------------------------------------------------
     */

    printf("\n1. Dijkstra\n");


    int graph[10][10] =
    {
        {0,   4,   1,   INF, INF},
        {4,   0,   2,   5,   INF},
        {1,   2,   0,   8,   10},
        {INF, 5,   8,   0,   2},
        {INF, INF, 10, 2,   0}
    };


    int distances[10];


    dijkstra(
        graph,
        5,
        0,
        distances
    );


    print_distances(
        distances,
        5
    );


    /*
     * --------------------------------------------------------
     * Bellman-Ford
     * --------------------------------------------------------
     */

    printf("\n2. Bellman-Ford\n");


    int edges[][3] =
    {
        {0, 1, 4},
        {0, 2, 5},
        {1, 2, -2},
        {1, 3, 6},
        {2, 3, 3}
    };


    bellman_ford(
        edges,
        5,
        4,
        0,
        distances
    );


    print_distances(
        distances,
        4
    );


    /*
     * --------------------------------------------------------
     * Floyd-Warshall
     * --------------------------------------------------------
     */

    printf("\n3. Floyd-Warshall\n");


    int all_pairs[10][10] =
    {
        {0,   3,   INF, 7},
        {8,   0,   2,   INF},
        {5,   INF, 0,   1},
        {2,   INF, INF, 0}
    };


    floyd_warshall(
        all_pairs,
        4
    );


    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (all_pairs[i][j] == INF)
            {
                printf("INF ");
            }
            else
            {
                printf(
                    "%3d ",
                    all_pairs[i][j]
                );
            }
        }

        printf("\n");
    }


    printf(
        "\nAdvanced graph algorithms demonstration complete.\n"
    );


    return 0;
}