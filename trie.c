#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 256  // Maximum number of children for each Trie node (for extended ASCII)

// Trie node structure
typedef struct TrieNode {
    struct TrieNode *children[MAX_CHARS]; // Array of pointers to child nodes
    bool isTerminal; // Flag to mark the end of a word
} trie;

// Function to create a new Trie node
trie *createNode() {
    trie *node = malloc(sizeof(trie)); // Allocate memory for new node
    if (node == NULL) {
        fprintf(stderr, "Memory allocation error\n"); // Error if allocation fails
        return NULL;
    }
    node->isTerminal = false; // Set end-of-word flag to false initially

    // Initialize all child pointers to NULL
    for (size_t i = 0; i < MAX_CHARS; i++) {
        node->children[i] = NULL;
    }

    return node;
}

// Helper function to insert a word into the Trie
bool insertNodeHelper(trie **root, unsigned char *word) {
    // Create root node if Trie is empty
    if (*root == NULL) {
        *root = createNode();
    }

    trie *temp = *root; // Start from the root node

    // Traverse the Trie, creating nodes as necessary
    while (*word) {
        int index = *word; // Use ASCII value of character as index
        if (temp->children[index] == NULL) {
            temp->children[index] = createNode();
        }
        temp = temp->children[index];
        word++;
    }
    
    // If word is already marked as terminal, insertion is unsuccessful
    if (temp->isTerminal) {
        return false;
    }
    
    // Mark the last node as terminal (end of a word)
    temp->isTerminal = true;
    return true;
}

// Wrapper function for insert operation with signed input
void insertNode(trie **root, char *signedWord) {
    unsigned char *word = (unsigned char *)signedWord; // Cast to unsigned for extended ASCII support
    printf("%s: %s\n", insertNodeHelper(root, word) ? "Inserted" : "Insertion Unsuccessful", signedWord);
}

// Function to check if a node has any children
bool hasChild(trie *node) {
    if (node == NULL) return false;
    for (size_t i = 0; i < MAX_CHARS; i++) {
        if (node->children[i] != NULL) {
            return true;
        }
    }
    return false;
}

// Recursive helper function for deleting a word from the Trie
trie *deleteStrHelper(trie *node, unsigned char *word) {
    if (node == NULL) return node;

    // If more characters remain in the word, recurse on the child node
    if (*word) {
        int index = *word;
        node->children[index] = deleteStrHelper(node->children[index], word + 1);
    }

    // If end of word reached, unmark terminal node
    if (*word == '\0' && node->isTerminal) {
        node->isTerminal = false;
    }

    // If node has no children and is not terminal, free it
    if (!hasChild(node) && !node->isTerminal) {
        free(node);
        node = NULL;
    }

    return node;
}

// Wrapper function for deleting a word from the Trie
void deleteStr(trie **root, char *signedWord) {
    unsigned char *word = (unsigned char *)signedWord;
    *root = deleteStrHelper(*root, word);
    printf("Deleted: %s\n", signedWord);
}

// Recursive helper function to search for a word in the Trie
bool searchStrHelper(trie *node, unsigned char *word) {
    if (node == NULL) return false;

    trie *temp = node;

    // Traverse the Trie using each character in the word
    while (*word) {
        int index = *word;
        if (temp->children[index] == NULL) {
            return false; // If character path doesn't exist, word is not found
        }
        temp = temp->children[index];
        word++;
    }
    
    // Word is found if last node is marked as terminal
    return temp->isTerminal;
}

// Wrapper function for searching a word in the Trie
void searchStr(trie *root, char *signedWord) {
    unsigned char *word = (unsigned char *)signedWord;
    printf("%s: %s\n", searchStrHelper(root, signedWord) ? "Found" : "Not found", signedWord);
}

// Helper function to print all words in the Trie recursively
void printTrieHelper(trie *node, unsigned char *word, int level) {
    // Print word if terminal node is reached
    if (node->isTerminal) {
        word[level] = '\0';
        printf("Word: %s\n", word);
    }
    
    // Recurse over all children nodes
    for (size_t i = 0; i < MAX_CHARS; i++) {
        if (node->children[i] != NULL) {
            word[level] = (unsigned char)i; // Store character in word array
            printTrieHelper(node->children[i], word, level + 1);
        }
    }
}

// Wrapper function to print all words in the Trie
void printTrie(trie *root) {
    if (root == NULL) {
        printf("Trie is empty\n");
        return;
    } 
  
    unsigned char word[MAX_CHARS];
    printTrieHelper(root, word, 0);
}

int main() {
    trie *root = NULL;

    printf("[------Inserting String------]\n");
    insertNode(&root, "Reyna");
    insertNode(&root, "Neon");
    insertNode(&root, "Jett");
    insertNode(&root, "Iso");
  
    printf("[-------Printing Trie------]\n");
    printTrie(root);

    printf("[------Searching Trie------]\n");
    searchStr(root, "Reyna");
    searchStr(root, "Nitin");

    printf("[------Deleting String------]\n"); 
    deleteStr(&root, "Reyna");
  
    printf("[------Printing Trie------]\n");
    printTrie(root);

    return 0;
}