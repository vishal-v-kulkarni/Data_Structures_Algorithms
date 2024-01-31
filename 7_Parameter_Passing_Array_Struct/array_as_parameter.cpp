#include <iostream>
#include <stdio.h>
using namespace std;

void fun(int A[], int n)
{ // We can use *A instead of A[]

    // cout<<"Size of Array in fun: "<<sizeof(A)/sizeof(int)<<endl; //Size of pointer/size of int as Array is passed as address/pointer

    // Cannot use for each loop on a pointer
    //  for(int a:A){
    //      cout<<a<<endl;
    //  }

    // for(int i=0;i<5;i++){
    //     cout<<A[i]<<endl;
    // }

    A[0] = 15;
}

int *fun1(int size) //* for returning array in new compilers
{
    int *p;
    p = new int[size]; // Array created in the HEAP

    for (int i = 0; i < size; i++)
    {
        p[i] = i + 1;
    }

    return p;
}

// Returning array in C
int *fun2(int n)
{
    int *A;
    A = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        A[i] = i + 1;
    }

    return A;
}

int main()
{

    int A[] = {2, 4, 6, 8, 10};
    int n = 5;
    fun(A, n);
    cout << "Size of Array in main: " << sizeof(A) / sizeof(int) << endl;

    for (int x : A)
        cout << x << endl;

    // Function returning array logic
    int *ptr, size = 5;

    ptr = fun1(size);

    for (int i = 0; i < size; i++)
        cout << ptr[i] << endl;

    // Function returning array in C
    int B[size];
    int *C = &B[0];
    C = fun2(size);

    return 0;
}