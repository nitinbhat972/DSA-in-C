#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}node;

node * createNode(int value){
    node * newNode = malloc(sizeof(node));

    if(newNode == NULL){
        printf("Node creation failed\n");
        return NULL;
    }

    newNode -> data = value;
    newNode -> next = NULL;

    return newNode;
}

void linkNodes(node * prevNode, node * nextNode){
    prevNode -> next = nextNode;
}

int isEmpty(node * head){
    return head == NULL ? 1: 0;
}

void showList(node * head){
    if(isEmpty(head)){
        fprintf(stderr, "[*] Nothing to show the linked list is empty\n");
        return;
    }
    node * temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

void insertAtHead(node ** head, int value){
    node * newNode = createNode(value);
    newNode -> next = *head;
    *head = newNode;    
}

void insertAfterNode(node * prevNode, int value){
    node * newNode = createNode(value);
    newNode -> next = prevNode -> next;
    prevNode -> next = newNode;
}

void insertAtEnd(node ** head, int value){
    node * newNode = createNode(value);
    node * temp = *head;

    newNode -> data = value;
    newNode -> next = NULL;

    if(temp == NULL){
        *head = newNode;
        return;
    }

    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp -> next = newNode;
}

void deleteSingleNode(node **head) {
    node *temp = *head;
    free(temp);
    *head = NULL;
}


void deleteAtHead(node ** head){
    if(isEmpty(*head)){
        fprintf(stderr, "[*] Nothing to delete the linked list is emtpy\n");
        return;
    }

    node * temp = *head;

    *head = (*head) -> next;
    free(temp);
}

void deleteAtEnd(node ** head){
    if(isEmpty(*head)){
        fprintf(stderr, "[*] Nothing to delete the linked list is emtpy\n");
        return;
    }
    node * temp = *head,
    * currentNode = NULL;

    if(temp -> next == NULL){
        deleteSingleNode(head);
        return;
    }
    while(temp -> next != NULL){
        currentNode = temp;
        temp = temp -> next;
    }
    currentNode -> next = NULL;
    free(temp);
}

void deleteUsingNode(node ** head, node * nodeToDelete){
    if(isEmpty(*head)){
        fprintf(stderr, "[*] Nothing to delete the linked list is emtpy\n");
        return;
    }
    node * temp = *head,
    * currentNode = NULL;
    
    if(nodeToDelete == NULL){
        fprintf(stderr, "[*] Invalid node to delete\n");
    }

    if(nodeToDelete == *head){
        deleteAtHead(head);
        return;
    }

    while(temp != NULL){
        if(temp == nodeToDelete){
            currentNode -> next = temp -> next;
            free(temp);
            return;
        }
        currentNode = temp;
        temp = temp -> next;
    }
    printf("[*] Node not found\n");
}

void freeList(node * head){
    node * temp;
    while(head != NULL){
        temp = head;
        head = head -> next;
        free(temp);
    }
}

int main(){
    node * head = createNode(1);
    node * second = createNode(2);
    node * third = createNode(3);
    node * forth = createNode(4);
    node * fifth = createNode(4);

    linkNodes(head, second);
    linkNodes(second, third);
    linkNodes(third, forth);

    showList(head);

    // insertAtHead(&head, 0);
    // insertAtEnd(&head, 5);
    // insertAfterNode(second, 10);
    // deleteAtHead(&head);
    // deleteAtEnd(&head);
    // deleteUsingNode(&head, second);
    showList(head);    

    freeList(head);
    return 0;
}