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

// Insertion based on position
Node *insert(Node *p, int position, int data, int length)
{
    // New node
    Node *t = new Node;
    t->data = data;
    t->next = NULL;

    if (position < 0 || position > length)
        return NULL;

    if (position == 0)
    {
        t->next = p;
        p = t;
        return p;
    }
    else
    {
        for (int i = 1; i < position; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }

    return t;
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
    int length = count(first);

    cout << "Display before insertion: " << endl;
    display(first);

    int position;
    int data;

    cout << "\nPlease enter the position to insert a node: \n";
    cin >> position;

    cout << "Please enter the data to be inserted into the node: \n";
    cin >> data;

    Node *p = insert(first, position, data, length);

    if (position == 0) // Head position, then update the head/first.
        first = p;

    if (p)
    {
        cout << "\nNode inserted at position, " << position << endl;
        cout << "Display after insertion: " << endl;
        display(first);
    }

    else
        cout << "\nNode could not be inserted because of wrong position" << endl;

    return 0;
}