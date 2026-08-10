#include <stdio.h>
#include <stdlib.h>
#include "graph.h"


Graph create_graph(int vertex_count)
{
    Graph graph = {0};

    if(vertex_count < 0 ||
       vertex_count > MAX_VERTICES)
    {
        return graph;
    }

    graph.vertex_count = vertex_count;

    return graph;
}


void add_edge(
    Graph* graph,
    int source,
    int destination
)
{
    if(graph == NULL)
    {
        return;
    }

    if(source < 0 ||
       destination < 0 ||
       source >= graph->vertex_count ||
       destination >= graph->vertex_count)
    {
        return;
    }

    graph->adjacency[source][destination] = 1;

    /*
     * Undirected graph:
     *
     * u -- v
     *
     * therefore both directions are stored.
     */

    graph->adjacency[destination][source] = 1;
}


int has_edge(
    const Graph* graph,
    int source,
    int destination
)
{
    if(graph == NULL)
    {
        return 0;
    }

    if(source < 0 ||
       destination < 0 ||
       source >= graph->vertex_count ||
       destination >= graph->vertex_count)
    {
        return 0;
    }

    return graph->adjacency[source][destination];
}


void bfs(
    const Graph* graph,
    int start
)
{
    if(graph == NULL)
    {
        return;
    }

    if(start < 0 ||
       start >= graph->vertex_count)
    {
        return;
    }

    int visited[MAX_VERTICES] = {0};
    int queue[MAX_VERTICES];

    int front = 0;
    int rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    printf("BFS: ");

    while(front < rear)
    {
        int current = queue[front++];

        printf("%d ", current);

        for(int neighbour = 0;
            neighbour < graph->vertex_count;
            neighbour++)
        {
            if(
                graph->adjacency[current][neighbour] &&
                !visited[neighbour]
            )
            {
                visited[neighbour] = 1;

                queue[rear++] = neighbour;
            }
        }
    }

    printf("\n");
}


static void dfs_recursive(
    const Graph* graph,
    int current,
    int* visited
)
{
    visited[current] = 1;

    printf("%d ", current);

    for(int neighbour = 0;
        neighbour < graph->vertex_count;
        neighbour++)
    {
        if(
            graph->adjacency[current][neighbour] &&
            !visited[neighbour]
        )
        {
            dfs_recursive(
                graph,
                neighbour,
                visited
            );
        }
    }
}


void dfs(
    const Graph* graph,
    int start
)
{
    if(graph == NULL)
    {
        return;
    }

    if(start < 0 ||
       start >= graph->vertex_count)
    {
        return;
    }

    int visited[MAX_VERTICES] = {0};

    printf("DFS: ");

    dfs_recursive(
        graph,
        start,
        visited
    );

    printf("\n");
}


int shortest_path(
    const Graph* graph,
    int source,
    int destination
)
{
    if(graph == NULL)
    {
        return -1;
    }

    if(source < 0 ||
       destination < 0 ||
       source >= graph->vertex_count ||
       destination >= graph->vertex_count)
    {
        return -1;
    }

    int distance[MAX_VERTICES];
    int queue[MAX_VERTICES];

    for(int i = 0;
        i < graph->vertex_count;
        i++)
    {
        distance[i] = -1;
    }

    int front = 0;
    int rear = 0;

    distance[source] = 0;
    queue[rear++] = source;

    while(front < rear)
    {
        int current = queue[front++];

        if(current == destination)
        {
            return distance[current];
        }

        for(int neighbour = 0;
            neighbour < graph->vertex_count;
            neighbour++)
        {
            if(
                graph->adjacency[current][neighbour] &&
                distance[neighbour] == -1
            )
            {
                distance[neighbour] =
                    distance[current] + 1;

                queue[rear++] = neighbour;
            }
        }
    }

    return -1;
}