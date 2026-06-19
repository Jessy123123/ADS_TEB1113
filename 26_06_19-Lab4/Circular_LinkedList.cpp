#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next = NULL;
};

Node *findTail(Node *head) // helper function
{

    if (head == NULL)
    {
        return NULL;
    }
    Node *current = head;

    while (current->next != head)
    {
        current = current->next;
    }

    return current;
}

void insertion(Node *&head)
{
    int newNodeIdx;
    Node *newNode = new Node();

    cout << "Enter value to be inseted: ";
    cin >> newNode->name;
    cout << "Enter position to be inserted: ";
    cin >> newNodeIdx;

    if (head == NULL)
    {
        newNode->next = newNode;
        head = newNode;
        return;
    }

    Node *tail = findTail(head);

    if (newNodeIdx == 0)
    {
        newNode->next = head;
        tail->next = newNode;
        head = newNode;
    }
    else
    {
        Node *current = head;
        int currentIdx = 0;

        while (current->next != head && currentIdx < newNodeIdx - 1)
        {
            current = current->next;
            currentIdx++;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
};

void deletion(Node *&head)
{
    int deletedIdx;

    cout << "Enter position to be deleted: ";
    cin >> deletedIdx;

    Node *tail = findTail(head);

    if (head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    if (deletedIdx == 0)
    {
        Node *temp = head; // save old head
        tail->next = head->next;
        head = head->next; // move head forward
        delete temp;       // free old head
    }
    else
    {
        Node *current = head;
        int currentIdx = 0;

        while (current->next != head && currentIdx < deletedIdx - 1)
        {
            current = current->next;
            currentIdx++;
        }

        Node *deletedNode = current->next; // node to remove
        current->next = deletedNode->next; // skip over it
        delete deletedNode;                // free memory
    }
}

void display_list(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    Node *current = head;
    do
    {
        cout << current->name << endl;
        current = current->next;
    } while (current != head);
    cout << current->name << endl;
};

int main()
{
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();

    node1->name = "Ali";
    node2->name = "Ben";
    node3->name = "Chua";
    node4->name = "Danish";

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;

    cout << "=== Circular Linked List ===" << endl;

    cout << "--- Insertion ---" << endl;
    insertion(node1);
    cout << endl;

    cout << "--- Deletion ---" << endl;
    deletion(node1);
    cout << endl;

    cout << "--- Display List ---" << endl;
    display_list(node1);
    cout << endl;

    return 0;
}
