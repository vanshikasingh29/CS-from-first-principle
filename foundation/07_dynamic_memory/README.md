# 07 — Dynamic Memory

> Understanding heap allocation and manual memory management in C.

---

# Overview

Computer memory is divided into different regions.

A simplified model:

```
High Memory

+----------------+
| Stack          |
+----------------+
| Heap           |
+----------------+
| Data           |
+----------------+
| Code           |
+----------------+

Low Memory
```

The stack is automatically managed.

The heap is manually managed by the programmer.

---

# Why Heap Memory Exists

The stack has limitations:

- fixed lifetime
- limited size
- disappears after function return

The heap allows:

- dynamic sizes
- long-lived data
- runtime allocation

Example:

A program does not know how many users exist until runtime.

Heap memory solves this problem.

---

# Learning Objectives

After completing this chapter, you should understand:

- Stack vs heap memory
- malloc()
- calloc()
- realloc()
- free()
- Memory ownership
- Memory leaks
- Dangling pointers

---

# Files

| File | Purpose |
|-|-|
| notes.md | Heap theory and memory ownership |
| malloc.c | Allocating and freeing memory |
| realloc.c | Resizing dynamic memory |

---

# malloc()

Function:

```c
malloc()
```

means:

```
memory allocation
```

Example:

```c
int *numbers;

numbers = malloc(sizeof(int) * 10);
```

The program requests:

```
10 integers worth of memory
```

---

# Heap Memory Example

```
Stack

+-------------+
| pointer     |
+-------------+
       |
       |
       v

Heap

+-------------+
| 10 integers |
+-------------+

```

The pointer lives on the stack.

The allocated memory lives on the heap.

---

# free()

When memory is no longer required:

```c
free(pointer);
```

The programmer returns the memory.

---

# Memory Leak

Incorrect:

```c
malloc(100);
```

without:

```c
free();
```

The memory remains allocated.

Over time:

```
Program Running

↓

Allocate Memory

↓

Forget To Free

↓

Memory Usage Increases

```

---

# calloc()

Similar to malloc:

```c
calloc(number,size);
```

Difference:

malloc:

```
uninitialised memory
```

calloc:

```
initialised to zero
```

---

# realloc()

Allows resizing:

```c
realloc(pointer,new_size);
```

Example:

```
Old memory:

[10][20][30]


Resize


[10][20][30][40][50]

```

---

# Ownership Concept

Every allocated block should have:

```
One owner

One responsibility

One free()

```

Example:

```
Create memory

↓

Use memory

↓

Release memory

```

---

# Common Memory Errors

## Memory Leak

Memory allocated but never released.

---

## Dangling Pointer

Pointer refers to freed memory.

Example:

```c
free(ptr);

ptr still exists;

```

---

## Double Free

Incorrect:

```c
free(ptr);

free(ptr);

```

Can corrupt heap metadata.

---


---

# Connection To Future Modules

Dynamic memory prepares you for:

```
Heap Management

↓

Operating Systems

↓

Virtual Memory

↓

Memory Allocators

↓

Garbage Collection

↓

Programming Language Design
```

---

# Key Idea

Dynamic memory gives the programmer control.

With that control comes responsibility.