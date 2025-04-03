#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

// This create has been modified to work for any number of LL creations.
Node *create(int A[], int n, bool loop)
{
    struct Node *t, *last;
    Node *q = NULL; // Loop pointer

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

        // Logic for Loop creation
        if (loop && i == 2)
        {
            q = t;
        }
    }

    if (loop)
        last->next = q;

    // Modified here
    return p;
}

void display(struct Node *p)
{

    while (p)
    {
        cout << p->data << " " << ends;
        p = p->next;
    }
}

bool detectLoop(Node *p)
{
    Node *slow = p, *fast = p;

    // Only 1 node or no node
    if (p == NULL || p->next == NULL)
        return false;

    while (fast != NULL && slow != NULL)
    {
        slow = slow->next;
        fast = fast->next->next; // OR fast = fast->next; fast = fast? fast->next : fast;

        if (slow == fast)
            return true;
    }

    return false;
}

int main()
{

    int A[5] = {2, 8, 10, 15, 16};
    first = create(A, 5, true);

    // display(first);

    // int B[5] = {2, 8, 10, 15, 16};
    // first = create(B, 5, false);

    if (detectLoop(first))
        cout
            << "Loop detected" << endl;
    else
        cout << "No loop detected" << endl;

    return 0;
}