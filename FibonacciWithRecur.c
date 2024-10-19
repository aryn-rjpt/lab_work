#include <stdio.h>

int arr[100];

int nthfibo(int n){
    if ( n==0 || n==1 ){
        return n;
    }

    return nthfibo(n-1) + nthfibo(n-2);
}

void fibo(int n){

    if ( n==0 ){
        return;
    }

    fibo(n-1);

    int val;

    if ( arr[n] != 0 ){
        val = arr[n];
    } 
    else{
        val = nthfibo(n);
    }

    printf("%d\n", val);
}

int main(){

    for ( int i = 0; i<100; i++ ){
        arr[i] = 0;
    }

    fibo(10);


    return 0;
}