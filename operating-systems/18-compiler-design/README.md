# Topic 18 — Compiler Design

## Lab: Mini Compiler Front-End

A first-principles implementation of the earliest stages of a compiler pipeline.

This lab demonstrates how source code is transformed from raw characters into structured tokens.

## Pipeline

```text
Source Code
    ↓
Lexical Analysis
    ↓
Tokens
    ↓
Parsing
    ↓
Abstract Syntax Tree
    ↓
Semantic Analysis
    ↓
Intermediate Representation
    ↓
Code Generation