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
// input= 8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1 7

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
bool isNodePresent(Node *root, int val)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->value == val)
    {
        return true;
    }
    bool left = isNodePresent(root->left, val);
    bool right = isNodePresent(root->right, val);
    if (left == true || right == true)
    {

        return true;
    }
    else
    {
        return false;
    }
    // return left || right
};
int main()
{
    Node *root = input_tree();
    bool isExist = isNodePresent(root, 10000);
    if (isExist)
        cout << "Found";
    else
        cout << "Not Found";
    return 0;
}