#include "queue.h"
#include <stdio.h>
#define NUMS 5

int main(void) {

    printf("Making a queue.\n");
    Queue myQ = newQueue();
    int i = 0;
    // add items numbers 0 to 4 into our queue
    while (i < NUMS) {
        printf("Adding %d to the queue.\n", i);
        enqueue(myQ, i);
        i++;
    }

    // dequeue everything
    i = 0;
    while (i < NUMS) {
        int result = dequeue(myQ);
        printf("Got %d from the queue.\n", result);
        i++;
    }

    // try to dequeue an empty queue
    int result = dequeue(myQ);
    printf("We shouldn't reach here... if we do we got %d\n", result);

    return 0;
}
