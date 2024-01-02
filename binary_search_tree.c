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
        preOrder(root -> left);
        preOrder(root -> right);
    }
}

void inOrderTraversal(node root){
    if(root != NULL){
        inOrder(root -> left);
        printf("%d ", root -> data);
        inOrder(root -> right);
    }
}

void postOrderTraversal(node root){
    if(root != NULL){
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d ", root -> data);
    }
}

int main(){

    //         50
    //        /  \
    //      30    70
    //     / \   / \
    //    20  40 60  80


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

    printf("Elements: ");
    preOrder(root);
    printf("\n");

    printf("Elements: ");
    inOrder(root);
    printf("\n");

    printf("Elements: ");
    postOrder(root);
    printf("\n");

    return 0;
}