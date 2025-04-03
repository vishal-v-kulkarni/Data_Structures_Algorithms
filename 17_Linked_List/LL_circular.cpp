#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;

    head = new Node;
    head->data = A[0];
    head->next = head;

    last = head; // Last will be initially pointing to first

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

int main()
{
    return 0;
}