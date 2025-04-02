#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

// This create has been modified to work for any number of LL creations.
Node *create(int A[], int n)
{
    struct Node *t, *last;

    // Modified here
    Node *p = new Node;
    p->data = A[0];
    p->next = NULL;

    last = p; // Last will be initially pointing to last

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

void merge()
{
    Node *last = NULL;

    if (first->data < second->data)
    {
        third = last = first;
        first = first->next;
        last->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        last->next = NULL;
    }

    while (first && second)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            second = second->next;
            last->next = NULL;
        }
    }

    if (first != NULL)
        last->next = first;
    else
        last->next = second;
}

int main()
{

    int A[5] = {2, 8, 10, 15, 16};
    first = create(A, 5);

    int B[4] = {4, 7, 12, 14};
    second = create(B, 4);

    display(first);
    cout << endl;
    display(second);
    cout << endl;

    merge();
    display(third);

    return 0;
}