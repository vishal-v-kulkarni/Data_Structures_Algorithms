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

    for (int i = 1; i <= s->num; i++)
    {
        cout << "Enter \'row column element\' for " << i << endl;
        cin >> s->e[i].i;
        cin >> s->e[i].j;
        cin >> s->e[i].x;
        }
}

// Method 1 - Self - Lengthier but works
// void display(struct Sparse s)
// {

//     for (int i = 1; i <= s.m; i++)
//     {
//         for (int j = 1; j <= s.n; j++)
//         {
//             int k = 1;
//             bool elementPrinted = false;
//             while (k <= s.num)
//             {
//                 if (s.e[k].i == i && s.e[k].j == j)
//                 {
//                     cout << s.e[k].x << " ";
//                     elementPrinted = true;
//                 }
//                 k++;
//             }
//             if (!elementPrinted)
//             {
//                 cout << "0 ";
//                 elementPrinted = false;
//             }
//         }
//         cout << endl;
//     }
// }

// Method 2 - Same with no boolean
void display(struct Sparse s)
{

    int k = 1;
    for (int i = 1; i <= s.m; i++)
    {
        for (int j = 1; j <= s.n; j++)
        {
            if (s.e[k].i == i && s.e[k].j == j)
            {
                cout << s.e[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    struct Sparse s;
    create(&s);
    // cout << s.e[0].x << endl;
    display(s);
    return 0;
}