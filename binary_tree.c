#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Queue

struct queue
{
    int size;
    int front;
    int rear;
    struct Node *arr[100];
};

int isFull(struct queue *q)
{
    return q->rear == q->size;
}

int isEmpty(struct queue *q)
{
    return q->front == -1;
}

int enqueue(struct queue *q, struct Node *n)
{
    if (isFull(q))
    {
        printf("Queue is full\n");
        return -1;
    }
    if (q->front == -1)
    {
        q->front = 0;
        q->rear = 0;
    }
    printf("Rear: %d\n", q->rear);
    q->arr[q->rear++] = n;
    return 0;
}

struct Node *deque(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    struct Node *node = q->arr[q->front++];
    if (q->front == q->rear)
    {
        q->front = q->rear = -1;
    }
    return node;
}

void printQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("%d %d\n", q->front, q->rear);
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d ", q->arr[i]->data);
        }
        printf("\n");
    }
}

int peek(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return q->arr[q->front + 1]->data;
}

void insert(struct Node *root, int val)
{
    printf("Inserting: %d\n", val);
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = val;
    node->left = NULL;
    node->right = NULL;

    if (root == NULL)
    {
        exit(1);
    }

    struct queue *q = (struct queue *)malloc(sizeof(struct queue) + sizeof(int) * 100);
    q->size = 100;
    q->front = -1;
    q->rear = 0;

    enqueue(q, root);

    printf("Printing queue: ");
    printQueue(q);

    while (1)
    {
        struct Node *cur = deque(q);

        if (cur->left != NULL)
        {
            enqueue(q, cur->left);
        }
        else
        {
            cur->left = node;
            break;
        }

        if (cur->right != NULL)
        {
            enqueue(q, cur->right);
        }
        else if (cur->right == NULL)
        {
            cur->right = node;
            break;
        }
    }
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main()
{

    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = 10;
    root->left = NULL;
    root->right = NULL;

    insert(root, 5);
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    insert(root, 11);
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    insert(root, 14);
    printf("Inorder: ");
    inorder(root);
    printf("\n");

    insert(root, 15);
    insert(root, 16);
    insert(root, 17);

    inorder(root);

    return 0;
}