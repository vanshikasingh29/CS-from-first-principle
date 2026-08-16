#include "graph_algorithms.h"


/*
 * ============================================================
 * Dijkstra's Algorithm
 * ============================================================
 *
 * Repeatedly selects the unvisited vertex with the smallest
 * known distance and relaxes its outgoing edges.
 *
 * Valid only when edge weights are non-negative.
 *
 * Time:  O(V²)
 * Space: O(V)
 * ============================================================
 */

int dijkstra(
    int graph[][10],
    int vertices,
    int source,
    int distances[]
)
{
    if (
        graph == NULL ||
        distances == NULL ||
        vertices <= 0 ||
        vertices > 10 ||
        source < 0 ||
        source >= vertices
    )
    {
        return -1;
    }


    int visited[10] = {0};


    for (int i = 0; i < vertices; i++)
    {
        distances[i] = INF;
    }


    distances[source] = 0;


    for (int count = 0; count < vertices; count++)
    {
        int current = -1;


        for (int i = 0; i < vertices; i++)
        {
            if (
                !visited[i] &&
                distances[i] != INF &&
                (current == -1 ||
                 distances[i] < distances[current])
            )
            {
                current = i;
            }
        }


        if (current == -1)
        {
            break;
        }


        visited[current] = 1;


        for (int neighbour = 0;
             neighbour < vertices;
             neighbour++)
        {
            int weight =
                graph[current][neighbour];


            if (
                weight != INF &&
                weight >= 0 &&
                distances[current] + weight <
                    distances[neighbour]
            )
            {
                distances[neighbour] =
                    distances[current] + weight;
            }
        }
    }


    return 0;
}


/*
 * ============================================================
 * Bellman-Ford
 * ============================================================
 *
 * Relaxes every edge V-1 times.
 *
 * Unlike Dijkstra, negative edge weights are permitted.
 *
 * A further relaxation after V-1 passes indicates a negative
 * cycle reachable from the source.
 *
 * Time:  O(VE)
 * Space: O(V)
 * ============================================================
 */

int bellman_ford(
    int edges[][3],
    int edge_count,
    int vertices,
    int source,
    int distances[]
)
{
    if (
        edges == NULL ||
        distances == NULL ||
        edge_count < 0 ||
        vertices <= 0 ||
        source < 0 ||
        source >= vertices
    )
    {
        return -2;
    }


    for (int i = 0; i < vertices; i++)
    {
        distances[i] = INF;
    }


    distances[source] = 0;


    for (int iteration = 0;
         iteration < vertices - 1;
         iteration++)
    {
        int changed = 0;


        for (int i = 0;
             i < edge_count;
             i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int weight = edges[i][2];


            if (
                u < 0 ||
                u >= vertices ||
                v < 0 ||
                v >= vertices
            )
            {
                return -2;
            }


            if (
                distances[u] != INF &&
                distances[u] + weight <
                    distances[v]
            )
            {
                distances[v] =
                    distances[u] + weight;

                changed = 1;
            }
        }


        /*
         * No changes means the shortest paths have already
         * converged.
         */
        if (!changed)
        {
            break;
        }
    }


    /*
     * Detect reachable negative cycles.
     */
    for (int i = 0;
         i < edge_count;
         i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weight = edges[i][2];


        if (
            distances[u] != INF &&
            distances[u] + weight <
                distances[v]
        )
        {
            return -1;
        }
    }


    return 0;
}


/*
 * ============================================================
 * Floyd-Warshall
 * ============================================================
 *
 * Dynamic programming algorithm for all-pairs shortest paths.
 *
 * The recurrence is:
 *
 * D_k(i,j) =
 * min(
 *     D_(k-1)(i,j),
 *     D_(k-1)(i,k) + D_(k-1)(k,j)
 * )
 *
 * Time:  O(V³)
 * Space: O(1) additional space
 * ============================================================
 */

int floyd_warshall(
    int graph[][10],
    int vertices
)
{
    if (
        graph == NULL ||
        vertices <= 0 ||
        vertices > 10
    )
    {
        return -1;
    }


    for (int k = 0; k < vertices; k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                if (
                    graph[i][k] != INF &&
                    graph[k][j] != INF
                )
                {
                    int through_k =
                        graph[i][k] +
                        graph[k][j];


                    if (
                        through_k <
                        graph[i][j]
                    )
                    {
                        graph[i][j] =
                            through_k;
                    }
                }
            }
        }
    }


    /*
     * Negative diagonal entry means a negative cycle exists.
     */
    for (int i = 0; i < vertices; i++)
    {
        if (graph[i][i] < 0)
        {
            return -1;
        }
    }


    return 0;
}