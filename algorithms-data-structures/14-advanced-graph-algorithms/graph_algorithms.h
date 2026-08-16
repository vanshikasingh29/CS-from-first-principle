#ifndef GRAPH_ALGORITHMS_H
#define GRAPH_ALGORITHMS_H

#define INF 1000000000

/*
 * Dijkstra's shortest-path algorithm.
 *
 * graph[u][v] represents the edge weight from u to v.
 * INF represents no direct edge.
 *
 * Returns 0 on success.
 * Returns -1 for invalid input.
 */
int dijkstra(
    int graph[][10],
    int vertices,
    int source,
    int distances[]
);


/*
 * Bellman-Ford shortest-path algorithm.
 *
 * edges[i][0] = source
 * edges[i][1] = destination
 * edges[i][2] = weight
 *
 * Returns:
 *   0  = success
 *  -1  = negative cycle detected
 *  -2  = invalid input
 */
int bellman_ford(
    int edges[][3],
    int edge_count,
    int vertices,
    int source,
    int distances[]
);


/*
 * Floyd-Warshall all-pairs shortest paths.
 *
 * graph is modified in place.
 */
int floyd_warshall(
    int graph[][10],
    int vertices
);

#endif