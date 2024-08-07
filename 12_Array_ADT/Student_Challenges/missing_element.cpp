#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int Sum(int A[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total = total + A[i];
    }
    return total;
}

// Single Missing Element - Method 1
int SumMissing(int A[], int n)
{
    int sum = n * (n + 1) / 2;
    int sumArray = Sum(A, n - 1); // Only 1 element missing

    int missingElement = sum - sumArray;

    return missingElement;
}

// Single Missing Element - Method 2
int UsingIndex(int A[], int n)
{
    int diff = A[0] - 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] - i > diff)
            return diff + i;
    }
    return -1; // No missing element
}

// Multiple Missing Element - Method 1
void MultipleUsingIndex(int A[], int n)
{
    int diff = A[0] - 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] - i > diff)
        {
            while (diff < A[i] - i)
            {
                cout << "Missing elements are " << diff + i << endl;
                diff++;
            }
        }
    }
}

// Multiple Missing Elements - Method 2
void MultipleUsingHashing(int A[], int n, int l, int h)
{
    int *H = new int[h];

    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    cout << "The missing elements are: " << endl;
    for (int j = l; j < h; j++)
    {
        if (H[j] == 0)
            cout << j << endl;
    }
}

int main()
{
    // int A[10] = {1, 2, 3, 4, 6, 7, 8, 9, 10};
    // int n = 10;

    // Sorted Array
    //  int A[8] = {6, 7, 8, 9, 12, 13, 15, 16};
    //  int n = 8;

    // Unsorted Array - Method 2
    int A[8] = {3, 2, 6, 5, 10, 9, 7, 12};
    int n = 8;
    int l = 2;
    int h = 12;

    // cout << "Missing element is " << SumMissing(A, n) << endl;
    // cout << "Missing element is " << UsingIndex(A, n) << endl;

    // MultipleUsingIndex(A, n);
    MultipleUsingHashing(A, n, l, h); // Method 2

    return 0;
}