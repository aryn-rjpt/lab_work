#include <stdio.h>

#include <stdlib.h>


int main(){

    int len;
    printf("Enter the size of the array: ");
    scanf("%d", &len);

    int arr[len];

    for (int i = 0; i<len; i++){
        printf("Element at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Given array: ");
    for (int i = 0; i<len; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");

    for (int i = len; i>0; i--){
        for ( int j = 0; j<i; j++){
            if (arr[j]>arr[j+1]){
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i<len; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}