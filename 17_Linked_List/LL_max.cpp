#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>

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

int max(struct Node *p)
{
    int max = INT_MIN;

    while (p) // or while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }

    return max;
}

int max_rec(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return INT_MIN;
    else
    {
        x = max_rec(p->next);
        return p->data > x ? p->data : x;
    }
}

int main()
{
    int A[] = {3, 2, 7, 4, 5};
    create(A, 5);

    cout << "Max using loop: " << max(first) << endl;
    cout << "Max using Recursion: " << max_rec(first) << endl;

    return 0;
}