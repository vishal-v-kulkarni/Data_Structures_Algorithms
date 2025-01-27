// This program uses the pattern of "Floyds Algorithm of Rabbit and Hare"

/*
You are given the head of a singly linked list. Your task is to determine if the linked list contains a loop. A loop exists in a linked list if the next pointer of the last node points to any other node in the list (including itself), rather than being null.

Custom Input format:
A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

Examples:

Input: head: 1 -> 3 -> 4, pos = 2
*/

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

class Solution
{
public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {

        // your code here
        if (head == NULL || (head->next) == NULL)
            return false;

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && (fast->next) != NULL)
        {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }
        return false;
    }
};