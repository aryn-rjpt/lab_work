#include <stdio.h>
#include <stdlib.h>
// Stack

struct Stack
{
    int size;
    int top;
    int *arr;
};

int stIsEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

int stIsFull(struct Stack *s)
{
    if (s->top == (s->size) - 1)
    {
        return 1;
    }
    return 0;
}

int push(struct Stack *s, int val)
{
    if (stIsFull(s))
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
    if (stIsEmpty(s))
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

int top(struct Stack *s)
{
    return s->arr[s->top];
}

int slen(struct Stack *s)
{
    return s->top+1;
}

void printStack(struct Stack *s)
{
    printf("Stack vals: ");
    for (int i = 0; i < slen(s); i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

// Queue

struct Queue
{
    int size;
    int front;
    int rear;
    int arr[];
};

int qIsFull(struct Queue *q)
{
    return q->rear == q->size;
}

int qIsEmpty(struct Queue *q)
{
    return q->front == q->rear - 1;
}

int enqueue(struct Queue *q, int n)
{
    if (qIsFull(q))
    {
        printf("Queue is full\n");
        return -1;
    }
    q->arr[q->rear++] = n;
}

int deque(struct Queue *q)
{
    if (qIsEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[++q->front];
}

void printQueue(struct Queue *q)
{
    if (qIsEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue vals: ");
        for (int i = q->front + 1; i < q->rear; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int peek(struct Queue *q)
{
    if (qIsEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front + 1];
}

int qlen(struct Queue *q)
{
    return q->rear - q->front - 1;
}

// students who remain hungry
int hungry(struct Stack *s, struct Queue *q)
{

    while (slen(s) > 0 && qlen(q) > 0)
    {

        int count = 0;

        printStack(s);
        printQueue(q);

        printf("%d\n", peek(q));
        printf("%d\n", top(s));

        while (peek(q) != top(s))
        {

            printf("aaya\n");

            printStack(s);
            printQueue(q);

            if (count == qlen(q))
                return qlen(q);

            int temp = deque(q);
            enqueue(q, temp);
            count++;
        }


        deque(q);
        pop(s);
        printStack(s);
        printQueue(q);
        printf("%d\n", slen(s));
        printf("%d\n", qlen(q));
    }

    return qlen(q);
}

int main()
{
    struct Stack *s = (struct Stack *)malloc(sizeof(struct Stack));
    s->size = 100;
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top = -1;

    push(s, 0);
    push(s, 1);
    push(s, 1);
    push(s, 0);

    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue) + sizeof(int) * 100);
    q->size = 100;
    q->front = -1;
    q->rear = 0;

    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 1);
    enqueue(q, 0);

    printf("Students who remain hungry: %d\n", hungry(s, q));

    return 0;
}