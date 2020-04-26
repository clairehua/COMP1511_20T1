// header file
// prototypes
// typedefs


typedef struct queueInternals *Queue;

// adds a new item to the end of the Queue q
void enqueue(Queue q, int item);

// takes the first item out of the queue and returns the value of the item
int dequeue(Queue q);

// makes a new Queue
Queue newQueue(void);
