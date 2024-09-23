#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *t;
};

void readTerms(struct Poly *p)
{
    cout << "Enter the number of terms in the polynomial" << endl;
    cin >> p->n;

    p->t = new Term[p->n];

    for (int i = 0; i < p->n; i++)
    {
        cout << "Enter the coefficient and exponent for the " << i + 1 << "th term" << endl;

        cin >> p->t[i].coeff >> p->t[i].exp;
    }
}

void display(struct Poly p)
{
    cout << "p(x) = ";
    for (int i = 0; i < p.n; i++)
    {
        cout << p.t[i].coeff;

        if (p.t[i].exp > 0)
        {
            if (p.t[i].exp == 1)
            {
                cout << "x";
            }
            else
            {
                cout << "x^";
                cout << p.t[i].exp;
            }
        }

        if (i < p.n - 1)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

int evaluate(struct Poly p, int x)
{
    int total = 0;
    for (int i = 0; i < p.n; i++)
    {
        total += p.t[i].coeff * pow(x, p.t[i].exp);
    }
    return total;
}

struct Poly *add(struct Poly p1, struct Poly p2)
{
    struct Poly *p3;
    p3 = new Poly;
    if (p1.n >= p2.n)
        p3->n = p1.n;
    else
        p3->n = p2.n;

    p3->t = new Term[p3->n];
    int i = 0, j = 0, k = 0;

    while (i < p1.n && j < p2.n)
    {
        if (p1.t[i].exp == p2.t[j].exp)
        {
            p3->t[k].exp = p1.t[i].exp;
            p3->t[k++].coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
        else if (p1.t[i].exp > p2.t[j].exp)
        {
            p3->t[k++] = p1.t[i++];
        }
        else
        {
            p3->t[k++] = p2.t[j++];
        }
    }

    for (; i < p1.n; i++)
        p3->t[k++] = p1.t[i];

    for (; j < p2.n; j++)
        p3->t[k++] = p2.t[j];

    return p3;
}

int main()
{
    struct Poly p1, p2;
    readTerms(&p1);
    readTerms(&p2);

    display(p1);
    display(p2);

    int x;
    cout << "Enter the value of x to evaluate the expression" << endl;
    cin >> x;
    cout << evaluate(p1, x) << endl;

    struct Poly *p3 = add(p1, p2);
    display(*p3);

    return 0;
}