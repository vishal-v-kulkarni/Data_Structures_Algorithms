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

// Search in LL using Loop
Node *search(Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }

    return NULL;
}

// Search in LL using Recursion
Node *search_rec(Node *p, int key)
{

    if (p == NULL)
        return NULL;

    if (p->data == key)
        return p;

    return search_rec(p->next, key);
}

// Search using Move to Head improvement
Node *search_HEAD(Node *p, int key)
{

    Node *q = NULL; // Trailing pointer to p.

    while (p)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = first;
            first = p;

            return p;
        }
        q = p;
        p = p->next;
    }

    return NULL;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " " << ends;
        p = p->next;
    }
}

int main()
{
    int A[] = {3, 2, 7, 4, 5};
    create(A, 5);

    cout << "Display before: " << endl;
    display(first);

    Node *temp = search_HEAD(first, 7);
    // Node *temp = search_rec(first, 7);
    // Node *temp = search_HEAD(first, 7);

    if (temp)
        cout << "Key found" << endl;
    else
        cout << "Key not found" << endl;

    cout << "Display after: " << endl;
    display(first);

    return 0;
}