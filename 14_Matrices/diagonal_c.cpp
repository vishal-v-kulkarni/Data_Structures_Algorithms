#include <stdio.h>
#include <stdlib.h>

// Assuming the matrix row and column number starts from 0
struct Matrix
{
    int n;
    int *A;
};

void Set(int *A, int i, int j, int x)
{
    if (i == j)
        A[i] = x;
}

int Get(int *A, int i, int j)
{
    if (i == j)
        return A[i];
    else
        return 0;
}

void Display(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            if (i == j)
                printf("%d ", m.A[j]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}

int main()
{

    struct Matrix m;
    m.n = 5;
    m.A = (int *)malloc(sizeof(int) * m.n);

    Set(m.A, 0, 0, 3);
    Set(m.A, 1, 1, 8);
    Set(m.A, 2, 2, 9);
    Set(m.A, 3, 3, 5);
    Set(m.A, 4, 4, 6);

    Display(m);

    printf("%d\n", Get(m.A, 0, 0));
    printf("%d\n", Get(m.A, 4, 4));

    return 0;
}