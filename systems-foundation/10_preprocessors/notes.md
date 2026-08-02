# C Preprocessor Theory Notes

---

# 1. What Is The Preprocessor?

The preprocessor is a program that modifies C source code before compilation.

It runs automatically.

Pipeline:

```
Original Code

↓

Preprocessor

↓

Modified Code

↓

Compiler

```

---

# 2. Preprocessor Directives

Directives start with:

```c
#
```

Examples:

```c
#define

#include

#if

#ifdef

#ifndef

```

They are not normal C statements.

---

# 3. Macros

A macro is a text substitution rule.

Example:

```c
#define SIZE 100
```

Before compilation:

```c
array[SIZE]
```

becomes:

```c
array[100]
```

---

# 4. Object-Like Macros

Example:

```c
#define MAX 100
```

Replacement:

```
MAX

↓

100

```

---

# 5. Function-Like Macros

Example:

```c
#define SQUARE(x) ((x)*(x))
```

Usage:

```c
SQUARE(5)
```

becomes:

```c
((5)*(5))
```

---

# 6. Why Parentheses Matter

Dangerous macro:

```c
#define SQUARE(x) x*x
```

Problem:

```c
SQUARE(2+3)
```

expands:

```
2+3*2+3

```

Incorrect.

Correct:

```c
#define SQUARE(x) ((x)*(x))
```

---

# 7. Header Files

Header files contain:

- function declarations
- structures
- constants

Example:

```
stdio.h

↓

printf()

scanf()

FILE

```

---

# 8. Include Process

When writing:

```c
#include "myfile.h"
```

The preprocessor effectively copies the file contents.

Example:

```
main.c

+

myfile.h

=

expanded.c

```

---

# 9. Header Guards

Problem:

```
A includes B

C includes B

main includes A and C

```

B may appear multiple times.

Solution:

```c
#ifndef HEADER_H
#define HEADER_H

code

#endif
```

---

# 10. Conditional Compilation

Allows selective code.

Example:

```c
#ifdef DEBUG

printf("Debug mode");

#endif
```

Only included when DEBUG exists.

---

# 11. Real Industry Usage

Used for:

## Operating Systems

Different hardware:

```
x86

ARM

RISC-V

```

---

## Libraries

Different platforms:

```
Windows

Linux

macOS

```

---

## Debug Builds

Debug:

```
extra checks

```

Release:

```
optimised code

```

---

# 12. Relationship To Compilers

The preprocessor is the first compiler stage.

Understanding it helps with:

- compiler design
- build systems
- dependency management
- large-scale engineering

---

# Key Takeaways

✓ Preprocessor runs before compilation.

✓ Macros perform text substitution.

✓ Headers organise large projects.

✓ Header guards prevent duplication.

✓ Conditional compilation supports portability.

✓ Professional C projects rely heavily on preprocessing.

---

# Next

Implementation files:

`macros.c`

and

`header_guards.c`

will demonstrate:

- constants
- macro functions
- debugging macros
- safe header organisation concepts.