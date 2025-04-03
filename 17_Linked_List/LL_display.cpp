#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

// Declaration and initialization
struct Node
{
    int data;
    struct Node *next;
} *first = NULL; // first pointer is in stack and its data is in heap.

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

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " " << ends;
        p = p->next;
    }
}

// Display Recursive
void display_rec(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " " << ends;
        display_rec(p->next);
    }
}

int main()
{
    int A[] = {3, 2, 7, 4, 5};
    create(A, 5);
    display(first);

    display_rec(first);

    return 0;
}