# 01 — Memory Model

> Understanding how a program exists inside memory.

---

# Overview

Before learning pointers, dynamic memory allocation, or operating systems, it is essential to understand **how a running program is organised in memory**.

Many programming languages abstract memory management away from the developer. C does not.

Understanding the memory model is therefore one of the most important skills in systems programming.

This folder explores:

- The process memory layout
- Code (Text) Segment
- Data Segment
- BSS Segment
- Heap
- Stack
- Program execution
- Variable lifetime
- Function call memory

These concepts underpin virtually every later topic in Computer Science, including:

- Pointer arithmetic
- Dynamic memory allocation
- Recursion
- Operating systems
- Memory debugging
- Computer architecture

---

# Learning Objectives

After completing this chapter, you should be able to:

- Explain how an executable is loaded into memory.
- Describe each region of process memory.
- Distinguish between stack and heap allocation.
- Explain why local variables disappear after a function returns.
- Explain why dynamically allocated memory survives function calls.
- Predict where different variables are stored.
- Understand common memory-related bugs before writing complex C programs.

---

# Process Memory Layout

A simplified process memory layout looks like:

```

High Memory
+-----------------------+
| Command Line / Env |
+-----------------------+
| Stack |
| ↓ grows downward |
+-----------------------+
| |
| Free Memory |
| |
+-----------------------+
| ↑ grows upward |
| Heap |
+-----------------------+
| BSS |
+-----------------------+
| Data |
+-----------------------+
| Text (Machine Code) |
+-----------------------+

Low Memory

```

Each region has a different purpose and lifetime.

Understanding **why these regions exist** is more valuable than simply memorising their names.

---

# Files

| File | Description |
|------|-------------|
| notes.md | Detailed theory and memory diagrams |
| stack_vs_heap.c | Comparing automatic and dynamic memory |
| memory_layout.c | Printing addresses from different memory regions |

---

---

# Common Beginner Mistakes

- Returning pointers to local variables.
- Confusing stack memory with heap memory.
- Forgetting to free dynamically allocated memory.
- Assuming variables are stored "next to each other."
- Believing memory layout is identical across operating systems.

---

# Why This Matters

Everything in modern systems programming depends on understanding memory.

Later folders will build directly on this knowledge:

```

Memory Model
↓

Pointers
↓

Dynamic Memory

↓

Structs

↓

Operating Systems

↓

Virtual Memory

↓

Caches

↓

Compilers

```

Without a solid mental model of memory, pointers become confusing and debugging becomes extremely difficult.

This  establishes that foundation.