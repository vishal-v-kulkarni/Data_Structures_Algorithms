#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <climits>

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
Node *insert(Node *p, int position, int data)
{
    // New node
    Node *t = new Node;
    t->data = data;
    t->next = NULL;

    if (position < 0 || position > count(p))
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

// Not optimal - Because have to traverse everytime to the last.
void insertLast(Node *p, int data)
{
    // New node
    Node *t = new Node;
    t->data = data;
    t->next = NULL;

    int length = count(p);

    for (int i = 1; i < length; i++)
    {
        p = p->next;
    }
    t->next = p->next;
    p->next = t;
}

void insertLastOpt(int data)
{
    // New node
    Node *t = new Node;
    t->data = data;
    t->next = NULL;

    if (first == NULL && last == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
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
    // For insert either use this or start with index 0 as given below.
    // int A[] = {3, 2, 7, 4, 5};
    // create(A, 5);

    // 3 Nodes creation to test InsertLast
    // first = insert(first, 0, 3);
    // insert(first, 1, 4);
    // insert(first, 2, 5);

    // Updating last node to avoid traversing.
    //  Node *p = first;
    //  while (p->next)
    //  {
    //      p = p->next;
    //  }
    //  last = p;

    // We can directly start with this from 1st node creation.
    insertLastOpt(8);
    insertLastOpt(7);
    insertLastOpt(6);

    cout << "Display - insertion: " << endl;
    display(first);

    // int position;
    // int data;

    // cout << "\nPlease enter the position to insert a node: \n";
    // cin >> position;

    // cout << "Please enter the data to be inserted into the node: \n";
    // cin >> data;

    // Node *p = insert(first, position, data);

    // if (position == 0) // Head position, then update the head/first.
    //     first = p;

    // if (p)
    // {
    //     cout << "\nNode inserted at position, " << position << endl;
    //     cout << "Display after insertion: " << endl;
    //     display(first);
    // }

    // else
    //     cout << "\nNode could not be inserted because of wrong position" << endl;

    return 0;
}