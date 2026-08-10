#ifndef LOGIC_H
#define LOGIC_H

#include <stddef.h>

/*
============================================================
Topic 1 — First-Order Predicate Logic & Relational Algebra

Core mathematical and computational abstractions.

Implemented concepts:

- Propositional logic
- Predicate logic
- Quantification over finite domains
- Relations
- Relational algebra
- Selection
- Projection
============================================================
*/


/*
============================================================
PROPOSITIONAL LOGIC
============================================================
*/

/*
Logical negation:

    ¬p
*/
int logical_not(int p);


/*
Logical conjunction:

    p ∧ q
*/
int logical_and(int p, int q);


/*
Logical disjunction:

    p ∨ q
*/
int logical_or(int p, int q);


/*
Material implication:

    p → q

Equivalent to:

    ¬p ∨ q
*/
int logical_implies(int p, int q);


/*
Logical equivalence:

    p ↔ q

True when p and q have the same truth value.
*/
int logical_equivalent(int p, int q);


/*
============================================================
PREDICATE LOGIC
============================================================
*/

/*
A unary predicate over an integer domain.

Example:

    P(x) = x > 80
*/
typedef int (*Predicate)(int value);


/*
Universal quantification:

    ∀x ∈ D, P(x)

Returns 1 if every element of the finite
domain satisfies the predicate.

Returns 0 otherwise.
*/
int evaluate_predicate(
    Predicate predicate,
    const int domain[],
    size_t size
);


/*
Counts the elements of D satisfying:

    P(x)

This corresponds to determining the
cardinality of:

    {x ∈ D | P(x)}
*/
size_t count_satisfying(
    Predicate predicate,
    const int domain[],
    size_t size
);


/*
============================================================
RELATIONAL ALGEBRA
============================================================
*/

/*
A tuple represents a simple relation element:

    Tuple(id, value)
*/
typedef struct
{
    int id;
    int value;

} Tuple;


/*
A finite relation represented as
a collection of tuples.

Conceptually:

    R ⊆ D × V
*/
typedef struct
{
    Tuple tuples[100];

    size_t size;

} Relation;


/*
Create an empty relation.
*/
Relation create_relation(void);


/*
Insert a tuple into a relation.
*/
void add_tuple(
    Relation* relation,
    int id,
    int value
);


/*
============================================================
SELECTION
============================================================

Relational algebra:

    σP(R)

Returns the subset of R containing
only tuples satisfying predicate P.
============================================================
*/
Relation selection(
    const Relation* relation,
    Predicate predicate
);


/*
============================================================
PROJECTION
============================================================

Relational algebra:

    πid(R)

Returns the identifier attribute of
each tuple.

The value field is discarded.
============================================================
*/
Relation projection_id(
    const Relation* relation
);

#endif