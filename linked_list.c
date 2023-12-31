#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}*node;

node createNode(int value){
    node ptr = malloc(sizeof(struct Node));
    ptr -> data = value;
    ptr -> next = NULL;

    return ptr;
}

void linkNode(node currentNode, node nextNode){
    currentNode -> next = nextNode;
}

node insertAtFirst(node head, int value){
    node newNode = createNode(value);

    newNode -> next = head;
    return newNode;
}

void insertAtEnd(node head, int value){
    node newNode = createNode(value),
    ptr = head;

    while(ptr -> next != NULL){
        ptr = head -> next;
    }

    ptr -> next = newNode;
    newNode -> next = NULL;
}

void insertAfterNode(node currentNode, int value){
    node newNode = createNode(value);
    
    newNode -> next = currentNode -> next;
    currentNode -> next =  newNode;
}

void insertAtIndex(node head, int index, int value){
    node newNode = createNode(value),
    ptr = head;
    int i = 0;

    while(i < index - 1){
        if(ptr == NULL){
            printf("Index not found\n");
            return;
        }
        ptr = ptr -> next;
        i++;
    }

    newNode -> next = ptr -> next;
    ptr -> next = newNode;
}


void displayData(node head){
    printf("Elements: ");
    while(head != NULL){
        printf("%d ", head -> data);
        head = head -> next;
    }
    printf("\n");
}

void freeList(node head){
    node tempHead = head;
    while(head != NULL){
        tempHead = head;
        head = head -> next;
        free(tempHead);
    }
}

int main(){
    node head = createNode(1);
    node second = createNode(2);
    node third = createNode(3);
    node forth = createNode(4);

    linkNode(head, second);
    linkNode(second, third);
    linkNode(third, forth);
    linkNode(forth, NULL);

    displayData(head);

    // head = insertAtFirst(head, 10);
    // insertAtEnd(head, 10);
    // insertAfterNode(second, 10);
    insertAtIndex(head, 1, 10);

    displayData(head);

    freeList(head);
    return 0;
}