
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;


void insert() {
    int value;

    if (rear == SIZE - 1) {
        printf("Queue Overflow\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &value);

        if (front == -1) {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        printf("%d inserted into the queue\n", value);
    }
}


void Delete() {
    if (front == -1) {
        printf("Queue Underflow\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }
}


void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");

        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }

        printf("\n");
    }
}

void peek() {
    if (front == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n--- Queue Operations ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                Delete();
                break;

            case 3:
                display();
                break;

            case 4:
                peek();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

