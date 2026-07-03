#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *node1 = new Node();
    Node *node2 = new Node();
    Node *node3 = new Node();
    Node *node4 = new Node();

    node1->data = 3;
    node2->data = 2;
    node3->data = 4;
    node4->data = 1;

    node1->left = node2;  // 3 > 2
    node1->right = node3; // 3 < 4
    node2->left = node4;  // 2 > 1

    cout << "Inorder   : ";
    inorder(node1);
    cout << endl;

    cout << "Preorder  : ";
    preorder(node1);
    cout << endl;

    cout << "Postorder : ";
    postorder(node1);
    cout << endl;

    return 0;
}