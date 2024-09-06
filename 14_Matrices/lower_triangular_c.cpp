#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Matrix
{
    int n;
    int *A;
};

void Set(struct Matrix *m, int i, int j, int x)
{
    int index;
    if (i >= j)
    {
        index = (i * (i + 1) / 2) + j; // Row-Major Formula
        m->A[index] = x;
    }
}

int Get(struct Matrix *m, int i, int j)
{
    int index;
    if (i >= j)
    {
        index = (i * (i + 1) / 2) + j;
        return m->A[index];
    }
    else
    {
        return 0;
    }
}

void Display(struct Matrix m)
{
    for (int i = 0; i < m.n; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            int index;
            if (i >= j)
            {
                index = (i * (i + 1) / 2) + j;
                printf("%d ", m.A[index]);
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

    struct Matrix m;
    m.n = 5;
    int numberElements = (m.n * (m.n + 1)) / 2;

    m.A = (int *)malloc(sizeof(int) * numberElements);

    Set(&m, 0, 0, 1);
    Set(&m, 1, 0, 2);
    Set(&m, 1, 1, 3);
    Set(&m, 2, 0, 4);
    Set(&m, 2, 1, 5);
    Set(&m, 2, 2, 6);
    Set(&m, 3, 0, 7);
    Set(&m, 3, 1, 8);
    Set(&m, 3, 2, 9);
    Set(&m, 3, 3, 1);
    Set(&m, 4, 0, 2);
    Set(&m, 4, 1, 3);
    Set(&m, 4, 2, 4);
    Set(&m, 4, 3, 5);
    Set(&m, 4, 4, 6);

    Display(m);

    printf("%d\n", Get(&m, 4, 3));
    printf("%d\n", Get(&m, 4, 1));
    printf("%d\n", Get(&m, 3, 1));

    return 0;
}