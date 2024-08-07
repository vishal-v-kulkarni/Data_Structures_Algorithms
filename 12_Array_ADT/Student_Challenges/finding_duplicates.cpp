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

// Finding and Counting Duplicated using Hashing - Method 2 - O(n)
void DuplicatesUsingHashing(int A[], int n, int l, int h)
{
    int *H = new int[h];

    for (int i = 0; i < n; i++)
    {
        H[A[i]]++;
    }

    for (int j = l; j < h; j++)
    {
        if (H[j] > 1)
            cout << "Element " << j << " appears " << H[j] << " times." << endl;
    }
}

int main()
{
    int A[] = {3, 6, 8, 8, 12, 12, 15, 15, 15, 20};
    int n = 10;
    int l = 3, h = 20;

    // FindingDuplicates(A, n);
    // CountingDuplicates(A, n);
    DuplicatesUsingHashing(A, n, l, h);

    return 0;
}