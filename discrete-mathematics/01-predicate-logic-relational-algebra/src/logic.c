#include "../include/logic.h"


/*
============================================================
PROPOSITIONAL LOGIC
============================================================
*/


int logical_not(int p)
{
    return !p;
}


int logical_and(int p, int q)
{
    return p && q;
}


int logical_or(int p, int q)
{
    return p || q;
}


int logical_implies(int p, int q)
{
    /*
        p → q

        ≡ ¬p ∨ q
    */

    return (!p) || q;
}


int logical_equivalent(int p, int q)
{
    /*
        p ↔ q

        True exactly when both propositions
        have the same truth value.
    */

    return p == q;
}


/*
============================================================
PREDICATE LOGIC
============================================================
*/


int evaluate_predicate(
    Predicate predicate,
    const int domain[],
    size_t size
)
{
    if (predicate == NULL || domain == NULL)
    {
        return 0;
    }


    /*
        Universal quantification:

            ∀x ∈ D, P(x)

        The statement is false as soon as
        one counterexample is found.
    */

    for (size_t i = 0; i < size; i++)
    {
        if (!predicate(domain[i]))
        {
            return 0;
        }
    }


    return 1;
}


size_t count_satisfying(
    Predicate predicate,
    const int domain[],
    size_t size
)
{
    if (predicate == NULL || domain == NULL)
    {
        return 0;
    }


    size_t count = 0;


    for (size_t i = 0; i < size; i++)
    {
        if (predicate(domain[i]))
        {
            count++;
        }
    }


    return count;
}


/*
============================================================
RELATIONAL ALGEBRA
============================================================
*/


Relation create_relation(void)
{
    Relation relation;

    relation.size = 0;

    return relation;
}


void add_tuple(
    Relation* relation,
    int id,
    int value
)
{
    if (relation == NULL)
    {
        return;
    }


    /*
        Prevent writing beyond the fixed
        relation capacity.
    */

    if (relation->size >= 100)
    {
        return;
    }


    relation->tuples[relation->size].id = id;

    relation->tuples[relation->size].value = value;

    relation->size++;
}


/*
============================================================
SELECTION

σP(R)
============================================================
*/


Relation selection(
    const Relation* relation,
    Predicate predicate
)
{
    Relation result = create_relation();


    if (relation == NULL || predicate == NULL)
    {
        return result;
    }


    for (size_t i = 0; i < relation->size; i++)
    {
        Tuple tuple = relation->tuples[i];


        if (predicate(tuple.value))
        {
            add_tuple(
                &result,
                tuple.id,
                tuple.value
            );
        }
    }


    return result;
}


/*
============================================================
PROJECTION

πid(R)
============================================================
*/


Relation projection_id(
    const Relation* relation
)
{
    Relation result = create_relation();


    if (relation == NULL)
    {
        return result;
    }


    for (size_t i = 0; i < relation->size; i++)
    {
        add_tuple(
            &result,
            relation->tuples[i].id,
            0
        );
    }


    return result;
}