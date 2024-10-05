#include <stdio.h>
#include <stdlib.h>

// Structure to represent a queue
typedef struct Queue {
    int front, rear, *arr;
    size_t size;
} * queue;

// Structure to represent a stack using two queues
typedef struct Stack {
    queue q1, q2;
} * stack;

// Function to create a new queue
queue createQueue(size_t size) {
    queue q = malloc(sizeof(struct Queue));
    q->arr = malloc(size * sizeof(int));
    q->front = q->rear = -1;
    q->size = size;
    return q;
}

// Function to check if a queue is full
int isFull(queue q) {
    return q->rear == q->size - 1;
}

// Function to check if a queue is empty
int isEmpty(queue q) {
    return q->rear == -1;
}

// Function to enqueue an element into a queue
void enqueue(queue q, int value) {
    if (isFull(q)) {
        return; // Queue is full, cannot enqueue
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = value;
}

// Function to dequeue an element from a queue
int dequeue(queue q) {
    if (isEmpty(q)) {
        return -1; // Queue is empty, cannot dequeue
    }
    int removed = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return removed;
}

// Function to create a new stack using two queues
stack createStack(size_t size) {
    stack s = malloc(sizeof(struct Stack));
    s->q1 = createQueue(size);
    s->q2 = createQueue(size);
    return s;
}

// Function to push an element onto the stack
void push(stack s, int value) {
    if (isFull(s->q1)) {
        printf("The stack is full. Cannot add %d\n", value);
        return;
    }
    enqueue(s->q1, value);
}

// Function to pop an element from the stack
int pop(stack s) {
    if (isEmpty(s->q1)) {
        printf("The stack is empty\n");
        return -1;
    }
    while (s->q1->front != s->q1->rear) {
        enqueue(s->q2, dequeue(s->q1));
    }
    int poppedItem = dequeue(s->q1);
    queue tempQueue = s->q1;
    s->q1 = s->q2;
    s->q2 = tempQueue;
    return poppedItem;
}

// Function to display the elements in the stack
void showData(stack s) {
    if (isEmpty(s->q1)) {
        printf("The stack is empty\n");
        return;
    }
    printf("Elements: ");
    for (int i = s->q1->front; i <= s->q1->rear; i++) {
        printf("%d ", s->q1->arr[i]);
    }
    printf("\n");
}

int main() {
    stack s = createStack(5);
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);

    showData(s);

    printf("%d\n", pop(s));
    printf("%d\n", pop(s));

    showData(s);

    return 0;
}