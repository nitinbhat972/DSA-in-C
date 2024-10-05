#include<stdio.h>
#include<stdlib.h>

// Define the structure for the stack
typedef struct Stack {
    int top, *arr;
    size_t size;
} *stack;

// Function to create a new stack with the given size
stack createStack(size_t size) {
    stack s = malloc(sizeof(struct Stack));
    s->arr = malloc(size * sizeof(int));
    s->top = -1;  // Initialize top to -1 as the stack is empty
    s->size = size;

    return s;
}

// Function to check if the stack is full
int isFull(stack s) {
    return s->top == s->size - 1;
}

// Function to check if the stack is empty
int isEmpty(stack s) {
    return s->top == -1;
}

// Function to push an element onto the stack
void push(stack s, int value) {
    if (isFull(s)) {
        printf("The stack is full. Cannot add %d\n", value);
        return;
    }
    s->arr[++s->top] = value;
}

// Function to pop an element from the stack
int pop(stack s) {
    if (isEmpty(s)) {
        printf("The stack is empty\n");
        return -1;
    }
    int poppedItem = s->arr[s->top--];
    return poppedItem;
}

// Function to display the elements in the stack
void displayItems(stack s) {
    if (isEmpty(s)) {
        printf("The stack is empty\n");
        return;
    }
    printf("Elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main() {
    // Create a stack with a size of 5
    stack s = createStack(5);

    // Push elements onto the stack
    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);
    push(s, 5);

    // Display the elements in the stack
    displayItems(s);

    // Pop elements from the stack
    pop(s);
    pop(s);
    pop(s);

    // Display the elements in the stack after popping
    displayItems(s);

    return 0;
}
