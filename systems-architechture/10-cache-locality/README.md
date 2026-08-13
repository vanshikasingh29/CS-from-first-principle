# Topic 10 — Cache Locality & Memory Hierarchy

## CS From First Principles

Phase 2 — Systems Architecture

This lab demonstrates how memory access patterns affect program performance.

## Concepts

- CPU registers
- CPU caches
- RAM
- cache lines
- spatial locality
- temporal locality
- row-major memory layout
- sequential access
- strided access
- performance measurement

## Experiment

The program compares two ways of traversing a two-dimensional array.

### Row-major traversal

```
A[0][0]
A[0][1]
A[0][2]
A[0][3]
```
Adjacent elements are accessed together.

This provides good spatial locality.

### Column-major traversal
```
A[0][0]
A[1][0]
A[2][0]
A[3][0]
```

Memory locations are accessed further apart.

This can result in poorer cache utilisation.