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

node deleteAtFirst(node head){
    node newHead = head -> next;
    free(head);

    return newHead;
}

void deleteAtLast(node head){
    node ptr = head -> next,
    prev = head;

    while(ptr -> next != NULL){
        ptr = ptr -> next;
        prev = prev -> next;
    }

    node tempNode = ptr;
    prev -> next = NULL;

    free(tempNode);
}

node deleteByNode(node head, node delNode){
    node ptr = head;

    if(delNode == ptr){
        node newHead = ptr -> next;
        return newHead;
        free(delNode);
    }

    while(ptr -> next != delNode){
        ptr = ptr -> next;
    }

    ptr -> next = delNode -> next;

    free(delNode);

    return head;
}

node deleteByValue(node head, int value){
    node ptr = head,
    prev = NULL;

    if(ptr -> data == value){
        node newHead = ptr -> next;
        free(ptr);
        return newHead;
    }

    while(ptr != NULL && ptr -> data != value){        
        prev = ptr;
        ptr = ptr -> next;
    }

    if(ptr == NULL){
        printf("No node of value %d found\n", value);
        return head;
    }
    prev -> next = ptr -> next;
    
    free(ptr);
    
    return head;
}

node deleteAtIndex(node head, int index){
    node ptr = head,
    prev = NULL;
    int i = 0;
    
    if(i == index){
        node newHead = ptr -> next;
        free(ptr);
        return newHead;
    }

    while(ptr != NULL && i < index){
        prev = ptr;
        ptr = ptr -> next;
        i++;
    }

    if(ptr == NULL){
        printf("Index out of bond\n");
        return NULL;
    }

    prev -> next = ptr -> next;
    free(ptr);

    return head;
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
    // insertAtIndex(head, 1, 10);

    // head = deleteAtFirst(head);
    // deleteAtLast(head);
    // head = deleteByNode(head, second);
    // head = deleteByValue(head, 3);
    head = deleteAtIndex(head, 0);

    displayData(head);

    freeList(head);
    return 0;
}