#include<stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create()
{
    struct node *head = NULL, *temp, *newnode;
    int n, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->next = NULL;

        if(head == NULL)
            head = newnode;
        else
            temp->next = newnode;

        temp = newnode;
    }
    return head;
}


struct node* sort(struct node *head)
{
    struct node *p, *q;
    int temp;

    for(p = head; p != NULL; p = p->next)
    {
        for(q = p->next; q != NULL; q = q->next)
        {
            if(p->data > q->data)
            {
                temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
        }
    }
    return head;
}

struct node* reverse(struct node *head)
{
    struct node *prev = NULL, *current = head, *next;

    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct node* concatenate(struct node *head1, struct node *head2)
{
    struct node *temp;

    if(head1 == NULL)
        return head2;

    if(head2 == NULL)
        return head1;



    temp = head1;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = head2;

    return head1;
}

void display(struct node *head)
{
    while(head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head1, *head2;

    printf("First Linked List\n");
    head1 = create();

    printf("Second Linked List\n");
    head2 = create();

    printf("\nOriginal List: ");
    display(head1);

    head1 = sort(head1);
    printf("Sorted List: ");
    display(head1);

    head1 = reverse(head1);
    printf("Reversed List: ");
    display(head1);

    head1 = concatenate(head1, head2);
    printf("Concatenated List: ");
    display(head1);

    return 0;
}

