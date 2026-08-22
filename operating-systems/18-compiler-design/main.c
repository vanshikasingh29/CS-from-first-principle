/*
============================================================

CS From First Principles

Phase 4 — Operating Systems & Networks

Topic 18 — Compiler Design

File:
main.c

Purpose:
Demonstrates lexical analysis.

============================================================
*/

#include <stdio.h>

#include "lexer.h"


int main(void)
{
    const char *source =
        "x + 42 * y";


    printf("\n");
    printf("========================================\n");
    printf(" Mini Compiler Front-End\n");
    printf("========================================\n\n");


    printf(
        "Source:\n%s\n\n",
        source
    );


    printf(
        "Tokens:\n"
    );

    printf(
        "----------------------------------------\n"
    );


    Lexer lexer;

    lexer_init(
        &lexer,
        source
    );


    while (1)
    {
        Token token =
            lexer_next_token(
                &lexer
            );


        printf(
            "%-12s %s\n",
            token_type_name(
                token.type
            ),
            token.value
        );


        if (
            token.type == TOKEN_EOF
        )
        {
            break;
        }
    }


    printf("\n");
    printf(
        "Lexical analysis complete.\n"
    );


    return 0;
}