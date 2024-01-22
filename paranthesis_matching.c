#include<stdio.h>

#define SIZE 100

char arr[SIZE]; 
int top = -1;

int isFull(){
    return top == SIZE - 1;
}

int isEmpty(){
    return top == -1;
}

void push(char value){
    if(isFull()){
        printf("Stack overflow\n");
        return;
    }
    arr[++top] = value;
}

int pop(){
    if(isEmpty()){
        printf("Stack Underflow\n");
    }
    return arr[top--];
}

int parenthesesMatch(char exp[]){
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '('){
            push('(');
        }
        else if(exp[i] == ')'){
            if(isEmpty()){
                return 0;
            }
            pop();
        }
    }
    return isEmpty();
}

int main(){
    char exp[] = "((a+b)*c)-d";

    printf("The expression has %s parentheses\n", parenthesesMatch(exp) ? "balanced": "unbalanced");
    return 0;
}