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

// O(n) - scanning it once
int findMiddle(Node *p)
{
    Node *q = first;

    while (q)
    {
        q = q->next;

        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    return p->data;
}

int main()
{
    int A[8] = {8, 6, 3, 9, 10, 5, 4, 12};
    create(A, 8);

    cout << "The middle node of the LL is: " << findMiddle(first) << endl;

    return 0;
}