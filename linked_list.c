#include<stdio.h>
#include<stdlib.h>

// Define a struct for a node in the linked list
typedef struct Node {
    int data;
    struct Node* next;
} *node;

// Function to create a new node with the given value
node createNode(int value) {
    node ptr = malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->next = NULL;

    return ptr;
}

// Function to link the current node to the next node
void linkNode(node currentNode, node nextNode) {
    currentNode->next = nextNode;
}

// Function to insert a node at the beginning of the list
node insertAtFirst(node head, int value) {
    node newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the list
void insertAtEnd(node head, int value) {
    node newNode = createNode(value);
    node ptr = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = NULL;
}

// Function to insert a node after a given node
void insertAfterNode(node currentNode, int value) {
    node newNode = createNode(value);
    newNode->next = currentNode->next;
    currentNode->next = newNode;
}

// Function to insert a node at a specific index
void insertAtIndex(node head, int index, int value) {
    node newNode = createNode(value);
    node ptr = head;
    int i = 0;

    while (i < index - 1) {
        if (ptr == NULL) {
            printf("Index not found\n");
            return;
        }
        ptr = ptr->next;
        i++;
    }

    newNode->next = ptr->next;
    ptr->next = newNode;
}

// Function to delete the first node in the list
node deleteAtFirst(node head) {
    node newHead = head->next;
    free(head);
    return newHead;
}

// Function to delete the last node in the list
void deleteAtLast(node head) {
    node ptr = head->next;
    node prev = head;

    while (ptr->next != NULL) {
        ptr = ptr->next;
        prev = prev->next;
    }

    node tempNode = ptr;
    prev->next = NULL;
    free(tempNode);
}

// Function to delete a specific node in the list
node deleteByNode(node head, node delNode) {
    node ptr = head;

    if (delNode == ptr) {
        node newHead = ptr->next;
        free(ptr);
        return newHead;
    }

    while (ptr->next != delNode) {
        ptr = ptr->next;
    }

    ptr->next = delNode->next;
    free(delNode);

    return head;
}

// Function to delete a node with a specific value in the list
node deleteByValue(node head, int value) {
    node ptr = head;
    node prev = NULL;

    if (ptr->data == value) {
        node newHead = ptr->next;
        free(ptr);
        return newHead;
    }

    while (ptr != NULL && ptr->data != value) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("No node with value %d found\n", value);
        return head;
    }

    prev->next = ptr->next;
    free(ptr);

    return head;
}

// Function to delete a node at a specific index in the list
node deleteAtIndex(node head, int index) {
    node ptr = head;
    node prev = NULL;
    int i = 0;

    if (i == index) {
        node newHead = ptr->next;
        free(ptr);
        return newHead;
    }

    while (ptr != NULL && i < index) {
        prev = ptr;
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL) {
        printf("Index out of bond\n");
        return NULL;
    }

    prev->next = ptr->next;
    free(ptr);

    return head;
}

// Function to display the elements of the linked list
void displayData(node head) {
    printf("Elements: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the linked list
void freeList(node head) {
    node tempHead = head;
    while (head != NULL) {
        tempHead = head;
        head = head->next;
        free(tempHead);
    }
}

int main() {
    // Create a linked list with four nodes
    node head = createNode(1);
    node second = createNode(2);
    node third = createNode(3);
    node fourth = createNode(4);

    linkNode(head, second);
    linkNode(second, third);
    linkNode(third, fourth);
    linkNode(fourth, NULL);

    // Display the original list
    displayData(head);

    // Uncomment and use different functions to test different operations
    // head = insertAtFirst(head, 10);
    // insertAtEnd(head, 10);
    // insertAfterNode(second, 10);
    // insertAtIndex(head, 1, 10);

    // head = deleteAtFirst(head);
    // deleteAtLast(head);
    // head = deleteByNode(head, second);
    // head = deleteByValue(head, 3);
    // head = deleteAtIndex(head, 0);

    // Display the modified list
    displayData(head);

    // Free the memory allocated for the linked list
    freeList(head);
    return 0;
}