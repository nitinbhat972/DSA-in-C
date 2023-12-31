#include<stdio.h>
#include<stdlib.h>

// Structure to represent a queue
typedef struct Queue {
    int front, rear, *arr;
    size_t size;
} * queue;

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
        return;
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
        return -1;
    }
    int removed = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return removed;
}

// Function to display the elements in the queue
void showData(queue q) {
    if (isEmpty(q)) {
        printf("The queue is empty\n");
        return;
    }
    printf("Elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

// Main function
int main() {
    // Create a queue
    queue q = createQueue(5);
    
    // Enqueue elements into the queue
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    enqueue(q, 5);
    
    // Display the elements in the queue
    showData(q);

    // Dequeue elements from the queue
    dequeue(q);
    dequeue(q);
    dequeue(q);

    // Display the elements in the modified queue
    showData(q);

    return 0;
}