#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    struct Node *prev, *next;
    int data;
}*node;

node createNode(int value){
    node ptr = malloc(sizeof(struct Node));
    ptr -> data = value;
    ptr -> prev = NULL;
    ptr -> next = NULL;

    return ptr;
}

void linkNode(node currentNode, node prevNode, node nextNode){
    currentNode -> prev = prevNode;
    currentNode -> next = nextNode;
}

int isNull(node head){
    return head == NULL;
}

node insertAtFirst(node head, int value){
    node newNode = createNode(value);

    if(isNull(head)){
        return newNode;
    }

    head -> prev = newNode;
    newNode->next = head;
    newNode -> prev = NULL;
    return newNode;
}

node insertAtEnd(node head, int value){
    node newNode = createNode(value),
    ptr;

    if(isNull(head)){
        return newNode;
    }

    ptr = head;

    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    ptr -> next = newNode;
    newNode -> next = NULL;
    newNode -> prev = ptr;

    return head;
}

node insertAfterNode(node head, node currentNode, int value){
    node newNode = createNode(value);

    if(isNull(head) && isNull(currentNode)){
        return newNode;
    }

    if(currentNode -> next == NULL){
        node ptr = insertAtEnd(head, value);
        return head;
    }
    if(currentNode == head){
        node ptr = insertAtFirst(head, value);
        return head;
    }

    newNode -> next = currentNode -> next;
    currentNode -> next -> prev = newNode;
    currentNode -> next = newNode;
    newNode -> prev = currentNode;
    
    return head;
}

node insertAtIndex(node head, int index, int value){
    node newNode = createNode(value), 
    ptr = head;
    int i = 0;

    if(index == 0){
        return insertAtFirst(head, value);
    }

    while(ptr != NULL && i < index - 1){
        ptr = ptr->next;
        i++;
    }

    if(ptr == NULL){
        printf("The index not found\n");
        return head;
    }

    newNode -> prev = ptr;
    newNode -> next = ptr -> next;
    ptr -> next -> prev = newNode;
    ptr -> next = newNode;

    return head;
}

node deleteAtFirst(node head){
    node ptr;
    if(isNull(head)){
        printf("The linked list is empty\n");
        return NULL;
    }
    ptr = head -> next;

    head -> next -> prev = NULL;
    free(head);
    return ptr; 
}

node deleteAtEnd(node head){
    node ptr;
    if(isNull(head)){
        printf("The linked list is empty\n");
        return NULL;
    }
    ptr = head;

    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    ptr -> prev -> next = NULL;
    free(ptr);

    return head;
}

node deleteANode(node head, node currentNode){
    if(isNull(head) && isNull(currentNode)){
        printf("The give node is not presentor the linked list is empty\n");
        return NULL;
    }
    if(currentNode == head){
        node ptr = deleteAtFirst(head);
        return ptr;
    }

    if(currentNode -> next == NULL){
        node ptr = deleteAtEnd(head);
        return head;
    }

    currentNode -> prev -> next = currentNode -> next;
    currentNode -> next -> prev = currentNode -> prev;

    free(currentNode);

    return head;
}

node deleteNodeByValue(node head, int value){
    node ptr = head;
    if(isNull(head)){
        printf("The linked list is empty\n");
        return NULL;
    }
    while(ptr != NULL && ptr -> data != value){
        ptr = ptr -> next;
    }
    if(ptr == NULL){
        printf("The node with value with %d not found\n", value);
        return head;
    }

    head = deleteANode(head, ptr);

    return head;
}

node deleteByIndex(node head, int index){
    node ptr;
    int i = 0;
    if(isNull(head)){
        printf("The linked list is empty\n");
        return NULL;
    }

    ptr = head;
    while(ptr != NULL && i != index){
        ptr = ptr -> next;
        i++;
    }

    if(ptr == NULL){
        printf("The index not found\n");
        return head;
    }

    head = deleteANode(head, ptr);

    return head;
}

void showDataForward(node head){
    node ptr;
    if(isNull(head)){
        printf("The linked list is empty\n");
        return;
    }
    ptr = head;
    printf("Elements: ");
    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> next;
    }
    printf("\n");
}

void showDataReverse(node head){
    node ptr;
    if(isNull(head)){
        printf("The linked list is empty\n");
        return;
    }
    ptr = head;
    while(ptr -> next != NULL){
        ptr = ptr -> next;
    }

    printf("Reversed Elements: ");
    while(ptr != NULL){
        printf("%d ", ptr -> data);
        ptr = ptr -> prev;
    }
    printf("\n");
}

void freeList(node head){
   while(head != NULL){
    node temp = head;
    head = head -> next;
    free(temp);
   }
}

int main(){
    node head = createNode(1);
    node second = createNode(2);
    node third = createNode(3);

    linkNode(head, NULL, second);
    linkNode(second, head, third);
    linkNode(third, second, NULL);
    
    showDataForward(head);
    printf("Elements after insertion\n");
    // head = insertAtFirst(head, 10);
    // head = insertAtEnd(head, 10);
    // head = insertAfterNode(head, second, 10);
    head = insertAtIndex(head, 1, 10);
    // head = deleteAtFirst(head);
    // head = deleteAtEnd(head);
    // head = deleteANode(head, third);
    // head = deleteNodeByValue(head, 1);
    // head = deleteByIndex(head, 1);
    showDataForward(head);
    showDataReverse(head);
    freeList(head);

    return 0;
}