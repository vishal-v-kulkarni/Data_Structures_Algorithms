#include <iostream>
#include <stdio.h>
using namespace std;

int add(int a, int b)
{ // Prototype/Signature/Declaration of a function / Formal parameters
    int c;
    c = a + b;
    return c; // The body with {} is called definition of the function
}

int main()
{
    int x, y, z;
    x = 10;
    y = 5;

    z = add(x, y); // Function call - Actual parameters
    cout << "Sum of x and y is " << z << endl;

    return 0;
}