
#include <bits/stdc++.h>

#define ll long long int
#define all(x) x.begin(), x.end()
#define nl '\n'
#define fastIO()                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0)

using namespace std;

#ifndef ONLINE_JUDGE
// #include "../DebugTemplate/debug.h"
#else
#define debug(x...)
#define dbgsize(x)
#endif
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
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
    {
        root = NULL;
        return root;
    }
    root = new Node(val);
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    //
    while (!nodeQueue.empty())
    {
        // bar korta hoba;
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        //
        int leftValue, rightValue;
        cin >> leftValue >> rightValue;
        Node *leftNode, *rightNode;
        if (leftValue == -1)
        {
            leftNode = NULL;
        }
        else
        {
            leftNode = new Node(leftValue);
        }
        //
        if (rightValue == -1)
        {
            rightNode = NULL;
        }
        else
        {
            rightNode = new Node(rightValue);
        }
        //
        currentNode->left = leftNode;
        currentNode->right = rightNode;
        if (currentNode->left)
            nodeQueue.push(currentNode->left);
        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }
    return root;
}

int count_node(Node *root)
{
    if (root == NULL)
        return 0;
    int l = count_node(root->left);
    int r = count_node(root->right);
    return l + r + 1;
};
// 40 min after see-->  https://phitron.io/conceptual-session/693d56dc43d01294b342f8a3
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1
int max_depth(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == 0) // 0 - base --> mines Edge/connection count
        return 0;
    int l = max_depth(root->left);
    int r = max_depth(root->right);
    return max(l, r) + 1;
};
int main()
{
    fastIO();
    Node *root = input_tree();
    int totalNode = count_node(root);

    int maxDepthNode = max_depth(root);
    /*
    Perfect Binary Tree formula:

    Total Nodes = 2^(h+1) - 1

    where,
    h = max depth (0-based)
    */
    int formulaTotal = pow(2, maxDepthNode + 1) - 1;
    if (totalNode == formulaTotal)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}