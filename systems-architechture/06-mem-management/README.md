# Topic 6 — Manual Memory Management

## Phase 2 — Systems Architecture

This laboratory explores how dynamically allocated memory is managed in C.

The objective is to move from the abstract idea of variables and pointers to an understanding of memory lifetime, ownership, allocation, and deallocation.

---

## Learning Objectives

By completing this laboratory I should be able to explain:

- the difference between stack and heap memory,
- what a pointer represents,
- how `malloc()` allocates memory,
- how `calloc()` differs from `malloc()`,
- how `realloc()` changes an allocation,
- why dynamically allocated memory must eventually be released,
- what ownership means in manual memory management,
- why use-after-free and memory leaks are dangerous.

---

## Laboratory Components

### 1. Memory Demonstration

`src/memory_demo.c`

Demonstrates:

- stack allocation,
- heap allocation,
- addresses,
- pointer dereferencing,
- allocation and deallocation.

### 2. Dynamic Array

`src/dynamic_array.c`

Implements a small dynamically growing integer array.

The array demonstrates:

```text
malloc
    ↓
write elements
    ↓
realloc
    ↓
grow capacity
    ↓
free