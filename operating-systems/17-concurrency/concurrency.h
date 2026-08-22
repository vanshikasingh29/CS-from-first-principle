#ifndef CONCURRENCY_H
#define CONCURRENCY_H

#include <pthread.h>
#include <semaphore.h>

#define THREAD_COUNT 4
#define INCREMENTS_PER_THREAD 100000

typedef struct
{
    long counter;
    pthread_mutex_t mutex;
} SharedCounter;

typedef struct
{
    int value;
    sem_t semaphore;
} SemaphoreResource;

/* Mutex-protected counter operations. */
int counter_init(SharedCounter *counter);
void counter_destroy(SharedCounter *counter);

void *increment_counter(void *argument);

/* Semaphore demonstration. */
int semaphore_init(SemaphoreResource *resource, int initial_value);
void semaphore_destroy(SemaphoreResource *resource);

void *semaphore_worker(void *argument);

#endif