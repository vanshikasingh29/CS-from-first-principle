#ifndef GREEDY_ALGORITHMS_H
#define GREEDY_ALGORITHMS_H

/*
 * Activity Selection
 *
 * Selects the maximum number of non-overlapping activities.
 *
 * start[]  - activity start times
 * finish[] - activity finish times
 * n        - number of activities
 *
 * Returns the maximum number of compatible activities.
 */
int activity_selection(
    const int start[],
    const int finish[],
    int n
);


/*
 * Fractional Knapsack
 *
 * Unlike 0/1 knapsack, fractions of items may be selected.
 *
 * weights[]  - item weights
 * values[]   - item values
 * n          - number of items
 * capacity   - maximum capacity
 *
 * Returns the maximum achievable value.
 */
double fractional_knapsack(
    const int weights[],
    const int values[],
    int n,
    int capacity
);


/*
 * Kruskal's Minimum Spanning Tree
 *
 * edges represent an undirected weighted graph.
 *
 * edges[][0] = source
 * edges[][1] = destination
 * edges[][2] = weight
 *
 * vertices - number of vertices
 * edge_count - number of edges
 *
 * Returns total MST weight.
 */
int kruskal_mst(
    int edges[][3],
    int edge_count,
    int vertices
);

#endif