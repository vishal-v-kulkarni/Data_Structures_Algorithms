#include <iostream>

using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;

} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;

    last = first; // Last will be initially pointing to first

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = NULL;

        // Connecting the previous node to the next node and moving the last pointer.
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " " << ends;
        p = p->next;
    }
}

void displayReverse(Node *p)
{
    while (p->next != NULL)
        p = p->next;

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->prev;
    }
}

int length(Node *p)
{
    int length = 0;

    while (p)
    {
        length++;
        p = p->next;
    }
    return length;
}

void insert(Node *p, int pos, int x)
{

    Node *t;
    int count = length(first);
    if (pos < 0 || pos > count)
        return;

    if (pos == 0)
    {
        t = new Node;
        t->data = x;
        t->next = t->prev = NULL;

        if (first == NULL)
        {
            first = t;
        }
        else
        {
            t->next = first;
            first->prev = t;
            first = t;
        }
    }
    else
    {
        t = new Node;
        t->data = x;
        t->next = t->prev = NULL;

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t->prev = p;
        t->next = p->next;

        if (p->next)
        {
            p->next->prev = t;
        }
        p->next = t;
    }
}

int main()
{
    int A[] = {3, 2, 7, 4, 5};
    create(A, 5);

    display(first);
    cout << endl;

    insert(first, 0, 1);
    insert(first, 1, 8);

    display(first);
    cout << endl;

    insert(first, 7, 10);
    display(first);
    cout << endl;

    displayReverse(first);
    return 0;
}