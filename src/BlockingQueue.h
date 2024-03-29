/*
 * BlockingQueue.h
 *
 * Module interface for a generic fixed-size Blocking Queue implementation.
 *
 */

#ifndef BLOCKING_QUEUE_H_
#define BLOCKING_QUEUE_H_

#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>

#include "Queue.h"

typedef struct BlockingQueue BlockingQueue;

/* You should define your struct BlockingQueue here */
struct BlockingQueue {
    /*
     * A BlockingQueue struct has 6 attributes:
     *      - queue: The blocking queue, represented as a Queue object;
     *      - capacity: The blocking queue's maximum capacity;
     *      - mutex_enq and mutex_deq: The mutexes used to enqueue and dequeue elements respectively;
     *      - sem_enq and sem_deq: The semaphores used before enqueueing and dequeuing elements respectively;
     */
    Queue* queue;
    int capacity;
    pthread_mutex_t mutex_enq, mutex_deq;
    sem_t sem_enq, sem_deq;
};

/*
 * Creates a new BlockingQueue for at most max_size void* elements.
 * Returns a pointer to a new BlockingQueue on success and NULL on failure.
 */
BlockingQueue* new_BlockingQueue(int max_size);

/*
 * Enqueues the given void* element at the back of this Queue.
 * If the queue is full, the function will block the calling thread until there is space in the queue.
 * Returns false when element is NULL and true on success.
 */
bool BlockingQueue_enq(BlockingQueue* this, void* element);

/*
 * Dequeues an element from the front of this Queue.
 * If the queue is empty, the function will block until an element can be dequeued.
 * Returns the dequeued void* element.
 */
void* BlockingQueue_deq(BlockingQueue* this);

/*
 * Returns the number of elements currently in this Queue.
 */
int BlockingQueue_size(BlockingQueue* this);

/*
 * Returns true if this Queue is empty, false otherwise.
 */
bool BlockingQueue_isEmpty(BlockingQueue* this);

/*
 * Clears this Queue returning it to an empty state.
 */
void BlockingQueue_clear(BlockingQueue* this);

/*
 * Destroys this Queue by freeing the memory used by the Queue.
 */
void BlockingQueue_destroy(BlockingQueue* this);

/*
 * Terminates the code, destroys the blocking queue and prints out an error message if an error is detected.
 */
void exit_error(BlockingQueue* this, char* msg);

#endif /* BLOCKING_QUEUE_H_ */
