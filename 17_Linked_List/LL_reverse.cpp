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

// Reversing the LL using recursion
void reverseRecursion(Node *p, Node *q)
{
    if (p != NULL)
    {
        reverseRecursion(p->next, p);
        p->next = q;
    }
    else
    {
        first = q;
    }
}

// Reversing the LL by reversing the Links.
void reverseLinks(Node *p)
{
    Node *q = NULL;
    Node *r = NULL;

    while (p)
    {
        r = q;
        q = p;
        p = p->next;

        q->next = r;
    }

    first = q;
}

// Reversing the LL using auxilary array.
void reverseElements(Node *p)
{
    int length = count(p);
    int A[length];
    int i = 0;

    while (p)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }

    // Bring 'p' back to First Node
    p = first;
    i--;

    while (p)
    {
        p->data = A[i--];
        p = p->next;
    }
}

int main()
{
    int A[5] = {2, 4, 3, 6, 7};
    create(A, 5);

    // reverseElements(first);
    // reverseLinks(first);
    reverseRecursion(first, NULL);

    display(first);

    return 0;
}