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

int isMatching(char open, char close){
    return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}');
}

int parenthesesMatch(char exp[]){
    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i] == '(' || exp[i] == '[' || exp[i] == '{'){
            push(exp[i]);
        }
        else if(exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if(isEmpty() || !isMatching(pop(), exp[i])){
                return 0;
            }
        }
    }
    return isEmpty();
}

int main(){
    char exp[] = "[({a+b}*c)-d]";

    printf("The expression has %s parentheses\n", parenthesesMatch(exp) ? "balanced": "unbalanced");
    return 0;
}