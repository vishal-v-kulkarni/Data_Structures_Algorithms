#include <stdio.h>
#include <iostream>

using namespace std;

int fun2(int n)
{

    if (n > 0)
    {
        return fun2(n - 1) + n;
    }
    return 0;
}

// int x=0; //Global variable is also the same.
// Revision: Final x value will be there in all addition operation on stack - Check Stack Tree

int fun(int n)
{

    static int x = 0; // Only initialized to 0 once, the very first time this line is hit

    if (n > 0)
    {
        x++;
        return fun(n - 1) + x;
    }
    return 0;
}

int main()
{

    int result;
    result = fun(5);

    cout << result << endl;

    return 0;
}