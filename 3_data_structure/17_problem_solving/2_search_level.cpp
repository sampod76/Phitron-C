#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph048/video/ph048-19_3-node-level
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
//
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
// 1 2 3 -1 -1 -1  6 -1 -1
int nodeLevel(Node *root, int searchValue)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<pair<Node *, int>> pairQueue;
    pairQueue.push({root, 1}); // normaly lavel start 0 but question deside lavel start 1

    while (!pairQueue.empty())
    {
        // bar kora anta hoba
        pair<Node *, int> currentPair = pairQueue.front();
        pairQueue.pop();
        Node *node = currentPair.first;
        int level = currentPair.second;
        // kag korta hoba
        if (node->value == searchValue)
        {
            return level;
        }
        // children push
        if (node->left)
            pairQueue.push({node->left, level + 1});
        if (node->right)
            pairQueue.push({node->right, level + 1});
    }
    return 0;
};
// https://phitron.io/ph048/video/ph048-19_3-node-level
int main()
{
    Node *root = input_tree();
    // printLevelOrder(root);
    int findLevel = nodeLevel(root, 99);
    cout << findLevel << endl;
    return 0;
}