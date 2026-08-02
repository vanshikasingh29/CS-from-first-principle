# Notes — The C Memory Model

---

# Introduction

When a C program is executed, the operating system creates a **process**.

A process is more than just code.

It is an organised collection of memory regions, registers, execution state, and operating system metadata.

One of the first responsibilities of the operating system loader is to map different parts of the executable into memory.

These regions are not arbitrary (based on random choices). 
Instead they exist because different kinds of data require different lifetimes and permissions.

---

# A Process in Memory

A simplified view:

```

High Addresses

+-----------------------------+
| Command-line arguments |
+-----------------------------+
| Environment Variables |
+-----------------------------+
| Stack |
| |
| Local variables |
| Function parameters |
| Return addresses |
| Saved registers |
| |
| grows downward ↓ |
+-----------------------------+
| |
| Free Memory |
| |
+-----------------------------+
| grows upward ↑ |
| Heap |
| |
| malloc() |
| calloc() |
| realloc() |
+-----------------------------+
| BSS Segment |
| |
| Uninitialised globals |
| Uninitialised statics |
+-----------------------------+
| Data Segment |
| |
| Initialised globals |
| Initialised statics |
+-----------------------------+
| Text Segment |
| |
| Machine Instructions |
| Read-only program code |
+-----------------------------+

Low Addresses

```

---

# Text Segment

Also called:

- Code Segment

Contains:

- Compiled machine instructions
- Executable code

Characteristics:

- Usually read-only
- Shared between processes where possible
- Loaded directly from the executable

Example:

```c
int add(int a, int b)
{
    return a + b;
}
```

The instructions implementing `add()` live here.

---

# Data Segment

Stores:

- Global variables
- Static variables
- Variables with explicit initial values

Example:

```c
int counter = 5;
```

Characteristics:

- Exists for the entire lifetime of the program.
- Read/write memory.
- Initialised before `main()` begins.

---

# BSS Segment

Historically:

**Block Started by Symbol**

Stores:

- Uninitialised global variables.
- Uninitialised static variables.

Example:

```c
int total;
```

Even though no value is specified, the operating system guarantees it begins as zero.

---

# Heap

The heap provides memory whose lifetime is controlled manually by the programmer.

Allocated using:

```c
malloc()

calloc()

realloc()
```

Released using:

```c
free()
```

Characteristics:

- Large memory region.
- Grows upward.
- Exists until explicitly released.
- Slower than stack allocation.
- Essential for dynamic data structures.

Examples:

- Linked lists
- Trees
- Graphs
- Hash tables
- Dynamic arrays

---

# Stack

Every function call creates a **stack frame**.

Each stack frame stores:

- Parameters
- Local variables
- Return address
- Saved registers

Example:

```c
void example()
{
    int x = 5;
}
```

`x` exists only while `example()` is executing.

When the function returns:

The entire stack frame disappears.

---

# Stack Growth

Most modern architectures grow the stack downward.

```

Address

1000

995

990 ← Stack Pointer

985

980

975

```

Each function call usually decreases the stack pointer.

Returning from a function restores it.

---

# Heap Growth

The heap generally grows upward.

```

100

105

110

115

120

```

Eventually, the heap and stack meet.

If they collide:

Memory exhaustion occurs. A state where a computer runs out of available memory resources to function or process new information properly

---

# Stack vs Heap

| Stack | Heap |
|---------|------|
| Automatic | Manual |
| Very fast | Slower |
| Small | Much larger |
| Freed automatically | Must call free() |
| Function lifetime | Programmer-controlled lifetime |

---

# Lifetime of Variables

Local variable:

```c
void test()
{
    int x = 5;
}
```

Exists only during the execution of `test()`.

---

Global variable:

```c
int x = 5;
```

Exists from program start until program termination.

---

Dynamic variable:

```c
int *p = malloc(sizeof(int));
```

Exists until:

```c
free(p);
```

or the process exits.

---

# Common Memory Errors

Returning pointers to local variables.

Example:

```c
int* bad()
{
    int x = 10;

    return &x;
}
```

This pointer becomes invalid immediately after the function returns because `x` lived on the stack.

---

Memory Leak

```c
malloc(...);
```

without

```c
free(...)
```

Allocated memory becomes unreachable.

---

Dangling Pointer

```c
free(ptr);

*ptr = 5;
```

The pointer still exists.

The memory does not.

---

Double Free

```c
free(ptr);

free(ptr);
```

Undefined behaviour.

---

# Key Takeaways

✓ A running program is divided into specialised memory regions.

✓ Every memory region exists for a different reason.

✓ Stack memory is temporary.

✓ Heap memory is dynamic.

✓ Globals live for the lifetime of the program.

✓ Understanding memory layout is essential before learning pointers, operating systems, or dynamic memory management.

---

# Looking Ahead

The next examples (`stack_vs_heap.c` and `memory_layout.c`) will move beyond theory and allow you to **observe the memory model in action** by printing addresses from different memory regions and comparing automatic versus dynamic allocation.