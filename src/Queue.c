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
    Queue this;
    this.arr = malloc(sizeof(void*)*(max_size + 1));
    this.capacity = max_size;
    this.size = ZERO;
    this.front = ZERO;
    this.rear = -ONE;
    return this*;
}

bool Queue_enq(Queue* this, void* element) {
    if (Queue_size(this) == (*this).capacity || element == NULL) {
        return false;
    }
    else {
        (*this).rear = ((*this).rear + 1)%(*this).capacity;
        (*this).arr[(*this).rear] = element;
        (*this).size++;
        return true;
    }
}

void* Queue_deq(Queue* this) {
    if (Queue_isEmpty(this)) {
        return NULL;
    }
    else {
        void* element = (*this).arr[(*this).front];
        (*this).front = ((*this).front + 1)%(*this).capacity;
        (*this).size--;
        return element;
    }
}

int Queue_size(Queue* this) {
    return (*this).size;
}

bool Queue_isEmpty(Queue* this) {
    if ((*this).size == ZERO) {
        return true;
    }
    else {
        return false;
    }
}

void Queue_clear(Queue* this) {
    (*this).size = ZERO;
    (*this).front = ZERO;
    (*this).rear = -ONE;
}

void Queue_destroy(Queue* this) {
    free((*this).arr);
}
