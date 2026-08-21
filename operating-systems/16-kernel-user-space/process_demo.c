/*
============================================================

CS From First Principles

Phase 4 — Operating Systems & Networks

Topic 16 — Kernel vs User Space

File:
process_demo.c

Purpose:
Demonstrate process creation using fork().

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Process Creation Demonstration\n");
    printf("========================================\n\n");


    printf(
        "Before fork(): PID = %ld\n",
        (long) getpid()
    );


    /*
    fork() asks the operating system to create
    a new child process.

    Return value:

    < 0  -> error
    = 0  -> child process
    > 0  -> parent process receives child PID
    */

    pid_t child_pid = fork();


    if (child_pid < 0)
    {
        perror("fork");

        return EXIT_FAILURE;
    }


    if (child_pid == 0)
    {
        /*
        This code executes inside the child.
        */

        printf(
            "Child process running: PID = %ld\n",
            (long) getpid()
        );

        printf(
            "Child parent PID = %ld\n",
            (long) getppid()
        );


        return EXIT_SUCCESS;
    }


    /*
    This code executes inside the parent.
    */

    printf(
        "Parent process running: PID = %ld\n",
        (long) getpid()
    );


    printf(
        "Created child with PID = %ld\n",
        (long) child_pid
    );


    /*
    waitpid() allows the parent to wait for
    the child to terminate.
    */

    int status = 0;

    waitpid(
        child_pid,
        &status,
        0
    );


    printf(
        "Child process has terminated.\n"
    );


    printf(
        "\nProcess demonstration complete.\n\n"
    );


    return EXIT_SUCCESS;
}