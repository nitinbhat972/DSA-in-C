#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct Person{
    char name[MAX_NAME];
    int age;
}person;

typedef struct Node{
    person * data;
    struct Node * next;
}node;

node * hashTable[TABLE_SIZE];

size_t hashFunc(char * name){
    size_t length = strlen(name);
    size_t hashValue = 0;

    for (size_t i = 0; i < length; i++){
        hashValue += name[i];
        hashValue = (hashValue * name[i]) % TABLE_SIZE;
    }

    return hashValue;
}

void initHashTable(){
    for(size_t i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
}

void printHashTable(){
    for(size_t i = 0; i < TABLE_SIZE; i++){
        node * currentNode = hashTable[i];
        printf("%d: ", i);
        
        if(currentNode == NULL){
            printf("---\n");
        }
        else{
            while(currentNode != NULL){
                printf("%s -> ", currentNode -> data -> name);
                currentNode = currentNode -> next;
            }
            printf("NULL\n");
        }
    }
}

person * createNode(char * name, int age){
    person * newNode = malloc(sizeof(person));

    if(newNode == NULL){
        printf("Error allocating memory\n");
        exit(EXIT_FAILURE);
    }

    strcpy(newNode -> name, name);
    newNode -> age = age;

    return newNode;
}

bool insertInHash(person * p){
    size_t index = hashFunc(p -> name);
    if(p == NULL) return false;

    node * newNode = malloc(sizeof(node));
    newNode -> data = p;
    newNode -> next = NULL;

    if(hashTable[index] == NULL){
        hashTable[index] = newNode;
    }
    else{
        node * currentNode = hashTable[index];
        while(currentNode -> next != NULL){
            currentNode = currentNode -> next;
        }
        currentNode -> next = newNode;
    }
    return true;
}

person * findInHash(char * name){
    size_t index = hashFunc(name);

    node * currentNode = hashTable[index];

    while(currentNode != NULL){
        if(strncmp(currentNode -> data -> name, name, MAX_NAME) == 0) return currentNode -> data;
        currentNode = currentNode -> next;
    }

    return NULL;
}

person * deleteInHash(char * name){
    size_t index = hashFunc(name);

    node * currentNode = hashTable[index];
    node * prevNode = NULL;

    while(currentNode != NULL){
        if(strncmp(currentNode -> data -> name, name, MAX_NAME) == 0){
            if(prevNode == NULL){
                hashTable[index] = currentNode -> next;
            }
            else{
                prevNode -> next = currentNode -> next;
            }
            person * deletedPerson = currentNode -> data;
            free(currentNode);
            return deletedPerson;
        }
        prevNode = currentNode;
        currentNode = currentNode -> next;
    }

    return NULL;
}


int main(){
    initHashTable();
    // printHashTable();
    
    // printf("-------------------------\n");


    person *jacob = createNode("Jacob", 42);
    person *kate = createNode("Kate", 12);
    person *john = createNode("John", 35);
    person *sarah = createNode("Sarah", 28);
    person *michael = createNode("Michael", 50);
    person *emily = createNode("Emily", 22);
    person *david = createNode("David", 40);
    person *anna = createNode("Anna", 30);
    person *lucas = createNode("Lucas", 18);
    person *olivia = createNode("Olivia", 25);
    person *daniel = createNode("Daniel", 33);

    insertInHash(jacob);
    insertInHash(kate);
    insertInHash(john);
    insertInHash(sarah);
    insertInHash(michael);
    insertInHash(emily);
    insertInHash(david);
    insertInHash(anna);
    insertInHash(lucas);
    insertInHash(olivia);
    insertInHash(daniel);


    printHashTable();

    // person *temp = findInHash("Anna");
    
    // if(temp == NULL){
    //     printf("Not found\n");
    // }
    // else{
    //     printf("%s found\n", temp -> name);
    // } 

    // person * tempd = deleteInHash("David");

    // if(tempd == NULL){
    //     printf("Data not found to be deleted\n");
    // }
    // else{
    //     printf("Deleted %s\n", tempd -> name);
    // }

    // printHashTable();

    return 0;
}