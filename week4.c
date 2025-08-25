#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node *front, *rear;
};

// Create empty queue
void create_queue(struct queue *q) {
    q->front = q->rear = NULL;
}

// Insert element
void insert(struct queue *q, int val) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    ptr->data = val;
    ptr->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = ptr;
    } else {
        q->rear->next = ptr;
        q->rear = ptr;
    }
    printf("%d inserted into queue\n", val);
}

// Delete element
void delete_element(struct queue *q) {
    if (q->front == NULL) {
        printf("UNDERFLOW - Queue is empty\n");
        return;
    }
    struct node *temp = q->front;
    printf("Deleted: %d\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) // if queue becomes empty
        q->rear = NULL;

    free(temp);
}

// Display queue
void display(struct queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function with menu
int main() {
    struct queue q;
    create_queue(&q);
    int choice, val;

    while (1) {
        printf("\n--- Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insert(&q, val);
                break;
            case 2:
                delete_element(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

