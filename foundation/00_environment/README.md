# 00 — Development Environment

## Overview

Before writing systems software, it is important to understand the development environment used by professional C programmers.

This chapter introduces:

- GCC
- Object files
- Executables
- Build systems
- Visual Studio Code
- Make
- Debugging

Although these concepts appear simple, they form the foundation of every systems programming project.

---

# Files

| File | Purpose |
|------|---------|
| hello.c | First build example |
| Makefile | Automates compilation |
| notes.md | Theory notes |
| launch.json | VS Code debugger |
| tasks.json | Build task |
| .gitignore | Ignore generated files |

---



Compile manually:

```bash
gcc hello.c -o hello
```

Run:

```bash
./hello
```

Or simply run:

```bash
make
```

--
# Learning Outcomes

After completing this folder you should understand:

- Source code
- Compilation
- Linking
- Executables
- Build automation
- Debugging workflow

These concepts are prerequisites for every later topic.