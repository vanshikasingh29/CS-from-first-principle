#ifndef SET_THEORY_H
#define SET_THEORY_H

#include <stddef.h>

#define MAX_SET_SIZE 100


typedef struct
{
    int elements[MAX_SET_SIZE];
    size_t size;
} IntSet;


/*
============================================================
Set Construction
============================================================
*/

IntSet create_set(void);

int contains(
    const IntSet* set,
    int value
);

int add_element(
    IntSet* set,
    int value
);


/*
============================================================
Set Relationships
============================================================
*/

int is_subset(
    const IntSet* a,
    const IntSet* b
);


/*
============================================================
Set Operations
============================================================
*/

IntSet set_union(
    const IntSet* a,
    const IntSet* b
);

IntSet set_intersection(
    const IntSet* a,
    const IntSet* b
);

IntSet set_difference(
    const IntSet* a,
    const IntSet* b
);


/*
============================================================
Cartesian Product
============================================================
*/

typedef struct
{
    int first;
    int second;
} OrderedPair;


typedef struct
{
    OrderedPair pairs[MAX_SET_SIZE * MAX_SET_SIZE];
    size_t size;
} CartesianProduct;


CartesianProduct cartesian_product(
    const IntSet* a,
    const IntSet* b
);


/*
============================================================
Power Set
============================================================
*/

size_t power_set_size(
    const IntSet* set
);

#endif