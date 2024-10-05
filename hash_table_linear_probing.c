#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MAX_NAME 256
#define TABLE_SIZE 10

typedef struct Person{
    char name[MAX_NAME];
    int age;
}person;

person * hashTable[TABLE_SIZE];

size_t hashFunction(char *name){
    int length = strnlen(name, MAX_NAME);
    size_t hashValue = 0;
    for(size_t i = 0; i < length; i++){
        hashValue += name[i];
        hashValue =(hashValue * name[i]) % TABLE_SIZE;
    }

    return hashValue;
}

void initHashTable(){
    for(size_t i = 0; i < TABLE_SIZE; i++){
        hashTable[i] = NULL;
    }
}

void printTable(){
    for(size_t i = 0; i < TABLE_SIZE; i++){
        if(hashTable[i] == NULL){
            printf("%d\t---\n", i);
        }
        else{
            printf("%d\t%s\n", i, hashTable[i] -> name);
        }
    }
}

bool insertHashTable(person* p){
    if(p == NULL) return false;
    size_t index = hashFunction(p -> name);
    // printf("Inserting %s...\n", p -> name);

    for(size_t i = 0; i < TABLE_SIZE; i++){
        size_t try = (index + i) % TABLE_SIZE;
        
        if(hashTable[try] == NULL){
            hashTable[try] = p;
            return true;
        }
    }
    return false;
}

person * findHash(char *name){
    size_t index = hashFunction(name);

    // printf("Finding %s...\n", name);

    for(size_t i = 0; i < TABLE_SIZE; i++){
        size_t try = (index + i) % TABLE_SIZE;
        
        if(hashTable[try] != NULL && strncmp(hashTable[try] -> name, name, MAX_NAME) == 0){
            return hashTable[try];
        }   
    }
    return NULL;
}

person * deleteHash(char * name){
    size_t index = hashFunction(name);

    // printf("Deleting %s...\n", name);
    for(size_t i = 0; i < TABLE_SIZE; i++){
        size_t try = (index + i) % TABLE_SIZE;

        if(hashTable[try] != NULL && strncmp(hashTable[try] -> name, name, MAX_NAME) == 0){
                person *temp = hashTable[try];
                hashTable[try] = NULL;
                return temp;
        }
    }
    return NULL;
}

int main(){
    initHashTable();
    printTable();
    
    printf("------------------------------\n");

    person jacob = {"Jacob", 12};
    person kate = {"Kate", 19};
    person natalie = {"Natalie", 18};
    person sara = {"Sarah", 22};
    person mpho = {"Mpho", 52};
    person edna = {"Edna", 31};
    person maren = {"Maren", 21};
    person eliza = {"Eliza", 46};
    person robert = {"Robert", 38};
    person charlie = {"Charlie", 38};

    insertHashTable(&jacob);
    insertHashTable(&kate);
    insertHashTable(&natalie);
    insertHashTable(&sara);
    insertHashTable(&mpho);
    insertHashTable(&edna);
    insertHashTable(&maren);
    insertHashTable(&eliza);
    insertHashTable(&robert);
    insertHashTable(&charlie);

    printTable();

    // person *temp = findHash("Maren");
    
    // if(temp == NULL){
    //     printf("Not found\n");
    // }
    // else{
    //     printf("%s found\n", temp -> name);
    // } 

    // person * tempd = deleteHash("Maren");

    // if(tempd == NULL){
    //     printf("Data not found to be deleted\n");
    // }
    // else{
    //     printf("Deleted %s\n", tempd -> name);
    // }

    // printTable();

    // printf("Jacob -> %zu\n", hashFunction("Jacob"));
    // printf("Natalie -> %zu\n", hashFunction("Natalie"));
    // printf("Sara -> %zu\n", hashFunction("Sara"));
    // printf("Mpho -> %zu\n", hashFunction("Mpho"));
    // printf("Tebogo -> %zu\n", hashFunction("Tebogo"));
    // printf("Ron -> %zu\n", hashFunction("Ron"));
    // printf("Jane -> %zu\n", hashFunction("Jane"));
    // printf("Maren -> %zu\n", hashFunction("Maren"));
    // printf("Bill -> %zu\n", hashFunction("Bill"));

    return 0;
}