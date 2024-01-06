#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *left, *right;
}*node;

node createNode(int value){
    node root = malloc(sizeof(struct Node));
    root -> left = root -> right = NULL;
    root -> data = value;

    return root;
}

void linkNode(node root, node left, node right){
    root -> left = left;
    root -> right = right;
}

void preOrderTraversal(node root){
    if(root != NULL){
        printf("%d ", root -> data);
        preOrderTraversal(root -> left);
        preOrderTraversal(root -> right);
    }
}

void inOrderTraversal(node root){
    if(root != NULL){
        inOrderTraversal(root -> left);
        printf("%d ", root -> data);
        inOrderTraversal(root -> right);
    }
}

void postOrderTraversal(node root){
    if(root != NULL){
        postOrderTraversal(root -> left);
        postOrderTraversal(root -> right);
        printf("%d ", root -> data);
    }
}

node insertionRec(node root, int value){
    if(root == NULL){
        return createNode(value);
    }
    if(value < root -> data){
        root -> left = insertionRec(root -> left, value);
    }
    else{
        root ->right = insertionRec(root -> right, value);
    }
    return root;
}

node insertionIter(node root, int value){
    node currentNode = root,
    newNode = createNode(value),
    prev = NULL;

    while(currentNode != NULL){
        prev = currentNode;
        if(value < currentNode -> data){
            currentNode = currentNode -> left;
        }
        else{
            currentNode = currentNode -> right;
        }
    }

    if(prev == NULL){
        root = newNode;
    }
    else if(value < prev -> data){
        prev -> left = newNode;
    }
    else{
        prev -> right = newNode;
    }

    return root;
}

node inOrdPred(node root){
    root = root -> left;
    while(root -> right != NULL){
        root = root -> right;
    }
    return root;
}

node deleteNode(node root, int value){
    if(root == NULL){
        return root;
    }
    if(value < root -> data){
        root -> left = deleteNode(root -> left, value);
    }
    else if(value > root -> data){
        root -> right = deleteNode(root -> right, value);
    }
    else{
        if(root -> left == NULL){
            node temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            node temp = root -> left;
            free(root);
            return temp;
        }
        else{
            node iPre = inOrdPred(root);
            root -> data = iPre -> data;
            root -> left = deleteNode(root -> left, iPre -> data);
        }
    }
    return root;
}

int main(){

    //         50
    //        /  \
    //      30    70
    //     / \   / \
    //    20  40 60  80
    
    // Inorder = 20 30 40 50 60 70 80

    node root = createNode(50);

    node p1 = createNode(30);
    node a1 = createNode(20);
    node a2 = createNode(40);

    linkNode(p1, a1, a2);

    node p2 = createNode(70);
    node b1 = createNode(60);
    node b2 = createNode(80);

    linkNode(p2, b1, b2);

    linkNode(root, p1, p2);

    // printf("Elements: ");
    // preOrderTraversal(root);
    // printf("\n");

    printf("Elements: ");
    inOrderTraversal(root);
    printf("\n");
    // root = insertionRec(root, 10);
    // root = insertionIter(root, 10);
    deleteNode(root, 50);
    printf("Elements: ");
    inOrderTraversal(root);
    printf("\n");

    // printf("Elements: ");
    // postOrderTraversal(root);
    // printf("\n");

    return 0;
}