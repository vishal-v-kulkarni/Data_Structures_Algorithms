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

void deleteLL(int position)
{
    Node *p = first;
    Node *t = NULL;

    int length = count(first);
    if (position == 1)
    {
        first = first->next;

        delete p;
    }
    else if (position > 1 && position <= length)
    {
        for (int i = 1; i < position && p; i++) // Check the condition of p!=NULL for wrong INDEX instead of checking position with length
        {
            t = p;
            p = p->next;
        }

        if (p) // Check the condition of p!=NULL for wrong INDEX instead of checking position with length
        {
            t->next = p->next;
            p->next = NULL;

            delete p;
        }
    }
}

int main()
{
    int A[5] = {3, 7, 5, 4, 2};
    create(A, 5);

    deleteLL(5);

    display(first);

    return 0;
}