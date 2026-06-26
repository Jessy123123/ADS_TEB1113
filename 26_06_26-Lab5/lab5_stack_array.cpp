#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

class Stack
{
public:
    string data[MAX];
    int top;

    Stack()
    {
        top = -1; // -1 means empty
    }
};

void push(Stack &s)
{
    if (s.top == MAX - 1)
    {
        cout << "Stack is full!" << endl;
        return;
    }
    cout << "Enter name to push: ";
    cin >> s.data[++s.top]; // increment top first, then insert
}

void pop(Stack &s)
{
    if (s.top == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Popped: " << s.data[s.top] << endl;
    s.top--; // just move top down, no need to delete
}

void peek(Stack &s)
{
    if (s.top == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Top: " << s.data[s.top] << endl;
}

void display(Stack &s)
{
    if (s.top == -1)
    {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack (top → bottom): ";
    for (int i = s.top; i >= 0; i--)
    { // print from top down
        cout << s.data[i];
        if (i > 0)
            cout << " → ";
    }
    cout << endl;
}

int main()
{
    Stack s;

    push(s);
    push(s);
    push(s);

    cout << "--- Display ---" << endl;
    display(s);

    cout << "--- Peek ---" << endl;
    peek(s);

    cout << "--- Pop ---" << endl;
    pop(s);
    pop(s);

    cout << "--- Display After Pop ---" << endl;
    display(s);

    return 0;
}