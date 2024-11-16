#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void add(struct Node *head, int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;

    struct Node *temp = head;

    while (temp->next != NULL)
    {

        temp = temp->next;
    }

    temp->next = new_node;
}

void delete(struct Node *head)
{
    if (head->next == NULL)
    {
        printf("Deleted the only element of linked list.");
        free(head);
    }
    else
    {
        struct Node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;
    }
}

void show(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;


    add(head, 2);
    add(head, 4);
    add(head, 6);

    show(head);

    delete(head);
    delete(head);
    show(head);

    return 0;
}