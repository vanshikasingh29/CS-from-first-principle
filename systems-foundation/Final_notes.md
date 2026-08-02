# Final notes for the foundation of CS

## How Does a C Program Become a Running Process?


### 1. Source Code

A programmer writes C code.

Example:

```c
#include <stdio.h>

int main()
{
    printf("Hello");
}
```

### 2. Preprocessor

The preprocessor runs first.

It handles:


- #include
- #define
- conditional compilation

Example:
```
#include <stdio.h>
```

is expanded into the contents of the header file.

The compiler does not see the original source code.

It sees the processed version.

### 3. Compiler

The compiler translates C into lower-level instructions.

Process:
```
C Code

↓

Assembly

↓

Machine Instructions
```

The compiler performs:

- syntax checking
- optimisation
- translation

### 4. Assembler and Linker

Assembly becomes machine code.

The linker combines:

- object files
- libraries

into one executable.

### 5. Operating System Loads Process

When the executable runs:

The OS creates a process.

A process receives:

- memory
- CPU time
- resources

### 6. Memory Layout

A running program contains:

```
Code Segment

↓

Global Data

↓

Heap

↓

Stack
```

Code:

contains instructions.

Data:

contains global variables.

Heap:

dynamic memory from malloc.

Stack:

function calls and local variables.

### 7. CPU Execution

The CPU repeatedly performs:

Fetch

↓

Decode

↓

Execute

Instructions are loaded from memory and processed.

### 8. File Interaction

Programs cannot directly control hardware.

File access follows:

Program

↓

Library

↓

Operating System

↓

File System

↓

Storage Device

The OS provides safe hardware access.