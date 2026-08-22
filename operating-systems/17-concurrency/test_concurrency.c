/*
============================================================
CS From First Principles

Phase 4 — Operating Systems & Networks
Topic 17 — Concurrency

File:
test_concurrency.c

Purpose:
Automated tests for thread synchronisation.

============================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#include "concurrency.h"


static int tests_passed = 0;
static int tests_failed = 0;


static void assert_test(
    int condition,
    const char *name
)
{
    if (condition)
    {
        printf(
            "[PASS] %s\n",
            name
        );

        tests_passed++;
    }
    else
    {
        printf(
            "[FAIL] %s\n",
            name
        );

        tests_failed++;
    }
}


/*
============================================================
Test mutex-protected counter
============================================================
*/

static void test_mutex_counter(void)
{
    SharedCounter counter;


    int initialised =
        counter_init(&counter) == 0;


    assert_test(
        initialised,
        "Mutex counter initialisation"
    );


    if (!initialised)
    {
        return;
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


    assert_test(
        counter.counter == expected,
        "Mutex prevents lost updates"
    );


    counter_destroy(&counter);
}


/*
============================================================
Test semaphore
============================================================
*/

static void test_semaphore(void)
{
    SemaphoreResource resource;


    int initialised =
        semaphore_init(
            &resource,
            1
        ) == 0;


    assert_test(
        initialised,
        "Semaphore initialisation"
    );


    if (!initialised)
    {
        return;
    }


    pthread_t threads[THREAD_COUNT];


    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(
            &threads[i],
            NULL,
            semaphore_worker,
            &resource
        );
    }


    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(
            threads[i],
            NULL
        );
    }


    assert_test(
        resource.value == THREAD_COUNT,
        "Semaphore-controlled resource access"
    );


    semaphore_destroy(&resource);
}


/*
============================================================
Test runner
============================================================
*/

int main(void)
{
    printf("\n");
    printf("========================================\n");
    printf(" Concurrency Test Suite\n");
    printf("========================================\n\n");


    test_mutex_counter();

    test_semaphore();


    printf("\n");
    printf("Results\n");
    printf("--------------------\n");


    printf(
        "Passed: %d\n",
        tests_passed
    );


    printf(
        "Failed: %d\n",
        tests_failed
    );


    if (tests_failed == 0)
    {
        printf(
            "\nAll concurrency tests passed.\n"
        );

        return EXIT_SUCCESS;
    }


    printf(
        "\nSome concurrency tests failed.\n"
    );


    return EXIT_FAILURE;
}