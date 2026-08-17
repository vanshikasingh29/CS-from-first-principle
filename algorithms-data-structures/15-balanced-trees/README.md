# Topic 15 — Balanced Trees

Practical implementation of balanced binary search trees from first principles.

## Concepts

- Binary Search Trees
- Tree rotations
- Balance factors
- AVL trees
- Insertion rebalancing
- Deletion rebalancing
- Height guarantees
- Ordered traversal

## Objective

Understand how balanced trees maintain logarithmic height and why balancing is essential for predictable search, insertion, and deletion performance.

## Complexity

For an AVL tree:

| Operation | Average | Worst Case |
|---|---:|---:|
| Search | O(log n) | O(log n) |
| Insert | O(log n) | O(log n) |
| Delete | O(log n) | O(log n) |

The AVL implementation maintains the invariant:

```text
balance factor = height(left) - height(right)

-1 <= balance factor <= 1