#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class UpperTriangle
{
private:
    int n;
    int *A;

public:
    UpperTriangle(int n)
    {
        this->n = n;
        int size = (n * (n + 1)) / 2;
        A = new int[size];
    }

    void Scan();
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();

    ~UpperTriangle()
    {
        delete[] A;
    }
};

void UpperTriangle ::Scan()
{
    // Scan values from keyboard
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> x;
            Set(i, j, x);
        }
    }

    cout << endl
         << endl;
}

void UpperTriangle ::Set(int i, int j, int x)
{
    int index;
    if (i <= j)
    {
        // index = (j * (j + 1) / 2) +i; // Column-Major Formula
        index = ((n * i) - (((i - 1) * (i)) / 2)) + (j - i); // Row-Major Formula
        A[index] = x;
    }
}

int UpperTriangle::Get(int i, int j)
{
    int index;
    if (i <= j)
    {
        // index = (j * (j + 1) / 2) +i; // Column-Major Formula
        index = ((n * i) - (((i - 1) * (i)) / 2)) + (j - i); // Row-Major Formula
        return A[index];
    }
    else
    {
        return 0;
    }
}

void UpperTriangle::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int index;
            if (i <= j)
            {
                // index = (j * (j + 1) / 2) +i; // Column-Major Formula
                index = ((n * i) - (((i - 1) * (i)) / 2)) + (j - i); // Row-Major Formula
                cout << A[index] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the dimension of the matrix:" << endl;
    cin >> n;

    UpperTriangle l(n);

    cout << "Enter the elements: " << endl;
    l.Scan();

    cout << endl
         << endl;

    // l.Set(0, 0, 1);
    // l.Set(1, 0, 2);
    // l.Set(1, 1, 3);
    // l.Set(2, 0, 4);
    // l.Set(2, 1, 5);
    // l.Set(2, 2, 6);
    // l.Set(3, 0, 7);
    // l.Set(3, 1, 8);
    // l.Set(3, 2, 9);
    // l.Set(3, 3, 1);
    // l.Set(4, 0, 2);
    // l.Set(4, 1, 3);
    // l.Set(4, 2, 4);
    // l.Set(4, 3, 5);
    // l.Set(4, 4, 6);

    l.Display();

    cout << l.Get(4, 3) << endl;
    cout << l.Get(4, 1) << endl;
    cout << l.Get(3, 1) << endl;

    return 0;
}