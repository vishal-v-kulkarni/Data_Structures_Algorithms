#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;

// This create has been modified to work for any number of LL creations.
Node *create(int A[], int n)
{
    struct Node *t, *last;

    // Modified here
    Node *p = new Node;
    p->data = A[0];
    p->next = NULL;

    last = p; // Last will be initially pointing to first

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;

        // Connecting the previous node to the next node and moving the last pointer.
        last->next = t;
        last = t;
    }

    // Modified here
    return p;
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " " << ends;
        p = p->next;
    }
}

// Concatenation of 2 LL
void concat(Node *p)
{

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = second;
    second = NULL;
}

int main()
{

    int A[5] = {2, 4, 3, 6, 7};
    first = create(A, 5);

    int B[3] = {8, 9, 1};
    second = create(B, 3);

    display(first);
    cout << endl;
    display(second);
    cout << endl;

    concat(first);
    display(first);

    return 0;
}