#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

class LowerTriangle
{
private:
    int n;
    int *A;

public:
    LowerTriangle(int n)
    {
        this->n = n;
        int size = (n * (n + 1)) / 2;
        A = new int[size];
    }

    void Scan();
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();

    ~LowerTriangle()
    {
        delete[] A;
    }
};

void LowerTriangle ::Scan()
{
    // Scan values from keyboard
    int x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &x);
            Set(i, j, x);
        }
    }

    printf("\n\n");
}

void LowerTriangle ::Set(int i, int j, int x)
{
    int index;
    if (i >= j)
    {
        // index = (i * (i + 1) / 2) + j; // Row-Major Formula
        index = ((n * j) - (((j - 1) * (j)) / 2)) + (i - j); // Column-Major Formula
        A[index] = x;
    }
}

int LowerTriangle::Get(int i, int j)
{
    int index;
    if (i >= j)
    {
        // index = (i * (i + 1) / 2) + j; // Row-Major Formula
        index = ((n * j) - (((j - 1) * (j)) / 2)) + (i - j); // Column-Major Formula
        return A[index];
    }
    else
    {
        return 0;
    }
}

void LowerTriangle::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int index;
            if (i >= j)
            {
                // index = (i * (i + 1) / 2) + j; // Row-Major Formula
                index = ((n * j) - (((j - 1) * (j)) / 2)) + (i - j); // Column-Major Formula
                printf("%d ", A[index]);
            }
            else
            {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main()
{
    int n;
    cout << "Enter the dimension of the matrix:" << endl;
    cin >> n;

    LowerTriangle l(n);

    cout << "Enter the elements: " << endl;
    l.Scan();

    printf("\n\n");

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