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
int max_height(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == 0) // 0 - base --> mines Edge/connection count
        return 0;
    int l = max_height(root->left);
    int r = max_height(root->right);
    return max(l, r) + 1;
};
void printLevel(Node *root, int level)
{
    vector<int> lv;
    if (root == NULL)
    {
        cout << "No tree";
        return;
    }

    queue<pair<Node *, int>> nodePairQueue;
    nodePairQueue.push({root, 0});
    while (!nodePairQueue.empty())
    {
        // bar korta hoba
        pair<Node *, int> currentNodePair = nodePairQueue.front();
        Node *currentNode = currentNodePair.first;
        int currentLevel = currentNodePair.second;
        nodePairQueue.pop();
        // kga korta hoba
        if (currentLevel == level)
        {
            cout << currentNode->value << " ";
            lv.push_back(currentNode->value);
        }
        if (currentNode->left)
        {
            nodePairQueue.push({currentNode->left, currentLevel + 1});
        }
        if (currentNode->right)
        {
            nodePairQueue.push({currentNode->right, currentLevel + 1});
        }
    }
};
int main()
{
    int level;
    cin >> level;
    Node *root = input_tree();
    int maxHight = max_height(root);
    if (level > maxHight) // overflow
    {
        cout << "Invalid";
        return 0;
    }
    printLevel(root, level);
    return 0;
}