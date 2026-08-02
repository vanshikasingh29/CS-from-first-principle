# Dynamic Memory Theory Notes

---

# 1. Memory Regions

A running program contains multiple memory areas.

Simplified:

```
+----------------+
| Stack          |
+----------------+
| Heap           |
+----------------+
| Global Data    |
+----------------+
| Program Code   |
+----------------+

```

---

# 2. Stack Memory

Used for:

- local variables
- function calls
- return addresses

Example:

```c
void function()
{
    int x = 10;
}
```

Memory:

```
Stack Frame

+-----------+
| x = 10    |
+-----------+

```

Destroyed when function ends.

---

# 3. Heap Memory

Used for:

- dynamic data
- unknown sizes
- long-lived objects

Example:

```c
int *ptr = malloc(sizeof(int));
```

Memory:

```
Stack

ptr
 |
 |
 v

Heap

+------+
| 10   |
+------+

```

---

# 4. malloc()

Syntax:

```c
malloc(size);
```

Example:

```c
int *array;

array = malloc(
    sizeof(int) * 5
);
```

Requests:

```
5 integers
```

---

# 5. malloc Does Not Initialise

Example:

```c
int *value = malloc(sizeof(int));
```

The memory contains unknown data.

It must be assigned before use.

---

# 6. calloc()

Syntax:

```c
calloc(count,size);
```

Example:

```c
calloc(10,sizeof(int));
```

Creates:

```
10 integers
```

Initialised:

```
0
```

---

# 7. realloc()

Used when memory requirements change.

Example:

Initial:

```
[1][2][3]

```

Need more:

```
[1][2][3][4][5][6]

```

realloc handles resizing.

---

# 8. free()

Memory must be returned.

Example:

```c
free(pointer);
```

After freeing:

```
Heap memory released
```

---

# 9. Ownership

The most important rule:

```
Whoever allocates memory
must know who frees it.
```

---

# 10. Memory Safety

Incorrect management causes:

## Leak

```
Allocate

↓

Lose pointer

↓

Memory trapped forever

```

---

## Use After Free

```
Allocate

↓

Free

↓

Access again

```

Undefined behaviour.

---

## Double Free

```
Free

↓

Free again

```

Heap corruption.

---

# 11. Why C Requires This Knowledge

Higher-level languages hide memory management.

Examples:

Python:

```
Garbage Collector
```

Java:

```
JVM Garbage Collection
```

C:

```
Programmer controls memory
```

This provides:

- speed
- predictability
- hardware control

---

# 12. Operating System Connection

malloc eventually requests memory from the OS.

Conceptually:

```
Program

↓

malloc()

↓

C Library

↓

System Calls

↓

Kernel

↓

Virtual Memory

↓

Physical RAM

```

---

# Key Takeaways

✓ Stack memory is automatic.

✓ Heap memory is manually managed.

✓ malloc allocates memory.

✓ calloc allocates and clears memory.

✓ realloc changes allocation size.

✓ free releases memory.

✓ Memory ownership prevents bugs.

✓ Dynamic memory is the foundation of systems programming.

---

# Next

Implementation files will demonstrate:

1. Creating heap allocations.
2. Checking allocation failures.
3. Writing and reading heap memory.
4. Resizing memory dynamically.