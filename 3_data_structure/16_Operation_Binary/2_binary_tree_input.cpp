#include <bits/stdc++.h>
using namespace std;
// https://phitron.io/ph048/video/ph048-18_5-binary-tree-input-implementation
/*
        10
       /  \
     20    30
    /     /  \
  40     50   60
*/
// input = 10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1
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

// ===============================
// Build Tree (Level Order Input)
// ===============================
Node *buildTree()
{
    int rootValue;
    cin >> rootValue;
    Node *root;
    if (rootValue == -1)
    {
        // cout << "No tree";
        return root = NULL;
    }

    root = new Node(rootValue);
    queue<Node *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        // 1) nodeQueue to get first / front
        Node *currentNode = nodeQueue.front(); // store
        nodeQueue.pop();                       // remove form queue
        //
        int leftValue, rightValue; // scan , 2 value
        cin >> leftValue >> rightValue;

        Node *leftChild;
        Node *rightChild;

        // Create left child
        if (leftValue == -1)
            leftChild = NULL;
        else
            leftChild = new Node(leftValue);

        // Create right child
        if (rightValue == -1)
            rightChild = NULL;
        else
            rightChild = new Node(rightValue);
        // connented primary node
        currentNode->left = leftChild;
        currentNode->right = rightChild;
        // push node queue
        if (currentNode->left)
            nodeQueue.push(currentNode->left);

        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }

    return root;
}

// ===============================
// Level Order Traversal Print
// ===============================
void printLevelOrder(Node *root)
{
    if (root == NULL)
        return;

    queue<Node *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();

        cout << currentNode->value << " ";

        if (currentNode->left)
            nodeQueue.push(currentNode->left);

        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }
}

int main()
{
    Node *root = buildTree();
    printLevelOrder(root);
    return 0;
}