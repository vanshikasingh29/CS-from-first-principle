# 10 — C Preprocessor

> Understanding the stage before compilation.

---

# Overview

The C preprocessor transforms source code before the compiler runs.

The preprocessor handles:

- macros
- header files
- conditional compilation
- code generation

---

# Compilation Pipeline

A C program follows:

```
.c File

↓

Preprocessor

↓

Compiler

↓

Assembler

↓

Linker

↓

Executable

```

---

# Preprocessor Directives

Preprocessor commands begin with:

```c
#
```

Examples:

```c
#define

#include

#ifdef

#ifndef

#endif

```

---

# 1. Macros

A macro replaces text before compilation.

Example:

```c
#define PI 3.14159
```

The preprocessor changes:

```c
area = PI * r * r;
```

into:

```c
area = 3.14159 * r * r;
```

---

# 2. Header Files

Header files contain reusable declarations.

Example:

```c
#include <stdio.h>
```

The preprocessor inserts the contents of the header.

Conceptually:

```
main.c

+

stdio.h

↓

Expanded Source

```

---

# 3. Header Guards

Large projects include headers many times.

Problem:

```
header included twice

↓

duplicate definitions

↓

compiler errors

```

Solution:

Header guards.

Example:

```c
#ifndef FILE_H
#define FILE_H

...

#endif
```

---

# 4. Conditional Compilation

Allows different code depending on conditions.

Example:

```c
#ifdef WINDOWS

run_windows_code();

#endif

```

Useful for:

- different operating systems
- different hardware
- debugging builds

---

# Learning Objectives

After completing this folder:

You should understand:

✓ Compilation stages  
✓ Macro replacement  
✓ Header files  
✓ Include process  
✓ Header guards  
✓ Conditional compilation  

---

# Files

| File | Purpose |
|-|-|
| macros.c | Macro examples |
| header_guards.c | Header protection concepts |

---


---

# Connection To Future Modules

The preprocessor prepares you for:

```
Source Code

↓

Compiler Design

↓

Operating Systems

↓

Large Software Projects

```

---

# Key Idea

The compiler does not see the code you wrote.

It sees the code after preprocessing.