#include <stdio.h>
#include "graph.h"


int tests_passed = 0;
int tests_failed = 0;


void assert_test(
    int condition,
    const char* name
)
{
    if(condition)
    {
        printf("[PASS] %s\n", name);
        tests_passed++;
    }
    else
    {
        printf("[FAIL] %s\n", name);
        tests_failed++;
    }
}


int main(void)
{
    Graph graph =
        create_graph(5);


    add_edge(&graph, 0, 1);
    add_edge(&graph, 1, 2);
    add_edge(&graph, 2, 3);
    add_edge(&graph, 3, 4);


    printf(
        "Graph Theory Test Suite\n"
    );

    printf(
        "========================\n\n"
    );


    assert_test(
        has_edge(&graph, 0, 1),
        "Edge membership"
    );


    assert_test(
        !has_edge(&graph, 0, 4),
        "Non-edge detection"
    );


    assert_test(
        has_edge(&graph, 1, 0),
        "Undirected symmetry"
    );


    assert_test(
        shortest_path(&graph, 0, 4) == 4,
        "Shortest path"
    );


    assert_test(
        shortest_path(&graph, 0, 2) == 2,
        "Intermediate shortest path"
    );


    printf(
        "\nPassed: %d\n",
        tests_passed
    );

    printf(
        "Failed: %d\n",
        tests_failed
    );


    return tests_failed == 0 ? 0 : 1;
}