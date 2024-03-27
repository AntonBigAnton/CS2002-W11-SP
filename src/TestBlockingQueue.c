/*
 * TestBlockingQueue.c
 *
 * Very simple unit test file for BlockingQueue functionality.
 *
 */

#include <stdio.h>
#include <stddef.h>

#include "BlockingQueue.h"
#include "myassert.h"


#define DEFAULT_MAX_QUEUE_SIZE 20

/*
 * The queue to use during tests
 */
static BlockingQueue *queue;

/*
 * The number of tests that succeeded
 */
static int success_count = 0;

/*
 * The total number of tests run
 */
static int total_count = 0;


/*
 * Setup function to run prior to each test
 */
void setup(){
    queue = new_BlockingQueue(DEFAULT_MAX_QUEUE_SIZE);
    total_count++;
}

/*
 * Teardown function to run after each test
 */
void teardown(){
    BlockingQueue_destroy(queue);
}

/*
 * This function is called multiple times from main for each user-defined test function
 */
void runTest(int (*testFunction)()) {
    setup();

    if (testFunction()) success_count++;

    teardown();
}


/*
 * Two sample user-defined tests included below.
 * You will have to write many more tests.
 *
 * Each test function should return TEST_SUCCESS at the end.
 * Test functions can contain more than one assertion.
 *
 * If any assertion fails, the function name and line number
 * will be printed and the test will return a failure value.
 *
 * You will have to call runTest on your test functions in main below.
 */


/*
 * Checks that the BlockingQueue constructor returns a non-NULL pointer.
 */
int newQueueIsNotNull() {
    assert(queue != NULL);
    return TEST_SUCCESS;
}

/*
 * Checks that the size of an empty blocking queue is 0.
 */
int newQueueSizeZero() {
    assert(BlockingQueue_size(queue) == 0);
    return TEST_SUCCESS;
}

/*
 * Write more of your own test functions below (such as enqOneElement, enqAndDeqOneElement, ...)
 * to help you verify correctness of your BlockingQueue.
 */

/*
 * Checks that a new queue is empty.
 */
int newQueueIsEmpty() {
    assert(BlockingQueue_isEmpty(queue));
    return TEST_SUCCESS;
}

/*
 * Checks that a non-NULL element can be enqueued to an empty queue.
 */
int enqOneElement() {
    int one = ONE;
    assert(BlockingQueue_enq(queue, &one));
    return TEST_SUCCESS;
}

/*
 * Checks that the queue is not empty after enqueueing an element.
 */
int enqNotEmpty() {
    int one = ONE;
    BlockingQueue_enq(queue, &one);
    assert(BlockingQueue_isEmpty(queue) == false);
    return TEST_SUCCESS;
}

/*
 * Checks that the size of the queue is 1 after enqueueing an element to an empty queue.
 */
int enqSize() {
    int one = ONE;
    BlockingQueue_enq(queue, &one);
    assert(BlockingQueue_size(queue) == 1);
    return TEST_SUCCESS;
}

/*
 * Checks that an element can be enqueued and dequeued to an empty queue.
 */
int enqAndDeqOneElement() {
    int one = ONE;
    BlockingQueue_enq(queue, &one);
    assert(BlockingQueue_deq(queue) == &one);
    return TEST_SUCCESS;
}

/*
 * Checks that the size of the queue is increased by 1 after enqueueing an element.
 */
int enqMultipleElements() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    int size = BlockingQueue_size(queue);
    BlockingQueue_enq(queue, &zero);
    assert(BlockingQueue_size(queue) == size+1);
    return TEST_SUCCESS;
}

/*
 * Checks that multiple elements can be enqueued and dequeued (testing for the first element).
 */
int enqAndDeqFirstElement() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    assert(BlockingQueue_deq(queue) == &one);
    return TEST_SUCCESS;
}

/*
 * Checks that multiple elements can be enqueued and dequeued (testing for the last element).
 */
int enqAndDeqLastElement() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    BlockingQueue_deq(queue);
    assert(BlockingQueue_deq(queue) == &zero);
    return TEST_SUCCESS;
}

