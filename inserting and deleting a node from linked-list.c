#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;


void insert()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;

    printf("Node inserted successfully\n");
}


void Delete()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        temp = head;
        head = head->next;
        free(temp);

        printf("Node deleted successfully\n");
    }
}

// Display the linked list
void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        printf("Linked list: ");

        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}