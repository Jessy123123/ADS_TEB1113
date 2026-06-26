#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string name;
    Node *next;
};

// Stack manages the nodes
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL; // initialize empty
    }

    void push()
    {
        Node *newNode = new Node();
        cout << "Enter name to push: ";
        cin >> newNode->name;

        newNode->next = top; // point to old top
        top = newNode;       // new node is the new top
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node *temp = top;
        cout << "Popped: " << temp->name << endl;
        top = top->next; // move top down
        delete temp;
    }

    void peek()
    {
        if (top == NULL)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top: " << top->name << endl;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node *current = top;
        cout << "Stack (top -> bottom): ";
        while (current != NULL)
        {
            cout << current->name;
            if (current->next != NULL)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;

    s.push();
    s.push();
    s.push();

    cout << "--- Display ---" << endl;
    s.display();

    cout << "--- Peek ---" << endl;
    s.peek();

    cout << "--- Pop ---" << endl;
    s.pop();

    cout << "--- Display After Pop ---" << endl;
    s.display();

    return 0;
}