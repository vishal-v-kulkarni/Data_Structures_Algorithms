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

    last = first; // Last will be initially pointing to first

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

// Count loop
int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }

    return count;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " " << ends;
        p = p->next;
    }
}

bool sorted(Node *p)
{
    Node *q = NULL;

    while (p->next)
    {
        q = p;
        p = p->next;

        if (q->data > p->data)
            return false;
    }

    return true;
}

int main()
{
    // int A[5] = {3, 7, 5, 4, 2};
    int A[5] = {3, 4, 5, 6, 8};
    create(A, 5);

    if (sorted(first))
    {
        cout << "The linked list is sorted\n";
    }
    else
    {
        cout << "The linked list is not sorted\n";
    }

    return 0;
}