#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Finding Duplicates in Sorted Array - Method 1 - O(n)
void FindingDuplicates(int A[], int n)
{
    int lastDuplicate = 0;
    cout << "Duplicates are: " << endl;

    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            lastDuplicate = A[i];
            cout << lastDuplicate << endl;
        }
    }
}

// Counting Duplicates in Sorted Array - Method 1 - O(n)
void CountingDuplicates(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (A[i] == A[i + 1])
        {
            int j = i + 1;

            while (A[i] == A[j])
                j++;

            cout << "Number " << A[i] << " is repeating " << j - i << " times" << endl;

            i = j - 1; // Consecutive repeating numbers will be skipped if it is i=j
        }
    }
}

// Finding and Counting Duplicated using Hashing - Method 2 - O(n) - Works for sorted and unsorted
void DuplicatesUsingHashing(int A[], int n, int l, int h)
{
    int *H = new int[h + 1];
    //  int A[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    for (int j = l; j < h + 1; j++)
    {
        if (H[j] > 1)
            cout << "Element " << j << " appears " << H[j] << " times." << endl;
    }
}

// Finding and counting duplicates for unsorted array
void DuplicatesUnsorted(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int count = 1;
        if (A[i] != -1)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i] == A[j])
                {
                    count++;
                    A[j] = -1;
                }
            }
            if (count > 1)
                cout << "Element " << A[i] << " appears " << count << " times." << endl;
        }
    }
}

int main()
{
    // Sorted Array
    // int A[] = {3, 6, 8, 8, 12, 12, 15, 15, 15, 20};
    // int n = 10;
    // int l = 3, h = 20;

    // Unsorted Array
    int A[] = {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    int n = 10;
    int l = 2;
    int h = 8;

    // FindingDuplicates(A, n);
    // CountingDuplicates(A, n);
    DuplicatesUsingHashing(A, n, l, h);

    // DuplicatesUnsorted(A, n);

    int A[h + 1][2];

    return 0;
}