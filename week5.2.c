#include <stdio.h>
#define MAX 4

int queue[MAX];
int front = -1, rear = -1;

int isFull() {
    return (front == 0 && rear == MAX - 1) || (rear + 1 == front);
}

int isEmpty() {
    return front == -1;
}

void insert() {
    int num;
    printf("\nEnter the number to be inserted in the queue: ");
    scanf("%d", &num);

    if (isFull()) {
        printf("\nOVERFLOW");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = num;
}

int delete_element() {
    int val;

    if (isEmpty()) {
        printf("\nUNDERFLOW");
        return -1;
    }

    val = queue[front];

    if (front == rear) {
        front = rear = -1;
    } else if (front == MAX - 1) {
        front = 0;
    } else {
        front++;
    }

    return val;
}

int peek() {
    if (isEmpty()) {
        printf("\nQUEUE IS EMPTY");
        return -1;
    }
    return queue[front];
}

void display() {
    int i;

    if (isEmpty()) {
        printf("\nQUEUE IS EMPTY");
        return;
    }

    printf("\nQueue elements are: ");

    if (front <= rear) {
        for (i = front; i <= rear; i++)
            printf("\t%d", queue[i]);
    } else {
        for (i = front; i < MAX; i++)
            printf("\t%d", queue[i]);
        for (i = 0; i <= rear; i++)
            printf("\t%d", queue[i]);
    }
    printf("\n");
}

int main() {
    int option, val;

    do {
        printf("\n***** MAIN MENU *****");
        printf("\n1. Insert an element");
        printf("\n2. Delete an element");
        printf("\n3. Peek");
        printf("\n4. Display the queue");
        printf("\n5. Exit");
        printf("\nEnter your option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                insert();
                break;

            case 2:
                val = delete_element();
                if (val != -1)
                    printf("\nThe number deleted is: %d", val);
                break;

            case 3:
                val = peek();
                if (val != -1)
                    printf("\nThe first value in queue is: %d", val);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("\nExiting...");
                break;

            default:
                printf("\nInvalid option. Try again.");
        }
    } while (option != 5);

    return 0;
}

