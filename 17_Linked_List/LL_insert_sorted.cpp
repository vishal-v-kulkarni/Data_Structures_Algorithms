#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *last = NULL;

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

void insertSorted(int data)
{
    Node *p = first;
    Node *q = NULL;

    // New Node
    Node *t = new Node;
    t->data = data;
    t->next = NULL;

    while (p && p->data < data)
    {
        q = p;
        p = p->next;
    }

    if (p == first)
    {
        t->next = p;
        first = t;
    }
    else
    {
        q->next = t;
        t->next = p;
    }
}

int main()
{
    // int A[] = {3, 7, 9, 15, 20};
    // create(A, 5);

    insertSorted(2);
    insertSorted(1);
    insertSorted(18);
    insertSorted(16);
    insertSorted(15);

    display(first);

    return 0;
}