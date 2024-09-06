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
        this->n = (n * (n + 1)) / 2;
        A = new int[this->n];
    }

    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();

    ~LowerTriangle()
    {
        delete[] A;
    }
};

int main()
{
    return 0;
}