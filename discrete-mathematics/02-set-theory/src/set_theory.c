#include "../include/set_theory.h"


IntSet create_set(void)
{
    IntSet set;

    set.size = 0;

    return set;
}


int contains(
    const IntSet* set,
    int value
)
{
    if (set == NULL)
    {
        return 0;
    }

    for (size_t i = 0; i < set->size; i++)
    {
        if (set->elements[i] == value)
        {
            return 1;
        }
    }

    return 0;
}


int add_element(
    IntSet* set,
    int value
)
{
    if (set == NULL)
    {
        return 0;
    }

    if (set->size >= MAX_SET_SIZE)
    {
        return 0;
    }

    if (contains(set, value))
    {
        return 0;
    }

    set->elements[set->size] = value;
    set->size++;

    return 1;
}


int is_subset(
    const IntSet* a,
    const IntSet* b
)
{
    if (a == NULL || b == NULL)
    {
        return 0;
    }

    for (size_t i = 0; i < a->size; i++)
    {
        if (!contains(b, a->elements[i]))
        {
            return 0;
        }
    }

    return 1;
}


IntSet set_union(
    const IntSet* a,
    const IntSet* b
)
{
    IntSet result = create_set();

    if (a == NULL || b == NULL)
    {
        return result;
    }

    for (size_t i = 0; i < a->size; i++)
    {
        add_element(
            &result,
            a->elements[i]
        );
    }

    for (size_t i = 0; i < b->size; i++)
    {
        add_element(
            &result,
            b->elements[i]
        );
    }

    return result;
}


IntSet set_intersection(
    const IntSet* a,
    const IntSet* b
)
{
    IntSet result = create_set();

    if (a == NULL || b == NULL)
    {
        return result;
    }

    for (size_t i = 0; i < a->size; i++)
    {
        if (contains(b, a->elements[i]))
        {
            add_element(
                &result,
                a->elements[i]
            );
        }
    }

    return result;
}


IntSet set_difference(
    const IntSet* a,
    const IntSet* b
)
{
    IntSet result = create_set();

    if (a == NULL || b == NULL)
    {
        return result;
    }

    for (size_t i = 0; i < a->size; i++)
    {
        if (!contains(b, a->elements[i]))
        {
            add_element(
                &result,
                a->elements[i]
            );
        }
    }

    return result;
}


CartesianProduct cartesian_product(
    const IntSet* a,
    const IntSet* b
)
{
    CartesianProduct result;

    result.size = 0;

    if (a == NULL || b == NULL)
    {
        return result;
    }

    for (size_t i = 0; i < a->size; i++)
    {
        for (size_t j = 0; j < b->size; j++)
        {
            result.pairs[result.size].first =
                a->elements[i];

            result.pairs[result.size].second =
                b->elements[j];

            result.size++;
        }
    }

    return result;
}


size_t power_set_size(
    const IntSet* set
)
{
    if (set == NULL)
    {
        return 0;
    }

    size_t result = 1;

    for (size_t i = 0; i < set->size; i++)
    {
        result *= 2;
    }

    return result;
}