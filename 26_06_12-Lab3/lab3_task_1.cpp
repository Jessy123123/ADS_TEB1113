#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next; // pointer
};

void insertion(Node *&head)
{
    int newNodeIdx;
    Node *newNode = new Node();

    cout << "Enter value to be inseted: ";
    cin >> newNode->name;
    cout << "Enter position to be inserted: ";
    cin >> newNodeIdx;

    if (newNodeIdx == 0)
    {
        newNode->next = head;
        head = newNode; // update head
    }
    else
    {
        Node *current = head;
        int currentIdx = 0;

        while (current != NULL && currentIdx < newNodeIdx - 1)
        {
            current = current->next;
            currentIdx++;
        }

        if (current == NULL)
        {
            cout << "Position out of range" << endl;
            delete newNode;
            return;
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

    if (deletedIdx == 0)
    {
        Node *temp = head; // save old head
        head = head->next; // move head forward
        delete temp;       // free old head
    }
    else
    {
        Node *current = head;
        int currentIdx = 0;

        while (current != NULL && currentIdx < deletedIdx - 1)
        {
            current = current->next;
            currentIdx++;
        }

        if (current == NULL || current->next == NULL)
        {
            cout << "Position out of range" << endl;
            return;
        }

        Node *deletedNode = current->next; // node to remove
        current->next = deletedNode->next; // skip over it
        delete deletedNode;                // free memory
    }
}

void display_list(Node *node1)
{

    Node *head = node1;
    while (head != NULL)
    {
        cout << head->name << endl;
        // head->name = Ben
        // head->next = node3
        head = head->next;
    }
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

    cout << "--- Insertion ---" << endl;
    insertion(node1);

    cout << "--- Deletion ---" << endl;
    deletion(node1);

    cout << "--- Display List ---" << endl;
    display_list(node1);

    return 0;
}

// #include <iostream>
// #include <string>
// using namespace std;

// struct Node
// {
//     string name;
//     Node *next; // pointer
// };

// int main()
// {
//     Node node1, node2, node3, node4;

//     node1.name = "Ali";
//     node2.name = "Ben";
//     node3.name = "Chua";
//     node4.name = "Danish";

//     cout << node1.name << endl;
//     cout << node2.name << endl;
//     cout << node3.name << endl;
//     cout << node4.name << endl;

//     node1.next = &node2;
//     node2.next = &node3;
//     node3.next = &node4;
//     node4.next = nullptr;

//     string target = "Chua";
//     Node *current = &node1;
//     bool found = false;

//     while (current != nullptr)
//     {
//         if (current->name == target)
//         {
//             cout << "Found: " << current->name << " " << current->next << endl;
//             found = true;
//             break;
//         }
//         current = current->next;
//     }

//     if (!found)
//     {
//         cout << target << " not found in the list." << endl;
//     }

//     return 0;
// }