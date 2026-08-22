/*
============================================================

CS From First Principles

Phase 4 — Operating Systems & Networks

Topic 18 — Compiler Design

File:
lexer.c

Purpose:
Implements a simple lexical analyser.

The lexer converts a sequence of characters into tokens.

============================================================
*/

#include "lexer.h"

#include <ctype.h>
#include <stdio.h>
#include <string.h>


/*
============================================================
Initialise Lexer
============================================================
*/

void lexer_init(
    Lexer *lexer,
    const char *source
)
{
    lexer->source = source;
    lexer->position = 0;
}


/*
============================================================
Create Token
============================================================
*/

static Token create_token(
    TokenType type,
    const char *value,
    size_t position
)
{
    Token token;

    token.type = type;
    token.position = position;

    if (value != NULL)
    {
        strncpy(
            token.value,
            value,
            sizeof(token.value) - 1
        );

        token.value[
            sizeof(token.value) - 1
        ] = '\0';
    }
    else
    {
        token.value[0] = '\0';
    }

    return token;
}


/*
============================================================
Read Identifier
============================================================
*/

static Token read_identifier(
    Lexer *lexer
)
{
    size_t start = lexer->position;

    while (
        isalnum(
            (unsigned char)
            lexer->source[lexer->position]
        )
        ||
        lexer->source[lexer->position] == '_'
    )
    {
        lexer->position++;
    }


    size_t length =
        lexer->position - start;


    char buffer[64];


    if (length >= sizeof(buffer))
    {
        length = sizeof(buffer) - 1;
    }


    memcpy(
        buffer,
        lexer->source + start,
        length
    );


    buffer[length] = '\0';


    return create_token(
        TOKEN_IDENTIFIER,
        buffer,
        start
    );
}


/*
============================================================
Read Number
============================================================
*/

static Token read_number(
    Lexer *lexer
)
{
    size_t start = lexer->position;


    while (
        isdigit(
            (unsigned char)
            lexer->source[lexer->position]
        )
    )
    {
        lexer->position++;
    }


    size_t length =
        lexer->position - start;


    char buffer[64];


    if (length >= sizeof(buffer))
    {
        length = sizeof(buffer) - 1;
    }


    memcpy(
        buffer,
        lexer->source + start,
        length
    );


    buffer[length] = '\0';


    return create_token(
        TOKEN_NUMBER,
        buffer,
        start
    );
}


/*
============================================================
Get Next Token
============================================================
*/

Token lexer_next_token(
    Lexer *lexer
)
{
    const char *source =
        lexer->source;


    /*
    --------------------------------------------------------
    Ignore whitespace
    --------------------------------------------------------
    */

    while (
        isspace(
            (unsigned char)
            source[lexer->position]
        )
    )
    {
        lexer->position++;
    }


    size_t position =
        lexer->position;


    char current =
        source[position];


    /*
    --------------------------------------------------------
    End of input
    --------------------------------------------------------
    */

    if (current == '\0')
    {
        return create_token(
            TOKEN_EOF,
            "",
            position
        );
    }


    /*
    --------------------------------------------------------
    Identifiers
    --------------------------------------------------------
    */

    if (
        isalpha(
            (unsigned char) current
        )
        ||
        current == '_'
    )
    {
        return read_identifier(
            lexer
        );
    }


    /*
    --------------------------------------------------------
    Numbers
    --------------------------------------------------------
    */

    if (
        isdigit(
            (unsigned char) current
        )
    )
    {
        return read_number(
            lexer
        );
    }


    /*
    --------------------------------------------------------
    Operators
    --------------------------------------------------------
    */

    lexer->position++;


    switch (current)
    {
        case '+':

            return create_token(
                TOKEN_PLUS,
                "+",
                position
            );


        case '-':

            return create_token(
                TOKEN_MINUS,
                "-",
                position
            );


        case '*':

            return create_token(
                TOKEN_MULTIPLY,
                "*",
                position
            );


        case '/':

            return create_token(
                TOKEN_DIVIDE,
                "/",
                position
            );


        case '=':

            return create_token(
                TOKEN_ASSIGN,
                "=",
                position
            );


        case '(':

            return create_token(
                TOKEN_LEFT_PAREN,
                "(",
                position
            );


        case ')':

            return create_token(
                TOKEN_RIGHT_PAREN,
                ")",
                position
            );


        default:
        {
            char invalid[2];

            invalid[0] = current;
            invalid[1] = '\0';


            return create_token(
                TOKEN_INVALID,
                invalid,
                position
            );
        }
    }
}


/*
============================================================
Token Type Names
============================================================
*/

const char *token_type_name(
    TokenType type
)
{
    switch (type)
    {
        case TOKEN_IDENTIFIER:
            return "IDENTIFIER";

        case TOKEN_NUMBER:
            return "NUMBER";

        case TOKEN_PLUS:
            return "PLUS";

        case TOKEN_MINUS:
            return "MINUS";

        case TOKEN_MULTIPLY:
            return "MULTIPLY";

        case TOKEN_DIVIDE:
            return "DIVIDE";

        case TOKEN_ASSIGN:
            return "ASSIGN";

        case TOKEN_LEFT_PAREN:
            return "LEFT_PAREN";

        case TOKEN_RIGHT_PAREN:
            return "RIGHT_PAREN";

        case TOKEN_EOF:
            return "EOF";

        case TOKEN_INVALID:
            return "INVALID";

        default:
            return "UNKNOWN";
    }
}