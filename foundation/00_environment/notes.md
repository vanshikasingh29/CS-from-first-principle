# Environment Notes

## The Journey from Source Code to Execution

When writing a C program, the computer does not execute the `.c` file directly.

Instead, it passes through several stages.

```
Source Code

↓

Preprocessor

↓

Compiler

↓

Assembler

↓

Object File

↓

Linker

↓

Executable

↓

Operating System Loader

↓

CPU Execution
```

This pipeline is one of the first steps towards systems programming.

---

# GCC

GCC stands for:

GNU Compiler Collection

Despite the name, GCC performs far more than compilation.

It invokes:

- Preprocessor
- Compiler
- Assembler
- Linker

---

# Executable Files

After compilation, the executable contains machine instructions understood directly by the processor.

The operating system loads this executable into memory before execution begins.

---

# Build Automation

Typing long GCC commands repeatedly is inefficient.

Professional projects instead use:

- Make
- CMake
- Meson
- Ninja

This stage begins with Make.

---

# Debugging

Professional developers rarely rely solely on print statements.

Instead they use:

- Breakpoints
- Variable inspection
- Memory inspection
- Call stack analysis

Later chapters will introduce GDB.

---

# Key Takeaways

✓ Source code is not executable.

✓ Compilation is a pipeline.

✓ Linking combines object files.

✓ The operating system loads executables into memory.

✓ Build systems automate compilation.