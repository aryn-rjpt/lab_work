#include <stdio.h>
#include <stdlib.h>

void takeArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        // prinf("Enter value %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void showArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void selectionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[min], &arr[i]);
        }
    }
}

int main()
{

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[100];

    takeArray(arr, n);
    selectionSort(arr, n);
    showArray(arr, n);

    return 0;
}