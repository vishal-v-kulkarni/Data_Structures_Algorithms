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

int Delete(struct Array *arr, int index){
    int x=0;
    if(index >= 0 && index < arr->length){
        x = arr->A[arr->length-1];
        for(int i=index; i<arr->length-1; i++){
            arr->A[i] = arr->A[i+1];
        }
    
        arr->A[arr->length-1] = 0;
        arr->length--; 
    }
    return x;
}

void Swap(int *elementOne, int *elementTwo){
    
    int Temp;
    Temp = *elementOne;
    *elementOne = *elementTwo;
    *elementTwo = Temp;
}

int LinearSearch(struct Array *arr, int key){
    for(int i=0; i < arr->length; i++){
        if(key == arr->A[i]){
            // Method 1: Transposition
            // Swap(&arr->A[i], &arr->A[i-1]);
            // return i-1;

            //Method 2: Move to Head
            Swap(&arr->A[i], &arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr, int key){
    int l = 0;
    int h = arr.length-1;
    int mid;
    
    while(l <= h){
        mid = (l + h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid - 1;
        else
            l = mid + 1;
    }

    return -1;
}

int RecBinarySearch(struct Array arr, int l, int h, int key){
    int mid;

    if(l<=h){
        mid = (l+h)/2;
        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            return RecBinarySearch(arr, l, mid-1, key);
        else   
            return RecBinarySearch(arr, mid+1, h, key);
    }
    return -1;

}

int Get(struct Array arr, int index){
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    }
    return -1;
}

void Set(struct Array *arr, int index, int x){
    if(index >=0 && index < arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr){
    int max = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }

    return max;
}

int Min(struct Array arr){
    int min = arr.A[0];
    for(int i=1; i<arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }

    return min;
}

int Sum(struct Array arr){
    int total = 0;
    for (int i=0; i<arr.length; i++){
        total = total + arr.A[i];
    }
    return total;
}

int SumRec(struct Array arr, int n){
    if(n < 0)
        return 0;
    else
        return arr.A[n] + SumRec(arr, n-1);
}

float Avg(struct Array arr){
    return (float)SumRec(arr, arr.length) / arr.length;
}

void Reverse(struct Array *arr){
    // int B[arr->length];
    int *B;
    B = (int *)malloc(sizeof(int) * arr->length);

    for(int i=arr->length-1, j=0; i>=0; i--, j++){
        B[j] = arr->A[i];
    }

    for(int i=0; i<arr->length; i++){
        arr->A[i] = B[i];
    }

}

void ReverseSwap(struct Array *arr){
    int temp;
    for(int i=0, j=arr->length-1; i < j; i++, j--){
        Swap(&arr->A[i], &arr->A[j]);
    }
}

void LeftShift(struct Array *arr){
    for(int i=1; i<arr->length; i++){
        arr->A[i-1] = arr->A[i];
    }
    arr->A[arr->length-1] = 0;
}

void LeftRotate(struct Array *arr){
    int temp = arr->A[0];
    for(int i=1; i<arr->length; i++){
        arr->A[i-1] = arr->A[i];
    }
    arr->A[arr->length-1] = temp;
}

void RightShift(struct Array *arr){
    for(int i=arr->length-1; i>0; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = 0;
}

void RightRotate(struct Array *arr){
    int temp = arr->A[arr->length-1];
    for(int i=arr->length-1; i>0; i--){
        arr->A[i] = arr->A[i-1];
    }
    arr->A[0] = temp;
}

int InsertSorted(struct Array *arr, int x){
    int i = arr->length-1;

    while(i >=0 && arr->A[i] > x){
       arr->A[i+1] = arr->A[i];
       i--;
    }

    arr->A[i+1] = x; //Because 'i' will be 1 behind the empty space.
    arr->length++;
}

bool isSorted(struct Array arr){
    
    for(int i=0; i< arr.length-1; i++){
        if(arr.A[i] > arr.A[i+1])
            return false;
    }

    return true;
}

void NegativeArrange(struct Array *arr){
    int i=0;
    int j=arr->length-1;

    while(i < j){
        while(arr->A[i] < 0){ i++; }
        while(arr->A[j] >= 0){ j--;}

        if(i < j){
            Swap(&arr->A[i], &arr->A[j]);
        }
    }

}

struct Array * MergeArrays(struct Array arr1, struct Array arr2){
    int i=0, j=0, k=0;
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));

    while(i < arr1.length && j < arr2.length){
        if(arr1.A[i] <= arr2.A[j])
            arr3->A[k++] = arr1.A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }

    for(;i<arr1.length; i++)
        arr3->A[k++] = arr1.A[i];
    for(;j<arr2.length; j++)
        arr3->A[k++] = arr1.A[j];

    arr3->length = arr1.length + arr2.length;
    arr3->size = 10;    

    return arr3;

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

    struct Array arr = {{-6, 3, -8, 10, 5, -7, -9, 12, -4, 2}, 10, 10};
    
    // Insert(&arr, arr.length, 6); // 6th element

    // Display(arr);

    // Delete(&arr, 1);

    // Display(arr);

    // int index = LinearSearch(&arr, 4);
    // if(index == -1)
    //     cout << "Element not found!" << endl;
    // else    
    //     cout<< "Element found at index " << index << endl;

    Display(arr);

    // cout << BinarySearch(arr, 6) << endl; 
    // cout << RecBinarySearch(arr, 0, arr.length-1, 1) << endl;

    // cout<< Sum(arr) << endl;
    // cout<< SumRec(arr, arr.length) << endl;
    // cout<< Avg(arr) << endl;

    //Reverse(&arr);
    // ReverseSwap(&arr);
    
    //LeftShift(&arr);
    //RightRotate(&arr);

    //struct Array arr = {{1,2,12,81,87,93}, 10, 6};
    //InsertSorted(&arr,82);
    
    //struct Array arr = {{1,21,12,81,87,93}, 10, 6};
    //cout<< isSorted(arr) << endl;

    NegativeArrange(&arr);

    struct Array arr1 = {{3, 8, 16, 20, 25}, 10, 5};
    struct Array arr2 = {{4, 10, 12, 22, 23}, 10, 5};
    struct Array *arr3;
    arr3 = MergeArrays(arr1, arr2);

    Display(arr1);
    Display(arr2);
    Display(*arr3);
    return 0;

}