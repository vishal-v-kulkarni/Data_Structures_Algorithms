//
//  main.cpp
//  Pointers
//
//  Created by Vishal Kulkarni on 21/07/23.
//

#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{

    // Pointer to an integer in STACK section
    int a = 10;
    int *p;

    p = &a;

    cout << "Value of a: " << a << endl;
    cout << "Address of a using p: " << p << endl;
    cout << "Value of a using dereferencing: " << *p << endl;

    // Pointer to an array of integers in stack
    int A[5] = {2, 4, 6, 8, 10};
    int *P;

    P = A; // No need of & because Array is already pointing to the 1st element
    // OR P = &A[0]; //Pointing to the first element

    cout << P << endl; // Address(stack) to the 1st element of the array

    for (int i = 0; i < 5; i++)
    {

        cout << P[i] << endl; // P acts as the name of the array, so no dereferencing
        // cout << A[i] << endl;
    }

    // Pointer to an array of integers in HEAP
    int *Q;
    Q = (int *)malloc(5 * sizeof(int));
    // Q = new int[5]; //C++ syntax

    Q[0] = 11;
    Q[1] = 12;
    Q[2] = 13;
    Q[3] = 14;
    Q[4] = 15;

    for (int i = 0; i < 5; i++)
    {
        cout << Q[i] << endl;
    }

    // Deallocating the memory
    delete[] Q; // For array [], else just the variable name
    // free(Q); This is in C

    // Trying to declare a pointer to a single integer in HEAP- REVISION
    int *p6 = (int *)malloc(sizeof(int));

    *p6 = 10;
    cout << "This is a single integer on HEAP: " << *p6 << endl;
    // Size of the pointer is INdependent of the data type

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    struct Rectangle *p5;

    cout << sizeof(p1) << endl;
    cout << sizeof(p2) << endl;
    cout << sizeof(p3) << endl;
    cout << sizeof(p4) << endl;
    cout << sizeof(p5) << endl;

    return 0;
}
