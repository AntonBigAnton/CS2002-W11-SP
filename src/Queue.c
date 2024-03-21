/*
 * Queue.c
 *
 * Fixed-size generic array-based Queue implementation.
 *
 */

#include <stddef.h>

#include "Queue.h"

/*
 * The functions below all return default values and don't work.
 * You will need to provide a correct implementation of the Queue module interface as documented in Queue.h.
 */


Queue *new_Queue(int max_size) {
    return NULL;
}

bool Queue_enq(Queue* this, void* element) {
    return false;
}

void* Queue_deq(Queue* this) {
    return NULL;
}

int Queue_size(Queue* this) {
    return -1;
}

bool Queue_isEmpty(Queue* this) {
    return false;
}

void Queue_clear(Queue* this) {
}

void Queue_destroy(Queue* this) {
}
