#include <stdio.h>
#include <stdlib.h>


struct stack {
    int data;
    struct stack *next;
};

struct stack *top = NULL;


struct stack *push(struct stack *, int);
struct stack *pop(struct stack *);
int peek(struct stack *);
void display(struct stack *);

int main() {
    int val, option;

    do {
        printf("\n***** MAIN MENU *****\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");
        printf("Enter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number to be pushed on stack: ");
                scanf("%d", &val);
                top = push(top, val);
                break;

            case 2:
                top = pop(top);
                break;

            case 3:
                val = peek(top);
                if (val != -1)
                    printf("The value at the top of stack is: %d\n", val);
                else
                    printf("STACK IS EMPTY\n");
                break;

            case 4:
                display(top);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid option! Please try again.\n");
        }

    } while (option != 5);

    return 0;
}


struct stack *push(struct stack *top, int val) {
    struct stack *ptr = (struct stack *)malloc(sizeof(struct stack));
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return top;
    }

    ptr->data = val;
    ptr->next = top;
    top = ptr;
    return top;
}


struct stack *pop(struct stack *top) {
    struct stack *ptr;
    if (top == NULL) {
        printf("STACK UNDERFLOW\n");
        return NULL;
    }

    ptr = top;
    printf("The value being deleted is: %d\n", ptr->data);
    top = top->next;
    free(ptr);
    return top;
}


int peek(struct stack *top) {
    if (top == NULL)
        return -1;
    else
        return top->data;
}


void display(struct stack *top) {
    struct stack *ptr = top;
    if (top == NULL) {
        printf("STACK IS EMPTY\n");
    } else {
        printf("STACK ELEMENTS ARE:\n");
        while (ptr != NULL) {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

