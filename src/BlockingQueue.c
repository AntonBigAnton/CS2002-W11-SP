/*
 * BlockingQueue.c
 *
 * Fixed-size generic array-based BlockingQueue implementation.
 *
 */

#include <stddef.h>
#include <stdlib.h>

#include "BlockingQueue.h"

/*
 * The functions below all return default values and don't work.
 * You will need to provide a correct implementation of the BlockingQueue module interface as documented in BlockingQueue.h.
 */


BlockingQueue *new_BlockingQueue(int max_size) {
    BlockingQueue* this = malloc(sizeof(BlockingQueue));
    (*this).queue = new_Queue(max_size);
    (*this).capacity = max_size;
    return this;
}

bool BlockingQueue_enq(BlockingQueue* this, void* element) {
    if (BlockingQueue_size(this) == (*this).capacity || element == NULL) {
        // Block the thread until an element can be enqueued
        return false;
    }
    else {
        Queue_enq((*this).queue, element);
        return true;
    }
}

void* BlockingQueue_deq(BlockingQueue* this) {
    if (BlockingQueue_isEmpty(this)) {
        // Block the thread until an element can be dequeued
        return NULL;
    }
    else {
        return Queue_deq((*this).queue);
    }
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
    Queue_destroy((*this).queue);
    free(this);
}
