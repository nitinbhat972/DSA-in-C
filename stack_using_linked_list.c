#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}*node;

typedef struct Stack{
    struct Node * top;
}*stack;

int isEmpty(stack s){
    return s -> top == NULL;
}

void push(stack s, int value){
    node newNode = malloc(sizeof(struct Node));
    newNode -> data = value;
    newNode -> next = s -> top;
    s -> top = newNode;
}

int pop(stack s){
    if(isEmpty(s)){
        printf("The stack is empty\n");
        return 0;
    }
    node tempTop = s -> top;
    int removed = s -> top -> data;
    s -> top = s -> top -> next;
    free(tempTop);

    return removed;
}

int peek(stack s){
    return s -> top -> data;
}

void showData(stack s){
    node ptr = s -> top;
    printf("Elements: ");
    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

int main(){
    stack s = malloc(sizeof(struct Stack));
    s -> top = NULL;

    push(s, 10);
    push(s, 11);
    push(s, 12);
    push(s, 13);

    showData(s);

    pop(s);
    
    showData(s);

    return 0;
}