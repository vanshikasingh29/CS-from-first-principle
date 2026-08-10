# Topic 1 — First-Order Predicate Logic & Relational Algebra

This laboratory implements core concepts from discrete mathematics computationally.

The purpose is to connect formal mathematical definitions with executable programs.

## Concepts

### Propositional Logic

Implemented:

- NOT
- AND
- OR
- implication
- logical equivalence

### Predicate Logic

Predicates are evaluated over finite domains.

Example:

```
P(x) = x > 80
```

A finite domain can then be evaluated to determine which elements satisfy the predicate.

##### Relational Algebra
The laboratory demonstrates:

- selection
- projection

These operations form part of the mathematical foundation of SQL.

##### Mathematical Connection

Selection:
```
σ condition(R)
```
Projection:
```
π attribute(R)
```

The implementation translates these mathematical operations into executable C functions.


### Learning Objective

The objective is not simply to implement Boolean functions.

The objective is to understand how:
```
Formal Logic
      ↓
Predicates
      ↓
Relations
      ↓
Relational Algebra
      ↓
Database Query Processing
```

This laboratory provides the computational bridge between the mathematical theory studied in Topic 1 and the Logic Query Engine portfolio project.