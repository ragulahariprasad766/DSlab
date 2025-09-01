#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    if (top < MAX - 1) {
    
    stack[++top] = c;
    }
}

// Pop function
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return -1; // Stack underflow
}

// Peek function
char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return -1;
}

// Operator precedence
int precedence(char op) {
    switch (op) {
        case '*':
        case '/':
        case '%': return 2;
        case '+':
        case '-': return 1;
        default: return 0;
    }
}

// Check if character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Infix to postfix conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char symbol;

    for (i = 0; i < strlen(infix); i++) {
        symbol = infix[i];

        if (isalnum(symbol)) { // Operand
            postfix[k++] = symbol;
        } 
        else if (symbol == '(') {
            push(symbol);
        } 
        else if (symbol == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '('
        } 
        else if (isOperator(symbol)) {
            while (top != -1 && precedence(peek()) >= precedence(symbol)) {
                postfix[k++] = pop();
            }
            push(symbol);
        }
    }

    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0'; // Null-terminate the postfix string
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

