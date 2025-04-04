#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
} *head = NULL;

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

// Count using do-while loop
int count(Node *p)
{

    if (p == NULL)
        return 0;

    int length = 0;
    do
    {
        length++;
        p = p->next;

    } while (p != head);

    return length;
}

void insert(Node *p, int pos, int x)
{
    Node *t;

    if (pos < 0 || pos > count(head))
        return;

    if (pos == 0)
    {
        t = new Node;
        t->data = x;

        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            t->next = head;

            // Move to the last node
            while (p->next != head)
                p = p->next;

            p->next = t;
            head = t;
        }
    }
    else
    {
        t = new Node;
        t->data = x;

        for (int i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

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

int main()
{
    int A[5] = {2, 5, 9, 1, 8};
    create(A, 5);

    display(head);
    cout << endl;

    insert(head, 5, 10);

    displayRec(head);
    // cout << count(head);

    return 0;
}