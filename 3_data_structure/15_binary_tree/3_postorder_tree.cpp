#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
};

int main()
{
    Node *root = new Node(10); // Root

    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);

    // Linking (Tree structure তৈরি)
    root->left = a;  // 10 → left = 20
    root->right = b; // 10 → right = 30

    a->left = c; // 20 → left = 40

    b->left = d;  // 30 → left = 50
    b->right = e; // 30 → right = 60
    postorder(root);
    return 0;
}