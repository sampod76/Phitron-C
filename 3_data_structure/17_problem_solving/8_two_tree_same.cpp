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

Node *buildTreeFromVector(vector<int> &v)
{
    if (v.empty() || v[0] == -1)
        return NULL;

    Node *root = new Node(v[0]);
    queue<Node *> q;
    q.push(root);

    int i = 1;

    while (!q.empty() && i < v.size())
    {
        Node *current = q.front();
        q.pop();

        // left child
        if (i < v.size() && v[i] != -1)
        {
            current->left = new Node(v[i]);
            q.push(current->left);
        }
        i++;

        // right child
        if (i < v.size() && v[i] != -1)
        {
            current->right = new Node(v[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// https://leetcode.com/problems/same-tree/
bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL)
        return false;
    if (q == NULL)
        return false;

    if (p->value != q->value)
        return false;
    bool l = isSameTree(p->left, q->left);
    bool r = isSameTree(p->right, q->right);
    return l && r;
};
int main()
{
    vector<int> v1 = {1, 2};

    vector<int> v2 = {1, -1, 2};

    Node *root1 = buildTreeFromVector(v1);
    Node *root2 = buildTreeFromVector(v2);

    bool isSame = isSameTree(root1, root2);
    cout << (isSame ? "true" : "false");
    return 0;
}