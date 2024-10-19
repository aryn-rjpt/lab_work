#include <stdlib.h>
#include <stdio.h>

int max;

void takeArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
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
    int temp = *a;
    *a = *b;
    *b = temp;
}

int maxEle(int arr[], int n)
{
    int ans = -999999999;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans)
        {
            ans = arr[i];
        }
    }
    return ans;
}

void merge(int arr[], int left, int mid, int right)
{

    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right)
    {
        
        if (arr[i] % max <= arr[j] % max)
        {
            arr[k] = arr[k] + (arr[i] % max) * max;
            k++;
            i++;
        }
        else
        {
            arr[k] = arr[k] + (arr[j] % max) * max;
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        
        arr[k] = arr[k] + (arr[i] % max) * max;
        k++;
        i++;
    }

    while (j <= right)
    {
        
        arr[k] = arr[k] + (arr[j] % max) * max;
        k++;
        j++;
    }

    for (i = left; i <= right; i++)
    {
        
        arr[i] = arr[i] / max;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    takeArray(arr, n);

    max = maxEle(arr, n) + 1;
    mergeSort(arr, 0, n - 1);
    // merge(arr, 0, 2, 4);
    showArray(arr, n);

    return 0;
}