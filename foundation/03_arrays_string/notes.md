# Arrays & Strings Theory Notes

---

# 1. What Is An Array?

An array is a fixed-size collection of elements stored in consecutive memory locations.

Example:

```c
int numbers[5];
```

The compiler reserves:

```
5 × sizeof(int)

```

bytes of memory.

---

# Memory Representation

Example:

```c
int values[3] = {5,10,15};
```

Assuming integers are 4 bytes:

```
Address       Data

2000          5

2004          10

2008          15

```

The elements are adjacent.

---

# 2. Array Name As Address

When used in expressions:

```c
values
```

represents:

```c
&values[0]
```

The first element's address.

Example:

```c
printf("%p", values);
```

is equivalent to:

```c
printf("%p", &values[0]);
```

---

# 3. Array Indexing

The expression:

```c
values[i]
```

is translated by the compiler into:

```c
*(values + i)
```

Example:

```c
values[3]
```

becomes:

```c
*(values + 3)
```

---

# 4. Pointer Arithmetic

Pointers know their data type.

Example:

```c
int *ptr;
```

If:

```
ptr = 1000
```

then:

```
ptr + 1

```

moves:

```
1000 → 1004
```

because integers occupy 4 bytes.

---

# 5. Arrays Are Not Pointers

A common misconception:

"Arrays are pointers."

This is not completely true.

An array:

- owns memory
- has fixed size
- cannot be reassigned

Example:

```c
int array[5];
```

A pointer:

- stores an address
- can point elsewhere

Example:

```c
int *ptr;
```

However, arrays often decay into pointers.

---

# 6. Strings In C

A C string is:

```
character array + null terminator
```

Example:

```c
char word[] = "Hello";
```

Memory:

```
Index

0 H
1 e
2 l
3 l
4 o
5 \0

```

The null character tells functions where the string ends.

---

# 7. String Functions

Common library functions:

```c
strlen()
strcpy()
strcmp()
strcat()
```

from:

```c
#include <string.h>
```

---

# 8. Why Strings Are Dangerous

C gives programmers direct memory access.

Therefore:

The programmer controls:

- size
- allocation
- termination

Mistakes create:

- buffer overflow
- memory corruption
- security vulnerabilities

---

# 9. Buffer Overflow

Example:

Memory:

```
char username[8]

+---+---+---+---+
| A | B | C | D |
+---+---+---+---+

```

Writing beyond the boundary:

```
+---+---+---+---+---+
| A | B | C | D | X |
+---+---+---+---+---+

```

can overwrite unrelated memory.

---

# 10. Relationship To Later Topics

Arrays prepare us for:

## Data Structures

```
Arrays
 ↓
Dynamic Arrays
 ↓
Linked Lists
 ↓
Trees
```

---

## Operating Systems

Memory buffers are everywhere:

```
Disk
 ↓
RAM
 ↓
CPU
 ↓
Application

```

---

## Cybersecurity

Many historic vulnerabilities come from unsafe memory handling.

Examples:

- Stack smashing
- Buffer overflow attacks
- Memory corruption

---

# Key Takeaways

✓ Arrays are contiguous memory.

✓ Indexing is pointer arithmetic.

✓ Strings are character arrays.

✓ Strings require null termination.

✓ Memory boundaries matter.

✓ Understanding arrays is understanding memory.

---

# Next

The implementation files will demonstrate:

1. Array memory addresses
2. Traversing arrays using pointers
3. Creating and manipulating C strings
4. Safe string handling practices