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
        cin >> s->e[i].i;
    }
}

int main()
{
    struct Sparse s;
    create(&s);
}