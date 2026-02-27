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
Node *input_node()
{
    int val;
    cin >> val;
    Node *root = NULL;
    if (val == -1)
    {
        //
        cout << "No tree";
        return root;
    }
    root = new Node(val);
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        // bar kora nite hoba
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        // kag kortahoba
        int leftVal, rightVal;
        cin >> leftVal >> rightVal;
        Node *leftNode, *rightNode;
        if (leftVal == -1)
            leftNode = NULL;
        else
            leftNode = new Node(leftVal);
        if (rightVal == -1)
            rightNode = NULL;
        else
            rightNode = new Node(rightVal);
        //
        currentNode->left = leftNode;
        currentNode->right = rightNode;
        if (currentNode->left)
            nodeQueue.push(currentNode->left);
        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }
};
int main()
{
    Node *root = NULL;

    return 0;
}