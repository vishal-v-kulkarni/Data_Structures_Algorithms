#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Symmetric
{
private:
    int n;
    int *A;

public:
    Symmetric()
    {
        n = 5;
        A = new int[(n * (n + 1)) / 2];
    }
    Symmetric(int n)
    {
        this->n = n;
        A = new int[(n * (n + 1)) / 2];
    }

    void Swap(int *i, int *j);
    void Set(int i, int j, int x);
    void Scan();
    int Get(int i, int j);
    void Display();

    ~Symmetric()
    {
        delete[] A;
    }
};

void Symmetric::Swap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

void Symmetric ::Scan()
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

void Symmetric ::Set(int i, int j, int x)
{
    int index;
    if (i >= j)
    {
        index = (i * (i + 1) / 2) + j; // Row-Major Formula
        // index = ((n * j) - (((j - 1) * (j)) / 2)) + (i - j); // Column-Major Formula
        A[index] = x;
    }
}

int Symmetric::Get(int i, int j)
{
    int index;
    if (i >= j)
    {
        index = (i * (i + 1) / 2) + j; // Row-Major Formula
        // index = ((n * j) - (((j - 1) * (j)) / 2)) + (i - j); // Column-Major Formula
        return A[index];
    }
    else
    {
        // Method 1 - Swap i and j
        // Swap(&i, &j);

        // Method 2 - Swap i and i in the formula
        index = (j * (j + 1) / 2) + i;
        // index = ((n * i) - (((i - 1) * (i)) / 2)) + (j - i);
        return A[index];

        // Swap(&i, &j);
    }
}

void Symmetric::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int index;
            if (i >= j)
            {
                index = (i * (i + 1) / 2) + j; // Row-Major Formula
                // index = ((n * j) - (((j - 1) * (j)) / 2)) + (i - j); // Column-Major Formula
                cout << A[index] << " ";
            }
            else
            {
                // Method 1 - Swap i and j, but swap them back after printing, because changing i and j itself will cause problems in the loop
                // Swap(&i, &j);

                // Method 2 - Swap i and i in the formula
                index = (j * (j + 1) / 2) + i;
                // index = ((n * i) - (((i - 1) * (i)) / 2)) + (j - i);
                cout << A[index] << " ";

                // Swapped back to maintain the for loops
                // Swap(&i, &j);
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

    Symmetric s(n);

    cout << "Enter the elements: " << endl;
    s.Scan();

    cout << endl
         << endl;

    s.Display();

    cout << s.Get(4, 3) << endl;
    cout << s.Get(4, 1) << endl;
    cout << s.Get(3, 1) << endl;

    return 0;
}
