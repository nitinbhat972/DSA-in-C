#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}*node;

typedef struct Queue{
    struct Node *front, *rear;
}*queue;

int isEmpty(queue q){
    return q -> rear == NULL;
}

void enqueue(queue q, int value){
    node newNode = malloc(sizeof(struct Node));
    newNode -> data = value;

    if(isEmpty(q)){
        q -> rear = q -> front = newNode;
    }
    else{
        q -> rear -> next = newNode;
        q -> rear = newNode;
    }
}

int dequeue(queue q){
    if(isEmpty(q)){
        printf("The queue is empty\n");
        return 0;
    }
    int removed = q -> front -> data;
    node tempFront = q -> front;

    if(q -> front == q -> rear){
        q -> front = q -> rear = NULL;
    }
    else{
        q -> front = q -> front -> next;
    }
    free(tempFront);
    return removed;
}

void showData(queue q){
    node ptr = q -> front;
    printf("Elements: ");
    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}


int main(){
    queue q = malloc(sizeof(struct Queue));
    q -> front = q -> rear = NULL;

    enqueue(q, 10);
    enqueue(q, 11);
    enqueue(q, 12);
    enqueue(q, 13);
    enqueue(q, 14);

    showData(q);

    dequeue(q);

    showData(q);

    return 0;
}