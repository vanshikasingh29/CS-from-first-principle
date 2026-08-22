/*
============================================================
CS From First Principles

Phase 4 — Operating Systems & Networks
Topic 17 — Concurrency

File:
main.c

Purpose:
Runs concurrency demonstrations involving threads,
mutexes and semaphores.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "concurrency.h"


int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Concurrency Demonstration\n");
    printf("========================================\n\n");


    /*
    ========================================================
    1. Threads + Mutex
    ========================================================
    */

    printf("1. Threads + Mutex\n\n");


    SharedCounter counter;


    if (counter_init(&counter) != 0)
    {
        fprintf(
            stderr,
            "Failed to initialise counter.\n"
        );

        return EXIT_FAILURE;
    }


    pthread_t threads[THREAD_COUNT];


    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(
            &threads[i],
            NULL,
            increment_counter,
            &counter
        );
    }


    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(
            threads[i],
            NULL
        );
    }


    long expected =
        (long)THREAD_COUNT *
        INCREMENTS_PER_THREAD;


    printf(
        "Expected counter: %ld\n",
        expected
    );


    printf(
        "Actual counter:   %ld\n",
        counter.counter
    );


    counter_destroy(&counter);


    /*
    ========================================================
    2. Semaphore
    ========================================================
    */

    printf("\n2. Semaphore\n\n");


    SemaphoreResource resource;


    if (
        semaphore_init(
            &resource,
            1
        ) != 0
    )
    {
        fprintf(
            stderr,
            "Failed to initialise semaphore.\n"
        );

        return EXIT_FAILURE;
    }


    pthread_t semaphore_threads[THREAD_COUNT];


    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(
            &semaphore_threads[i],
            NULL,
            semaphore_worker,
            &resource
        );
    }


    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(
            semaphore_threads[i],
            NULL
        );
    }


    printf(
        "Semaphore-controlled value: %d\n",
        resource.value
    );


    semaphore_destroy(&resource);


    printf(
        "\nConcurrency demonstration complete.\n"
    );


    return EXIT_SUCCESS;
}