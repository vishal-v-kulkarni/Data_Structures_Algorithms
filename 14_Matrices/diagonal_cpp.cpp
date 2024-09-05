#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Assuming that the matric row and column starts from 0
class Diagonal
{
private:
    int n;
    int *A;

public:
    Diagonal(int n)
    {
        this->n = n;
        A = new int[n];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();

    ~Diagonal()
    {
        delete[] A;
    }
};

void Diagonal::Set(int i, int j, int x)
{
    if (i == j && i < n && j < n)
    {
        A[i] = x;
    }
}

int Diagonal::Get(int i, int j)
{
    if (i == j && i < n && j < n)
        return A[i];
    else
        return 0;
}

void Diagonal::Display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << A[j] << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
}

int main()
{
    Diagonal d(5);

    d.Set(0, 0, 3);
    d.Set(1, 1, 8);
    d.Set(2, 2, 9);
    d.Set(3, 3, 5);
    d.Set(4, 4, 6);
    d.Set(5, 5, 6); // Invalid Index

    d.Display();

    cout << d.Get(0, 0) << endl;
    cout << d.Get(3, 3) << endl;
    cout << d.Get(4, 3) << endl;
    cout << d.Get(5, 5) << endl; // Invalid Index

    return 0;
}