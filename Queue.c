#include <stdlib.h>
#include <stdio.h>

struct queue
{
    int size;
    int front;
    int rear;
    int arr[];
};

int isFull(struct queue *q)
{
    return q->rear == q->size;
}

int isEmpty(struct queue *q)
{
    return q->front == q->rear -1;
}

int enqueue(struct queue *q, int n){
    if (isFull(q)){
        printf("Queue is full\n");
        return -1;
    }
    q->arr[q->rear++] = n;
}

int deque(struct queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[++q->front];
}

void printQueue(struct queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
    }
    else{
        for (int i=q->front+1; i<q->rear; i++){
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}

int peek(struct queue *q){
    if (isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front + 1];
}

int main()
{

    int size;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    struct queue *q = (struct queue *)malloc(sizeof(struct queue) + sizeof(int) * size);
    q->size = size;
    q->front = -1;
    q->rear = 0;

    enqueue(q, 10);
    printQueue(q);

    enqueue(q, 20);
    printQueue(q);

    enqueue(q, 30);
    printQueue(q);

    printf("Front element: %d\n", peek(q));

    deque(q);
    printQueue(q);

    printf("Front element after dequeue: %d\n", peek(q));

    return 0;
}