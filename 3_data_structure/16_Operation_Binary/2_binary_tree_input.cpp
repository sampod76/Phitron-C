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

Node *input_tree(Node *root)
{
    if (root == NULL)
    {
        cout << "No Tree";
        return;
    }
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) // q.empty() ==false
    {
        // get out from queue
        Node *p = q.front();
        q.pop();
        //
    }
};
int main()
{
    Node *root = NULL;

    return 0;
}