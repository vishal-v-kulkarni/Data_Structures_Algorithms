#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{

    int A[5] = {0, 0, 0, 3, 12};
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