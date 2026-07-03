#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

int main()
{
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();

    node1->data = 1;
    node2->data = 2;
    node3->data = 3;
    node4->data = 4;

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;

    //        1
    //       / \
    //      2   3
    //     /
    //    4

    // Inorder: Left -> Root -> Right
    cout << "Inorder   : ";
    cout << node4->data << " "; // 4
    cout << node2->data << " "; // 2
    cout << node1->data << " "; // 1
    cout << node3->data << " "; // 3
    cout << endl;

    // Preorder: Root -> Left -> Right
    cout << "Preorder  : ";
    cout << node1->data << " "; // 1
    cout << node2->data << " "; // 2
    cout << node4->data << " "; // 4
    cout << node3->data << " "; // 3
    cout << endl;

    // Postorder: Left -> Right -> Root
    cout << "Postorder : ";
    cout << node4->data << " "; // 4
    cout << node2->data << " "; // 2
    cout << node3->data << " "; // 3
    cout << node1->data << " "; // 1
    cout << endl;

    return 0;
}