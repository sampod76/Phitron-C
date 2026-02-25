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
// https://phitron.io/ph048/video/ph048-18_7-count-nodes-in-a-binary-tree
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
int countNode(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = countNode(root->left);
    int right = countNode(root->right);
    return left + right + 1;
};
int main()
{
    Node *root = input_tree();
    int total = countNode(root);
    cout << total;
    return 0;
}