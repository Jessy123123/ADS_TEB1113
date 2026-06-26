#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next = NULL;
    Node *prev = NULL;
};

Node *findTail(Node *head)
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

    cout << "Enter value to be inserted: ";
    cin >> newNode->name;
    cout << "Enter position to be inserted: ";
    cin >> newNodeIdx;

    if (head == NULL)
    {
        newNode->next = newNode;
        newNode->prev = newNode; // points to itself
        head = newNode;
        return;
    }

    Node *tail = findTail(head);

    if (newNodeIdx == 0)
    {
        newNode->next = head;
        newNode->prev = tail;
        tail->next = newNode;
        head->prev = newNode;
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

        // insert after current
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

void deletion(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

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
        Node *temp = head;
        tail->next = head->next;
        head->next->prev = tail; // new head's prev = tail
        head = head->next;
        delete temp;
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

        if (currentIdx < deletedIdx - 1)
        {
            cout << "Position out of range" << endl;
            return;
        }

        Node *deletedNode = current->next;
        current->next = deletedNode->next;
        deletedNode->next->prev = current; // fix prev of node after deleted
        delete deletedNode;
    }
}

void display_list(Node *head)
{
    if (head == NULL)
    {
        cout << "Empty list" << endl;
        return;
    }

    // forward
    cout << "Forward:  ";
    Node *current = head;
    do
    {
        cout << current->name;
        if (current->next != head)
            cout << " -> ";
        current = current->next;
    } while (current != head);
    cout << endl;

    // backward, start from tail
    cout << "Backward: ";
    Node *tail = findTail(head);
    current = tail;
    do
    {
        cout << current->name;
        if (current->prev != tail)
            cout << " -> ";
        current = current->prev;
    } while (current != tail);
    cout << endl;
}

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

    // next pointers
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node1;

    // prev pointers
    node1->prev = node4;
    node2->prev = node1;
    node3->prev = node2;
    node4->prev = node3;

    cout << "=== Doubly Linked List ===" << endl;

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