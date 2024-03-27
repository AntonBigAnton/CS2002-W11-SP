/*
 * BlockingQueue.c
 *
 * Fixed-size generic array-based BlockingQueue implementation.
 *
 */

#include <stddef.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#include "BlockingQueue.h"

/*
 * The functions below all return default values and don't work.
 * You will need to provide a correct implementation of the BlockingQueue module interface as documented in BlockingQueue.h.
 */


BlockingQueue *new_BlockingQueue(int max_size) {
    // Initialise the blocking queue
    BlockingQueue* this = malloc(sizeof(BlockingQueue));

    // Initialise the blocking queue's Queue object and maximum capacity
    (*this).queue = new_Queue(max_size);
    (*this).capacity = max_size;

    // Initialise the blocking queue's mutexes
    pthread_mutex_init(&(*this).mutex_enq, NULL);
    pthread_mutex_init(&(*this).mutex_deq, NULL);

    // Initialise the blocking queue's semaphores
    sem_init(&(*this).sem_enq, ZERO, max_size);
    sem_init(&(*this).sem_deq, ZERO, ZERO);

    return this;
}

bool BlockingQueue_enq(BlockingQueue* this, void* element) {
    sem_wait(&(*this).sem_enq);
    pthread_mutex_lock(&(*this).mutex_enq);
    bool value = Queue_enq((*this).queue, element);
    pthread_mutex_unlock(&(*this).mutex_enq);
    sem_post(&(*this).sem_deq);
    return value;
}

void* BlockingQueue_deq(BlockingQueue* this) {
    sem_wait(&(*this).sem_deq);
    pthread_mutex_lock(&(*this).mutex_deq);
    void* value = Queue_deq((*this).queue);
    pthread_mutex_unlock(&(*this).mutex_deq);
    sem_post(&(*this).sem_enq);
    return value;
}

int BlockingQueue_size(BlockingQueue* this) {
    return Queue_size((*this).queue);
}

bool BlockingQueue_isEmpty(BlockingQueue* this) {
    return Queue_isEmpty((*this).queue);
}

void BlockingQueue_clear(BlockingQueue* this) {
    Queue_clear((*this).queue);
}

void BlockingQueue_destroy(BlockingQueue* this) {
    // Destroy both mutexes
    pthread_mutex_destroy(&(*this).mutex_enq);
    pthread_mutex_destroy(&(*this).mutex_deq);

    // Destroy both semaphores
    sem_destroy(&(*this).sem_enq);
    sem_destroy(&(*this).sem_deq);

    // Destroy the Queue object
    Queue_destroy((*this).queue);
    
    // Free the memory allocated for this blocking queue
    free(this);
}