/*
 * Checks that the size of the queue is 0 after dequeueing the final element.
 */
int deqSize() {
    int one = ONE;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_deq(queue);
    assert(BlockingQueue_size(queue) == 0);
    return TEST_SUCCESS;
}

/*
 * Checks that the size of the queue is reduced by 1 after dequeueing an element.
 */
int deqMultipleElements() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    int size = BlockingQueue_size(queue);
    BlockingQueue_deq(queue);
    assert(BlockingQueue_size(queue) == size-1);
    return TEST_SUCCESS;
}

/*
 * Checks that the queue is empty after dequeueing the final element.
 */
int deqToEmpty() {
    int one = ONE;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_deq(queue);
    assert(BlockingQueue_isEmpty(queue));
    return TEST_SUCCESS;
}

/*
 * Checks that no element can be enqueued to a full queue.
 */
int enqFullQueue() {
    int one = ONE;
    for (int i = 0; i < 20; i++) {
        BlockingQueue_enq(queue, &one);
    }
    assert(BlockingQueue_enq(queue, &one) == false);
    return TEST_SUCCESS;
}

/*
 * Checks that no NULL element can be enqueued.
 */
int enqNullElement() {
    assert(BlockingQueue_enq(queue, NULL) == false);
    return TEST_SUCCESS;
}

/*
 * Checks that dequeueing from an empty queue returns NULL.
 */
int deqFromEmpty() {
    assert(BlockingQueue_deq(queue) == NULL);
    return TEST_SUCCESS;
}

/*
 * Checks that clearing a queue makes it empty.
 */
int clearToEmpty() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    BlockingQueue_clear(queue);
    assert(BlockingQueue_isEmpty(queue));
    return TEST_SUCCESS;
}

/*
 * Checks that clearing a queue sets its size to 0.
 */
int clearSize() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    BlockingQueue_clear(queue);
    assert(BlockingQueue_size(queue) == 0);
    return TEST_SUCCESS;
}

/*
 * Checks that an element can be enqueued after clearing the queue.
 */
int enqAfterClearing() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    BlockingQueue_clear(queue);
    assert(BlockingQueue_enq(queue, &one));
    return TEST_SUCCESS;
}

/*
 * Checks that the size of the queue is 1 after enqueueing an element to a cleared queue.
 */
int enqClearedSize() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    BlockingQueue_clear(queue);
    BlockingQueue_enq(queue, &one);
    assert(BlockingQueue_size(queue) == 1);
    return TEST_SUCCESS;
}

/*
 * Checks that an element can be enqueued and dequeued after clearing the queue.
 */
int enqAndDeqAfterClearing() {
    int one = ONE;
    int zero = ZERO;
    BlockingQueue_enq(queue, &one);
    BlockingQueue_enq(queue, &zero);
    BlockingQueue_clear(queue);
    BlockingQueue_enq(queue, &one);
    assert(BlockingQueue_deq(queue) == &one);
    return TEST_SUCCESS;
}

/*
 * Main function for the BlockingQueue tests which will run each user-defined test in turn.
 */

int main() {
    runTest(newQueueIsNotNull);
    runTest(newQueueSizeZero);
    /*
     * you will have to call runTest on all your test functions above, such as
     *
     * runTest(enqOneElement);
     * runTest(enqAndDeqOneElement);
     *
     */

    runTest(newQueueIsEmpty);
    runTest(enqOneElement);
    runTest(enqNotEmpty);
    runTest(enqSize);
    runTest(enqAndDeqOneElement);
    runTest(enqMultipleElements);
    runTest(enqAndDeqFirstElement);
    runTest(enqAndDeqLastElement);
    runTest(deqSize);
    runTest(deqMultipleElements);
    runTest(deqToEmpty);
    //runTest(enqFullQueue);
    runTest(enqNullElement);
    //runTest(deqFromEmpty);
    runTest(clearToEmpty);
    runTest(clearSize);
    runTest(enqAfterClearing);
    runTest(enqClearedSize);
    runTest(enqAndDeqAfterClearing);

    printf("\nBlockingQueue Tests complete: %d / %d tests successful.\n----------------\n", success_count, total_count);

}
