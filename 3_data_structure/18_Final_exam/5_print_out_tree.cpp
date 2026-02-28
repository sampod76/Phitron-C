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
void leftOuterView(Node *root)
{
    if (root == NULL)
    {
        // cout << "No tree";
        return;
    };

    if (root->left)
    {
        leftOuterView(root->left);
    }
    else if (root->right)
    {
        leftOuterView(root->right);
    }
    cout << root->value << " ";
};
void rightOuterView(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    if (root->right)
    {
        rightOuterView(root->right);
    }
    else if (root->left)
    {
        rightOuterView(root->left);
    }
};
int main()
{

    Node *root = input_tree();
    leftOuterView(root->left);
    cout << root->value << " ";
    rightOuterView(root->right);
    return 0;
}