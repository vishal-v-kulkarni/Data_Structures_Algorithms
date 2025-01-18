#include <iostream>
#include <stdio.h>
using namespace std;

void swapByAddress(int *x, int *y) // Call by address. These are pointers: similar to int *x = &a
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// Call by Reference - The function may become inline to main - Depends on compiler
void swapByRef(int &x, int &y) // Call by reference. These are references: similar to int &x = a
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int main()
{

    int a = 10, b = 20;

    swapByAddress(&a, &b); // Passing the address of actual paramters
    // swapByRef(a, b); // Passing the actual to formal as nick names.
    cout << "First number: " << a << endl
         << "Second Number: " << b << endl;
    return 0;
}