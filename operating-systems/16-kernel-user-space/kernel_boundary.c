
/*
============================================================

CS From First Principles

Phase 4 — Operating Systems & Networks

Topic 16 — Kernel vs User Space

File:
kernel_boundary.c

Purpose:
Demonstrate the boundary between a user-space program
and operating-system services exposed through system calls.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>


/*
============================================================
Process identity
============================================================
*/

static void demonstrate_process_identity(void)
{
    pid_t process_id = getpid();

    pid_t parent_id = getppid();


    printf("Process ID: %ld\n", (long) process_id);

    printf(
        "Parent Process ID: %ld\n",
        (long) parent_id
    );
}


/*
============================================================
Main
============================================================
*/

int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Kernel / User Space Demonstration\n");
    printf("========================================\n\n");


    printf("User-space program is running.\n\n");


    /*
    getpid() and getppid() request information
    managed by the operating system.
    */

    demonstrate_process_identity();


    printf("\n");


    printf(
        "The application requested process information\n"
        "through operating-system services.\n"
    );


    printf("\nDemonstration complete.\n\n");


    return EXIT_SUCCESS;
}