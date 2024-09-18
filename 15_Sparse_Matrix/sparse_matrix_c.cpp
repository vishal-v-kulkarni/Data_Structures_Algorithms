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

// Method 2 - Same with no boolean and while loop
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

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    if (s1->m != s2->m && s1->n != s2->n)
        return NULL;

    int i, j, k;
    i = j = k = 1;

    struct Sparse *s3;
    s3 = (struct Sparse *)malloc(sizeof(struct Sparse));
    s3->e = (struct Element *)malloc((s1->num + s2->num) * sizeof(struct Element));

    while (i <= s1->num && j <= s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
            s3->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            s3->e[k++] = s2->e[j++];
        else
        {
            if (s1->e[i].j < s2->e[j].j)
                s3->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                s3->e[k++] = s2->e[j++];
            else
            {
                s3->e[k] = s1->e[i];
                s3->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for (; i <= s1->num; i++)
        s3->e[k++] = s1->e[i];

    for (; j <= s2->num; j++)
        s3->e[k++] = s2->e[j];

    s3->num = k;
    s3->m = s1->m;
    s3->n = s1->n;

    return s3;
}

int main()
{
    struct Sparse s1, s2;

    // Take inputs for s1 and s2
    create(&s1);
    create(&s2);

    // Display s1 and s2
    cout << "First Matrix" << endl;
    display(s1);

    cout << "Second Matrix" << endl;
    display(s2);

    struct Sparse *s3 = add(&s1, &s2);

    // Display the s3
    cout << "Sum Matrix" << endl;
    display(*s3);
    // cout << s.e[0].x << endl;

    return 0;
}