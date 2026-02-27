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
// https://leetcode.com/problems/univalued-binary-tree/
int firstVal = NULL;
bool isUnivalTree(Node *root)
{

    if (root == NULL)
    {
        return true;
    }
    if (!firstVal)
    {
        firstVal = root->value;
    }
    if (root->value != firstVal)
    {
        return false;
    }
    bool left = isUnivalTree(root->left);
    bool right = isUnivalTree(root->right);
    if (left == false || right == false)
    {
        return false;
    }
    else
    {
        return true;
    }
};
int main()
{
    Node *root = input_tree();
    bool unival = isUnivalTree(root);
    if (unival)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
    return 0;
}