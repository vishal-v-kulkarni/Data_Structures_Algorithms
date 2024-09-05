#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums{1, 2, 3, 4, 5};
    cout << nums.size() << endl;

    int A[5] = {0, 1, 0, 3, 12};
    int i = 0, j = 0;
    int counter = 0;

    while (j < 5)
    {
        if (A[j] == 0)
        {
            counter++;
            j++;
        }
        else
        {
            A[i] = A[j];
            i++;
            j++;
        }
    }

    while (i < 5)
    {
        A[i] = 0;
        i++;
    }

    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}