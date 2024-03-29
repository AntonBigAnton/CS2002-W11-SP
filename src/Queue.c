/*
 * Queue.c
 *
 * Fixed-size generic array-based Queue implementation.
 *
 */

#include <stddef.h>
#include <stdlib.h>

#include "Queue.h"

/*
 * The functions below all return default values and don't work.
 * You will need to provide a correct implementation of the Queue module interface as documented in Queue.h.
 */


Queue *new_Queue(int max_size) {
    // Create the pointer to the new queue using malloc
    Queue* this = malloc(sizeof(Queue));

    /*
     * Initialise all 5 Queue attributes:
     *      - arr is initialised as an empty array of max_size + 1 void* elements;
     *      - capacity is set to the inputted max_size;
     *      - size is set to 0;
     *      - front is set to 0;
     *      - rear is set to -1.
     */
    (*this).arr = malloc(sizeof(void*)*(max_size + 1));
    (*this).capacity = max_size;
    (*this).size = ZERO;
    (*this).front = ZERO;
    (*this).rear = -ONE;

    // Return the pointer to the new queue
    return this;
}

bool Queue_enq(Queue* this, void* element) {
    // Return false if the queue is full, or if the enqueued element is NULL
    if (Queue_size(this) == (*this).capacity || element == NULL) {
        return false;
    }
    // Otherwise, enqueue the element to the back of the queue and return true
    else {
        (*this).rear = ((*this).rear + 1)%(*this).capacity; // Increase the rear by 1 (mod the capacity of the queue)
        (*this).arr[(*this).rear] = element; // Enqueue the element to the back of the queue
        (*this).size++; // Increase the size by 1
        return true;
    }
}

void* Queue_deq(Queue* this) {
    // Return NULL if the queue is empty
    if (Queue_isEmpty(this)) {
        return NULL;
    }
    // Otherwise, dequeue the element at the front of the queue and return it
    else {
        void* element = (*this).arr[(*this).front];
        (*this).front = ((*this).front + 1)%(*this).capacity; // Increase the front by 1 (mod the capacity of the queue)
        (*this).size--; // Reduce the size by 1
        return element;
    }
}

int Queue_size(Queue* this) {
    return (*this).size; // The number of elements currently in this queue
}

bool Queue_isEmpty(Queue* this) {
    // The queue is empty if the number of elements currently in it is 0 <=> its size is 0
    if ((*this).size == ZERO) {
        return true; // Return true if the queue is empty
    }
    else {
        return false; // Otherwise return false
    }
}

void Queue_clear(Queue* this) {
    /*
     * To clear the queue:
     *      - Reset its size to 0;
     *      - Reset its front to 0;
     *      - Reset its rear to -1.
     */
    (*this).size = ZERO;
    (*this).front = ZERO;
    (*this).rear = -ONE;
}

void Queue_destroy(Queue* this) {
    // The queue uses memory twice: once for the array to store the elements, and once for itself
    free((*this).arr); // Free the memory used for the array
    free(this); // Free the memory used for itself
}
