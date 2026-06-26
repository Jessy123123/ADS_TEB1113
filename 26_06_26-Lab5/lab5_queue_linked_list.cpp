#include <iostream>
#include <string>
using namespace std;

class Queue
{
public:
    string name;
    Queue *next;
};

void enqueue(Queue *&front, Queue *&rear)
{
    Queue *newNode = new Queue();
    cout << "Enter name to enqueue: ";
    cin >> newNode->name;
    newNode->next = NULL; // always inserted at the end

    if (rear == NULL)
    { // queue was empty
        rear = newNode;
        front = newNode;
    }
    else
    {
        rear->next = newNode; // link old tail to new node
        rear = newNode;       // new node becomes the new tail
    }
}

void dequeue(Queue *&front, Queue *&rear)
{
    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    Queue *temp = front;
    cout << "Dequeued: " << temp->name << endl;
    front = front->next; // move front forward

    if (front == NULL)
    {                // queue is now empty
        rear = NULL; // reset rear too
    }

    delete temp;
}

void display(Queue *front)
{
    if (front == NULL)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    Queue *current = front;
    cout << "Queue (front -> rear): ";
    while (current != NULL)
    {
        cout << current->name;
        if (current->next != NULL)
            cout << " -> ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Queue *front = NULL; // front of queue
    Queue *rear = NULL;  // rear of queue

    enqueue(front, rear);
    enqueue(front, rear);
    enqueue(front, rear);

    cout << "--- Display ---" << endl;
    display(front);

    cout << "--- Dequeue ---" << endl;
    dequeue(front, rear);
    dequeue(front, rear);

    cout << "--- Display After Dequeue ---" << endl;
    display(front);

    return 0;
}