#include <stdio.h>
#include <stdlib.h>

struct Matrix
{
    int r;
    int c;
    int arr[100][100];
};

void showMatrix(struct Matrix *m)
{
    for (int i = 0; i < m->r; i++)
    {
        for (int j = 0; j < m->c; j++)
        {
            printf("%d ", m->arr[i][j]);
        }
        printf("\n");
    }
}

void inputMatrix(struct Matrix *m)
{
    printf("Enter the number of rows: ");
    scanf("%d", &m->r);
    printf("Enter the number of cols: ");
    scanf("%d", &m->c);
    printf("\n");

    for (int i = 0; i < m->r; i++)
    {
        for (int j = 0; j < m->c; j++)
        {
            printf("Enter the value of element matrix[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m->arr[i][j]);
        }
    }
}

struct Matrix *multiply(struct Matrix *m1, struct Matrix *m2, struct Matrix *result)
{

    for (int i = 0; i < m1->r; i++)
    {
        for (int j = 0; j < m2->c; j++)
        {
            result->arr[i][j] = 0;
            for (int k = 0; k < m1->c; k++)
            {
                result->arr[i][j] += m1->arr[i][k] * m2->arr[k][j];
            }
        }
    }
    return result;
}

int main()
{

    struct Matrix *m1 = (struct Matrix *)malloc(sizeof(struct Matrix));

    inputMatrix(m1);
    printf("Matrix 1: \n");
    showMatrix(m1);
    printf("\n");

    struct Matrix *m2 = (struct Matrix *)malloc(sizeof(struct Matrix));

    inputMatrix(m2);
    printf("Matrix 2: \n");
    showMatrix(m2);
    printf("\n");

    if (m1->c != m2->r)
    {
        printf("Invalid Matrix: Matrix 1's cols should be equal in number to Matrix 2's rows");
        exit(1);
    }

    struct Matrix *result = (struct Matrix *)malloc(sizeof(struct Matrix));
    result->r = m1->r;
    result->c = m2->c;
    result = multiply(m1, m2, result);

    printf("Result Matrix: \n");
    showMatrix(result);
    printf("\n");

    return 0;
}