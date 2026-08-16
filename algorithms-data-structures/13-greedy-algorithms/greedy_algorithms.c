#include "greedy_algorithms.h"

#include <stdlib.h>


/*
 * ============================================================
 * Activity Selection
 * ============================================================
 *
 * Greedy strategy:
 *
 * Always choose the activity that finishes earliest.
 *
 * Why?
 *
 * Choosing the earliest finishing compatible activity leaves
 * the largest possible remaining time for future activities.
 *
 * Time: O(n log n)
 * Space: O(n)
 * ============================================================
 */

typedef struct
{
    int start;
    int finish;

} Activity;


static int compare_activity(
    const void *a,
    const void *b
)
{
    const Activity *x = a;
    const Activity *y = b;

    return x->finish - y->finish;
}


int activity_selection(
    const int start[],
    const int finish[],
    int n
)
{
    if (
        start == NULL ||
        finish == NULL ||
        n <= 0
    )
    {
        return 0;
    }


    Activity *activities =
        malloc(
            (size_t)n *
            sizeof(Activity)
        );


    if (activities == NULL)
    {
        return 0;
    }


    for (int i = 0; i < n; i++)
    {
        activities[i].start = start[i];
        activities[i].finish = finish[i];
    }


    qsort(
        activities,
        (size_t)n,
        sizeof(Activity),
        compare_activity
    );


    int selected = 1;

    int last_finish =
        activities[0].finish;


    for (int i = 1; i < n; i++)
    {
        if (
            activities[i].start >= last_finish
        )
        {
            selected++;

            last_finish =
                activities[i].finish;
        }
    }


    free(activities);

    return selected;
}


/*
 * ============================================================
 * Fractional Knapsack
 * ============================================================
 *
 * Greedy strategy:
 *
 * Select the item with the highest value/weight ratio first.
 *
 * Fractions are allowed, so taking part of an item is valid.
 *
 * Time: O(n log n)
 * Space: O(n)
 * ============================================================
 */

typedef struct
{
    int weight;
    int value;
    double ratio;

} Item;


static int compare_item(
    const void *a,
    const void *b
)
{
    const Item *x = a;
    const Item *y = b;


    if (x->ratio < y->ratio)
    {
        return 1;
    }

    if (x->ratio > y->ratio)
    {
        return -1;
    }

    return 0;
}


double fractional_knapsack(
    const int weights[],
    const int values[],
    int n,
    int capacity
)
{
    if (
        weights == NULL ||
        values == NULL ||
        n <= 0 ||
        capacity <= 0
    )
    {
        return 0.0;
    }


    Item *items =
        malloc(
            (size_t)n *
            sizeof(Item)
        );


    if (items == NULL)
    {
        return 0.0;
    }


    for (int i = 0; i < n; i++)
    {
        items[i].weight =
            weights[i];

        items[i].value =
            values[i];

        if (weights[i] > 0)
        {
            items[i].ratio =
                (double)values[i] /
                weights[i];
        }
        else
        {
            items[i].ratio = 0.0;
        }
    }


    qsort(
        items,
        (size_t)n,
        sizeof(Item),
        compare_item
    );


    double total_value = 0.0;

    int remaining =
        capacity;


    for (int i = 0; i < n; i++)
    {
        if (remaining <= 0)
        {
            break;
        }


        if (items[i].weight <= remaining)
        {
            total_value +=
                items[i].value;

            remaining -=
                items[i].weight;
        }
        else
        {
            double fraction =
                (double)remaining /
                items[i].weight;

            total_value +=
                items[i].value *
                fraction;

            remaining = 0;
        }
    }


    free(items);

    return total_value;
}


/*
 * ============================================================
 * Kruskal's Minimum Spanning Tree
 * ============================================================
 *
 * Greedy strategy:
 *
 * Repeatedly select the cheapest edge that does not create
 * a cycle.
 *
 * A Disjoint Set Union structure tracks connected components.
 *
 * Time: O(E log E)
 * Space: O(V)
 * ============================================================
 */

typedef struct
{
    int parent;
    int rank;

} DisjointSet;


static int find_set(
    DisjointSet sets[],
    int vertex
)
{
    if (sets[vertex].parent != vertex)
    {
        sets[vertex].parent =
            find_set(
                sets,
                sets[vertex].parent
            );
    }

    return sets[vertex].parent;
}


static void union_sets(
    DisjointSet sets[],
    int a,
    int b
)
{
    int root_a =
        find_set(sets, a);

    int root_b =
        find_set(sets, b);


    if (root_a == root_b)
    {
        return;
    }


    if (
        sets[root_a].rank <
        sets[root_b].rank
    )
    {
        sets[root_a].parent =
            root_b;
    }
    else if (
        sets[root_a].rank >
        sets[root_b].rank
    )
    {
        sets[root_b].parent =
            root_a;
    }
    else
    {
        sets[root_b].parent =
            root_a;

        sets[root_a].rank++;
    }
}


static int compare_edges(
    const void *a,
    const void *b
)
{
    const int *edge_a = a;
    const int *edge_b = b;

    return edge_a[2] - edge_b[2];
}


int kruskal_mst(
    int edges[][3],
    int edge_count,
    int vertices
)
{
    if (
        edges == NULL ||
        edge_count <= 0 ||
        vertices <= 0
    )
    {
        return 0;
    }


    qsort(
        edges,
        (size_t)edge_count,
        sizeof(edges[0]),
        compare_edges
    );


    DisjointSet *sets =
        malloc(
            (size_t)vertices *
            sizeof(DisjointSet)
        );


    if (sets == NULL)
    {
        return 0;
    }


    for (int i = 0; i < vertices; i++)
    {
        sets[i].parent = i;
        sets[i].rank = 0;
    }


    int total_weight = 0;
    int selected_edges = 0;


    for (int i = 0; i < edge_count; i++)
    {
        int source = edges[i][0];
        int destination = edges[i][1];
        int weight = edges[i][2];


        if (
            find_set(sets, source) !=
            find_set(sets, destination)
        )
        {
            union_sets(
                sets,
                source,
                destination
            );

            total_weight += weight;

            selected_edges++;


            if (selected_edges == vertices - 1)
            {
                break;
            }
        }
    }


    free(sets);

    return total_weight;
}