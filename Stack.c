

#include <stdio.h>
#include <stdlib.h>

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
    push(s, 3);
    push(s, 3);
    push(s, 3);
    push(s, 3);
    push(s, 3);
    push(s, 4);
    push(s, 4);
    printf("%d\n", s->arr[s->top]);
    printf("%d\n", pop(s));
    printf("%d\n", pop(s));
    printf("%d\n", s->arr[s->top]);
    printf("%d\n", peek(s));

    return 0;
}
