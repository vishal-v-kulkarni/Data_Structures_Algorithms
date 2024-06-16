#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

// To make it easier to explain and visualize, static array used. Dynamic array code commented.

struct Array{
    //int *A;
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    printf("Elements are: \n");
    for(int i=0; i < arr.length; i++){
        printf("%d\n", arr.A[i]);
    }
}




/* struct Array Append(struct Array arr, int element){
    if(arr.length < arr.size){
        arr.A[arr.length] = element;
        arr.length++;
    }
    return arr;
}
*/

// Instead of returning the struct(above), we can pass struct as an address and make changes.
void Append(struct Array *arr, int element){
    if(arr->length < arr->size){
        arr->A[arr->length] = element; // Can also be written as  arr->A[arr->length++] = element;. Read post and pre-increments.
        arr->length++;
    }
}

/* struct Array Insert(struct Array arr, int index, int element){
    if(arr.length < arr.size && index + 1 < arr.length){
        for(int i = arr.length; i > index; i--){
            arr.A[i] = arr.A[i-1];
        }
        arr.A[index] = element;
        arr.length++;
    }
    return arr;
} */

// Instead of returning the struct(above), we can pass struct as an address and make changes.
void Insert(struct Array *arr, int index, int element){
    if(index >= 0 && arr->length < arr->size && index <= arr->length){
        for(int i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = element;
        arr->length++;
    }
}

int main(){
    // Dynamic Array Creation
    /* struct Array arr;
    int n; //Number of Elements to be entered

    cout << "Enter the size of the array"<<endl;
    cin >> arr.size;

    arr.length = 0;

    cout << "Enter the number of elements to be entered:" << endl;
    cin >> n;

    arr.A = (int *)malloc(sizeof(int) * arr.size);

    for(int i=0; i<n; i++){
        cin >> arr.A[i];
        arr.length++;
    } */

    struct Array arr = {{1,2,3,4,5}, 10, 5};
    
    Insert(&arr, arr.length, 6); // 6th element
    Insert(&arr, arr.length, 7); // 7th element
    Insert(&arr, arr.length, 8); // 8th element
    Insert(&arr, arr.length, 9); // 9th element
    Insert(&arr, arr.length, 10); // 10th element

    Display(arr);

    Insert(&arr, arr.length, 11); // 11th element 

    Display(arr);

    return 0;
}