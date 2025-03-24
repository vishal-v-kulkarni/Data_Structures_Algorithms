#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->next = NULL;

    last = first; // Last will be initially pointing to last

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;

        // Connecting the previous node to the next node and moving the last pointer.
        last->next = t;
        last = t;
    }
}

// Sum loop
int sum(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

// Sum using Recursive function
int sum_rec(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return sum_rec(p->next) + p->data;
}

int main()
{
    int A[] = {3, 2, 7, 4, 5};
    create(A, 5);

    cout << "\nSum for LL using loop: " << sum(first) << endl;
    cout << "Sum for LL using recursion: " << sum_rec(first) << endl;

    return 0;
}