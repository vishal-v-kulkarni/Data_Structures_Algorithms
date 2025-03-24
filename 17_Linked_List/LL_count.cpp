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

// Count using Recursive function
int count_rec(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return count(p->next) + 1;
}

int main()
{
    int A[] = {3, 2, 7, 4, 5};
    create(A, 5);

    cout << "\nCount for LL using loop: " << count(first) << endl;
    cout << "Count for LL using recursion: " << count_rec(first) << endl;

    return 0;
}