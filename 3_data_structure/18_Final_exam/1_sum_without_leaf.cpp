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

int sumWithoutLeaf(Node *root)
{
    if (root == NULL)
        return 0;

    int total = 0;
    queue<Node *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        // BAR KORTA HOBA
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        //
        if (currentNode->left == NULL && currentNode->right == NULL)
        { // leaf node
          // Skip leaf node
        }
        else
        {
            total += currentNode->value;
        }
        // children push
        if (currentNode->left)
            nodeQueue.push(currentNode->left);
        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }
    return total;
};

/*
int total = 0;
void sumWithoutLeaf(Node *root)
{
    if (root == NULL)
        return;

    if (root->left != NULL || root->right != NULL)
    {

        total += root->value;
    }

        // if (root->left == NULL && root->right == NULL) // leaf node then skip
        // {

        //     // skip
        // }
        // else
        // {
        //     // cout << root->value << " ";
        //     total += root->value;
        // }

    sumWithoutLeaf(root->left);
    sumWithoutLeaf(root->right);
};
*/
int main()
{
    Node *root = input_tree();
    // cout << root->value;
    int total = sumWithoutLeaf(root);
    cout << total;
    return 0;
}