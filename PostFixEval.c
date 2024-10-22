// Evaluating a postfix expression using stack

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack *s)
{
    if (s->top == (s->size) - 1)
    {
        return 1;
    }
    return 0;
}

int push(struct Stack *s, int val)
{
    if (isFull(s))
    {
        printf("Overflow occured");
        return -1;
    }
    s->top++;
    s->arr[s->top] = val;
    return 1;
}

int pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack is empty.");
        return -1;
    }
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

int peek(struct Stack *s)
{
    return s->arr[s->top];
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top = -1;

    char exp[] = "246++2*";

    for (int i = 0; i < strlen(exp); i++)
    {
        if (isdigit(exp[i]))
        {
            int digit;
            char c = exp[i];
            sscanf(&c, "%d", &digit);
            // printf("digit: %d\n", digit);
            push(s, digit);
        }
        else
        {
            int a = pop(s);
            int b = pop(s);
            // printf("%d, %d\n", a, b);
            if (exp[i] == '+')
            {
                push(s, a + b);
            }
            else if (exp[i] == '-')
            {
                push(s, a - b);
            }
            else if (exp[i] == '*')
            {
                push(s, a * b);
            }
            else if (exp[i] == '/')
            {
                push(s, a / b);
            }
        }
    }

    printf("%d\n", pop(s));

    return 0;
}
