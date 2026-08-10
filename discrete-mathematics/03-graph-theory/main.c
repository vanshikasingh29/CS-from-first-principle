#include <stdio.h>
#include "graph.h"


int main(void)
{
    Graph graph =
        create_graph(6);


    /*
     * Graph:
     *
     * 0 --- 1 --- 2
     * |     |
     * 3 --- 4 --- 5
     */

    add_edge(&graph, 0, 1);
    add_edge(&graph, 0, 3);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 1, 4);
    add_edge(&graph, 3, 4);
    add_edge(&graph, 4, 5);


    printf("Graph Theory Lab\n");
    printf("================\n\n");


    printf(
        "Edge 0 -> 1: %s\n",
        has_edge(&graph, 0, 1)
            ? "true"
            : "false"
    );


    printf(
        "Edge 2 -> 5: %s\n",
        has_edge(&graph, 2, 5)
            ? "true"
            : "false"
    );


    bfs(&graph, 0);

    dfs(&graph, 0);


    printf(
        "Shortest path 0 -> 5: %d edges\n",
        shortest_path(&graph, 0, 5)
    );


    return 0;
}