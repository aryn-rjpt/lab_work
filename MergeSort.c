#include <stdlib.h>
#include <stdio.h>

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

void merge(int arr[], int left, int mid, int right){

    int n1 = mid - left + 1;
    int n2 = right - mid;
    int arrL[n1];
    int arrR[n2];

    int i=0, j=0;

    for (i = 0; i<n1; i++){
        arrL[i] = arr[left+i];
    }

    for (i = 0; i<n2; i++){
        arrR[i] = arr[mid+1+i];
    }

    i = 0;
    int k = left;

    while ( i<n1 && j<n2 ){
        if ( arrL[i] <= arrR[j] ){
            arr[k++] = arrL[i++];
        }
        else{
            arr[k++] = arrR[j++];
        }
    }

    while ( i<n1 ){
        arr[k++] = arrL[i++];
    }

    while ( j<n2 ){
        arr[k++] = arrR[j++];
    }

}


void mergeSort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];

    takeArray(arr, n);
    mergeSort(arr, 0, n - 1);
    showArray(arr, n);

    return 0;
}