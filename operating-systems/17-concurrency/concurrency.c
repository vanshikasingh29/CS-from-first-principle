/*
============================================================
CS From First Principles

Phase 4 — Operating Systems & Networks
Topic 17 — Concurrency

File:
concurrency.c

Purpose:
Demonstrates thread synchronisation using POSIX mutexes
and semaphores.

============================================================
*/

#include "concurrency.h"

#include <stdio.h>
#include <errno.h>


/*
============================================================
Mutex-protected shared counter
============================================================
*/

int counter_init(SharedCounter *counter)
{
    if (counter == NULL)
    {
        return -1;
    }

    counter->counter = 0;

    if (pthread_mutex_init(&counter->mutex, NULL) != 0)
    {
        return -1;
    }

    return 0;
}


void counter_destroy(SharedCounter *counter)
{
    if (counter == NULL)
    {
        return;
    }

    pthread_mutex_destroy(&counter->mutex);
}


/*
============================================================
Thread worker

Each thread increments the same shared counter.

The mutex creates a critical section around the shared
state modification.

============================================================
*/

void *increment_counter(void *argument)
{
    SharedCounter *counter =
        (SharedCounter *)argument;

    if (counter == NULL)
    {
        return NULL;
    }


    for (
        int i = 0;
        i < INCREMENTS_PER_THREAD;
        i++
    )
    {
        /*
        Lock before accessing shared state.
        */

        pthread_mutex_lock(
            &counter->mutex
        );


        counter->counter++;


        /*
        Release the critical section.
        */

        pthread_mutex_unlock(
            &counter->mutex
        );
    }


    return NULL;
}


/*
============================================================
Semaphore resource
============================================================
*/

int semaphore_init(
    SemaphoreResource *resource,
    int initial_value
)
{
    if (resource == NULL)
    {
        return -1;
    }

    resource->value = 0;


    if (
        sem_init(
            &resource->semaphore,
            0,
            initial_value
        ) != 0
    )
    {
        return -1;
    }


    return 0;
}


void semaphore_destroy(
    SemaphoreResource *resource
)
{
    if (resource == NULL)
    {
        return;
    }

    sem_destroy(
        &resource->semaphore
    );
}


/*
============================================================
Semaphore worker

The semaphore controls access to the shared resource.

============================================================
*/

void *semaphore_worker(void *argument)
{
    SemaphoreResource *resource =
        (SemaphoreResource *)argument;

    if (resource == NULL)
    {
        return NULL;
    }


    /*
    Wait until the resource is available.
    */

    sem_wait(
        &resource->semaphore
    );


    resource->value++;


    /*
    Release the resource.
    */

    sem_post(
        &resource->semaphore
    );


    return NULL;
}