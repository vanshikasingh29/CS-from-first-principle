/*
============================================================

CS From First Principles

Phase 4 — Operating Systems & Networks

Topic 18 — Compiler Design

File:
lexer.h

Purpose:
Defines the lexical analyser interface.

============================================================
*/

#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>


/*
============================================================
Token Types
============================================================
*/

typedef enum
{
    TOKEN_IDENTIFIER,

    TOKEN_NUMBER,

    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,

    TOKEN_ASSIGN,

    TOKEN_LEFT_PAREN,
    TOKEN_RIGHT_PAREN,

    TOKEN_EOF,

    TOKEN_INVALID

} TokenType;


/*
============================================================
Token Structure
============================================================
*/

typedef struct
{
    TokenType type;

    char value[64];

    size_t position;

} Token;


/*
============================================================
Lexer Structure
============================================================
*/

typedef struct
{
    const char *source;

    size_t position;

} Lexer;


/*
============================================================
Lexer API
============================================================
*/

void lexer_init(
    Lexer *lexer,
    const char *source
);


Token lexer_next_token(
    Lexer *lexer
);


const char *token_type_name(
    TokenType type
);

#endif