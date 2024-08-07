#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Finding Duplicates in Sorted Array - Method 1
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

// Counting Duplicates in Sorted Array - Method 2
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

int main()
{
    int A[] = {3, 6, 8, 8, 12, 12, 15, 15, 15, 20};
    int n = 10;

    // FindingDuplicates(A, n);
    CountingDuplicates(A, n);
    return 0;
}