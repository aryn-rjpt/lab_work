#include <stdio.h>
#include <stdlib.h>

void takeArray(int arr[], int n){
    for (int i = 0; i<n; i++){
        // prinf("Enter value %d: ", i);
        scanf("%d", &arr[i]);
    }
}

void showArray(int arr[], int n){
    for ( int i = 0 ; i < n; i++ ){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){
    int i, j;
    for ( i=1; i<n; i++){
        int key = arr[i];
        for ( j=i-1; j>-1; j--){
            if ( arr[j] > key ){
                arr[j+1] = arr[j];
            }
            else break;
        }
        arr[j+1] = key;

    }
}

int main(){

    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n); 

    int arr[100];

    takeArray(arr, n);
    showArray(arr, n);
    insertionSort(arr, n);
    showArray(arr, n);

    return 0;
}