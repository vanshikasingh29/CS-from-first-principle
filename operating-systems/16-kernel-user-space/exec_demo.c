/*
============================================================

CS From First Principles

Phase 4 — Operating Systems & Networks

Topic 16 — Kernel vs User Space

File:
exec_demo.c

Purpose:
Demonstrate how exec() replaces the current process image.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" exec() Process Replacement Demo\n");
    printf("========================================\n\n");


    printf(
        "Current process PID: %ld\n",
        (long) getpid()
    );


    printf(
        "About to replace this process with 'ls'.\n\n"
    );


    /*
    execlp() replaces the current process image.

    If successful, execution does NOT continue
    after this function.

    The process itself remains the same,
    but its program image is replaced.
    */

    execlp(
        "ls",
        "ls",
        "-l",
        NULL
    );


    /*
    This code is reached only if exec fails.
    */

    perror("execlp");

    return EXIT_FAILURE;
}