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

void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "No tree";
        return;
    }
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        // 1 ) bar korta hoba
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        // 2. kag korta hoba
        cout << currentNode->value << " ";
        if (currentNode->left)
            nodeQueue.push(currentNode->left);
        if (currentNode->right)
            nodeQueue.push(currentNode->right);
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
void preorder(Node *root, vector<int> &pre_v)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        pre_v.push_back(root->value);
    }
    preorder(root->left, pre_v);
    preorder(root->right, pre_v);
};
bool leafSimilar(Node *root1, Node *root2)
{
    vector<int> rv;
    vector<int> rv2;
    preorder(root1, rv);
    preorder(root2, rv2);
    return rv == rv2;
};
int main()
{
    vector<int> v1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4, -1, -1, -1, -1, -1, -1};

    vector<int> v2 = {3, 5, 1, 6, 7, 4, 2, -1, -1, -1, -1, -1, -1, 9, 8, -1, -1, -1, -1};

    Node *root1 = buildTreeFromVector(v1);
    Node *root2 = buildTreeFromVector(v2);

    bool leaf = leafSimilar(root1, root2);
    cout << (leaf ? "true" : "false");
    return 0;
}