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
    head->next = head; // Circular

    last = head; // Last will be initially pointing to first

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = head; // Circular

        // Connecting the previous node to the next node and moving the last pointer.
        last->next = t;
        last = t;
    }
}

// Display using do-while loop
void display(Node *p)
{

    do
    {
        cout << p->data << " ";
        p = p->next;

    } while (p != head);
}

// Display using flag and recursion
void displayRec(Node *p)
{
    static bool flag = false; // Static is important, so that it is changing only once.
    if (p != head || flag == false)
    {
        flag = true;
        cout << p->data << " ";
        displayRec(p->next);
    }
    flag = false;
}

int main()
{
    int A[5] = {2, 5, 9, 1, 8};
    create(A, 5);

    display(head);
    cout << endl;

    displayRec(head);

    return 0;
}