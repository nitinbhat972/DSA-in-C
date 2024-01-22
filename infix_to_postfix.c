#include<stdio.h>
#include<ctype.h>

#define MAX_SIZE 100

char arr[MAX_SIZE];
int top = -1;

int isFull(){
    return top == MAX_SIZE - 1;
}

int isEmpty(){
    return top == -1;
}

void push(char value){
    if(isFull()){
        printf("Stack overflow\n");
    }
    arr[++top] = value;
}

char pop(){
    if(isEmpty()){
        printf("Stack underflow\n");
        return '\0';
    }
    return arr[top--];
}

char peek(){
    return isEmpty() ? '\0': arr[top];
}

int getPrecedence(char op){
    if(op == '*' || op == '/'){
        return 2;
    }
    else if(op == '+' || op == '-'){
        return 1;
    }
    else{
        return -1;
    }
}

char matchingBrackets(char open){
    if(open == ')') return '(';
    else if (open == ']') return '[';
    else if(open == '}') return '{';
    else return '\0';
}

void infixToPostfix(char infix[], char postfix[]){
    int i = 0, j = 0;
    while(infix[i] != '\0'){
        if(infix[i] == ' '){
            i++;
        }
        else if(isalnum(infix[i])){
            postfix[j++] = infix[i++];
        }
        else if(infix[i] == '(' || infix[i] == '[' || infix[i] == '{'){
            push(infix[i++]);
        }
        else if(infix[i] == ')' || infix[i] == ']' || infix[i] == '}'){
            while(peek() != matchingBrackets(infix[i])){
                postfix[j++] = pop();
            }
            pop();
            i++;
        }
        else{
            if(getPrecedence(infix[i]) > getPrecedence(peek())){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(!isEmpty()){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

int main(){
    char infix[] = "a + [b * (c - d)]" ,postfix[MAX_SIZE];
    infixToPostfix(infix, postfix);

    printf("The postfilx expression of infix expression %s is: %s\n", infix, postfix);
    return 0;
}