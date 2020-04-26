// implementation of the queue ADT

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


struct queueInternals {
    struct queueNode *front;
    struct queueNode *back;
};

struct queueNode {
    int data;
    struct queueNode *next;
};


// make and return a new queue
Queue newQueue(void){
    Queue new = malloc(sizeof(struct queueInternals));
    if (new == NULL) {
        printf("No memory for new queue\n");
        exit(1);
    }
    new->front = NULL;
    new->back = NULL;
    return new;
}

//Remove a queueNode from the beginning of the list (at the start) and return
// the value of data at the start node
void enqueue(Queue q, int item) {
    // make a new node for item
    struct queueNode *newNode = malloc(sizeof(struct queueNode));
    newNode->data = item;
    newNode->next = NULL;
    
    
    // empty list
    if (q->front == NULL) {
        q->front = newNode;
        q->back = newNode;
        return;
    }
    
    // general case
    q->back->next = newNode;
    q->back = q->back->next;
    return;
}

//Remove a queueNode from the beginning of the list (at the start) and return
// the value of data at the start node
int dequeue(Queue q){
    // edge case (base cases)
    if (q->front == NULL) {
        printf("Queue is empty!!! Can't dequeue!\n");
        exit(1);
    }
    
    // general case
    // keep track of the first node
    struct queueNode *tmp = q->front;
    q->front = q->front->next;
    
    int data = tmp->data;
    free(tmp);
    
    return data;
}







