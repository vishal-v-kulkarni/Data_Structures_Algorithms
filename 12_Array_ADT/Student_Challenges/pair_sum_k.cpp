#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Unsorted Array - Method 1 - Scanning O(n2)
void PairSumK_Scan(int A[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] + A[j] == k)
                cout << "Sum of " << A[i] << " and " << A[j] << " is " << k << "." << endl;
        }
    }
}

// Unsorted Array - Method 2 - Hashing - O(n)
void PairSumK_Hashing(int A[], int l, int h, int n, int k)
{
    int *H = new int[h + 1];

    for (int i = 0; i < n; i++)
    {

        if (k - A[i] > 0)
        {
            if (H[k - A[i]] != 0)
            {

                cout << "Sum of " << A[i] << " and " << k - A[i] << " is " << k << "." << endl;
            }
            H[A[i]]++;
        }
    }
}

// Sorted Array - Using 2 pointers - O(n)
void PairSumK_TwoPointers(int A[], int n, int k)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (A[i] + A[j] == k)
        {
            cout << "Sum of " << A[i] << " and " << A[j] << " is " << k << "." << endl;
            i++, j--;
        }
        else if (A[i] + A[j] > k)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int k = 10;

    // Unsorted Array - 2 methods
    int A[] = {6, 3, 8, 10, 16, 7, 5, 2, 4, 14};
    int l = 2, h = 16;
    int n = 10;

    // Sorted Array
    int A1[] = {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};
    n = 10;

    // Function calls for Unsorted Array
    // PairSumK_Scan(A, n, k);
    // PairSumK_Hashing(A, l, h, n, k);

    // Function Calls for Sorted Array
    PairSumK_TwoPointers(A1, n, k);

    return 0;
}