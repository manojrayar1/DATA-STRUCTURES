#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;
struct node *front = NULL;
struct node *rear = NULL;


void push()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = top;
    top = newnode;
}


void pop()
{
    struct node *temp;

    if(top == NULL)
        printf("Stack is Empty\n");
    else
    {
        temp = top;
        printf("Deleted: %d\n", top->data);
        top = top->next;
        free(temp);
    }
}


void displayStack()
{
    struct node *temp = top;

    printf("Stack: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


void enqueue()
{
    struct node *newnode;

    newnode = (struct node*)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}


void dequeue()
{
    struct node *temp;

    if(front == NULL)
        printf("Queue is Empty\n");
    else
    {
        temp = front;
        printf("Deleted: %d\n", front->data);
        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);
    }
}


void displayQueue()
{
    struct node *temp = front;

    printf("Queue: ");

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display Stack");
        printf("\n4.Enqueue\n5.Dequeue\n6.Display Queue");
        printf("\n7.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push();
                    break;

            case 2: pop();
                    break;

            case 3: displayStack();
                    break;

            case 4: enqueue();
                    break;

            case 5: dequeue();
                    break;

            case 6: displayQueue();
                    break;

            case 7: exit(0);

            default: printf("Invalid Choice\n");
        }
    }
    return 0;
}


