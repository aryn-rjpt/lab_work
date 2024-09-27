#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Stack
{
    int len;
    int arr[100];
};

bool isFull(struct Stack* st)
{
    return st->len == 99;
}

bool isEmpty(struct Stack* st)
{
    return st->len == 0;
}

void push(struct Stack* st, int x)
{
    if (isFull(st))
    {
        printf("Stack full");
        exit(1);
    }
    int idx = st->len++;
    (st->arr)[idx] = x;
    
}

void show(struct Stack* st)
{
    for (int i = 0; i < st->len; i++)
    {
        printf("%d ", st->arr[i]);
    }
}

void pop(struct Stack* st){
    if (isEmpty(st)){
        printf("Stack empty");
        exit(1);
    }
    st->len--;
}

int main()
{

    struct Stack st;
    st.len = 0;


    push(&st, 1);
    push(&st, 2);git
    push(&st, 3);
    push(&st, 4);
    pop(&st);
    push(&st, 5);
    push(&st, 6);

    show(&st);

    return 0;
}
