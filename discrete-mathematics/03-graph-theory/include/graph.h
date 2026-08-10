#ifndef GRAPH_H
#define GRAPH_H

#define MAX_VERTICES 100

typedef struct
{
    int adjacency[MAX_VERTICES][MAX_VERTICES];
    int vertex_count;

} Graph;


/* Graph construction */

Graph create_graph(int vertex_count);

void add_edge(
    Graph* graph,
    int source,
    int destination
);


/* Graph inspection */

int has_edge(
    const Graph* graph,
    int source,
    int destination
);


/* Traversal */

void bfs(
    const Graph* graph,
    int start
);

void dfs(
    const Graph* graph,
    int start
);


/* Shortest path in an unweighted graph */

int shortest_path(
    const Graph* graph,
    int source,
    int destination
);

#endif