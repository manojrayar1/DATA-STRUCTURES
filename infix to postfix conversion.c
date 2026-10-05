#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int priority(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 2;

    return 0;
}

void infixToPostfix(char infix[], char postfix[])
{
    int i, j = 0;
    char x;

    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        /* Operand */
        if (isalnum(x))
        {
            postfix[j++] = x;
        }

        /* Opening parenthesis */
        else if (x == '(')
        {
            push(x);
        }

        /* Closing parenthesis */
        else if (x == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }

            if (top != -1)
                pop();   // Remove '('
        }

        /* Operator */
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(x))
            {
                postfix[j++] = pop();
            }

            push(x);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main()
{
    char infix[MAX], postfix[MAX];

    printf("Enter the infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}