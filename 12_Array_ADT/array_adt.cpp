#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct Array{
    int *A;
    int size;
    int length;
};

void Display(struct Array arr){
    printf("Elements are: \n");
    for(int i=0; i < arr.length; i++){
        printf("%d\n", arr.A[i]);
    }
}

int main(){

    struct Array arr;
    int n, i;

    printf("Enter the size of the array\n");
    scanf("%d", &arr.size);

    // Allocate memory of specified size of the array on heap
    arr.A = (int *) malloc(arr.size * sizeof(int));

    // Initialize the length of the array
    arr.length = 0;

    printf("Enter the number of elements to be entered:\n");
    scanf("%d", &n);
    arr.length = n;

    printf("Enter the elements of array\n");
    for(i = 0; i < n; i++){
        scanf("%d", &arr.A[i]);
    }

    Display(arr);

    return 0;
}