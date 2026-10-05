#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = ch;
}

char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return '\0';
    }

    return stack[top--];
}

void reversePrefix(char word[], char ch)
{
    int i, index = -1;

    
    for (i = 0; word[i] != '\0'; i++)
    {
        if (word[i] == ch)
        {
            index = i;
            break;
        }
    }

    
    if (index == -1)
        return;

    
    for (i = 0; i <= index; i++)
    {
        push(word[i]);
    }

    
    for (i = 0; i <= index; i++)
    {
        word[i] = pop();
    }
}

int main()
{
    char word[MAX];
    char ch;

    printf("Enter the word: ");
    scanf("%s", word);

    printf("Enter the character: ");
    scanf(" %c", &ch);

    reversePrefix(word, ch);

    printf("Result: %s\n", word);

    return 0;
}