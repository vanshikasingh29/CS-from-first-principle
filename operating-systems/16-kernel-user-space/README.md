# Topic 16 — Kernel vs User Space

## Systems Architecture Lab

This laboratory explores the boundary between user-space applications and the operating-system kernel.

The exercises demonstrate:

- processes
- process identifiers
- system calls
- `fork()`
- parent/child processes
- `exec()`
- `wait()`
- process isolation
- file descriptors

## Learning Objective

Understand how an ordinary C program transitions from user space into kernel-managed operations through system calls.

## Architecture

```text
User Application
       |
       | system call
       v
Operating System Kernel
       |
       v
Hardware / System Resources