#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Time complexity - O(n)
void MinMax_SingleScan(int A[], int n)
{
    int min, max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] < min)
            min = A[i];
        else if (A[i] > max)
            max = A[i];
    }
    cout << "Minimum element is " << min << endl;
    cout << "Maximum element is " << max << endl;
}

int main()
{
    int A[] = {5, 8, 3, 9, 6, 2, 10, 7, -1, 4};
    int n = 10;

    MinMax_SingleScan(A, n);

    return 0;
}