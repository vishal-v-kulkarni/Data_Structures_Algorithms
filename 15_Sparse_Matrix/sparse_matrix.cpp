#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};

void create(struct Sparse *s)
{
    cout << "Enter the dimensions" << endl;
    cin >> s->m;
    cin >> s->n;

    cout << "Enter the number of non-zero elements" << endl;
    cin >> s->num;

    s->e = (struct Element *)malloc(sizeof(struct Element) * s->num);

    cout << "Enter the elements for the matrix" << endl;

    for (int i = 0; i < s->num; i++)
    {
        cout << "Enter row for " << i << endl;
        cin >> s->e[i].i;

        cout << "Enter column for " << i << endl;
        cin >> s->e[i].j;

        cout << "Enter element for " << i << endl;
        cin >> s->e[i].x;
    }
}

void display(struct Sparse s)
{
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            while (k < s.num)
            {
                if (s.e[k].i == i && s.e[k].j == j)
                    cout << s.e[k].x << " ";
                else
                    cout << "0 ";

                k++;
            }
        }
        cout << endl;
    }
}

int main()
{
    struct Sparse s;
    create(&s);
    cout << s.e[0].x << endl;
    // display(s);
    return 0;
}