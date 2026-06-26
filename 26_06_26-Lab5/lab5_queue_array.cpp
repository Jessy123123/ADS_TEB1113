#include <iostream>
#include <string>
using namespace std;

const int MAX = 5;

class Queue
{
public:
    string data[MAX];
    int front;
    int rear;

    Queue()
    {
        front = 0;
        rear = 0;
    }
};

void enqueue(Queue &q)
{
    if (q.rear == MAX)
    { // rear hit the end
        cout << "Queue is full!" << endl;
        return;
    }
    cout << "Enter name to enqueue: ";
    cin >> q.data[q.rear];
    q.rear++;
}

void dequeue(Queue &q)
{
    if (q.front == q.rear)
    { // front caught up to rear = empty
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Dequeued: " << q.data[q.front] << endl;
    q.front++;
}

void display(Queue &q)
{
    if (q.front == q.rear)
    {
        cout << "Queue is empty!" << endl;
        return;
    }
    cout << "Queue (front -> rear): ";
    for (int i = q.front; i < q.rear; i++)
    {
        cout << q.data[i];
        if (i < q.rear - 1)
            cout << " -> ";
    }
    cout << endl;
}

int main()
{
    Queue q;

    enqueue(q); // Ali
    enqueue(q); // Ben
    enqueue(q); // Chua

    display(q);

    dequeue(q); // removes Ali
    dequeue(q); // removes Ben

    display(q);

    return 0;
}