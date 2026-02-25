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
// 10 20 30 40 -1 50 60 -1 -1 -1 -1 -1 -1
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
    while (!nodeQueue.empty())
    {
        // bar korata hoba queue
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        // kag start
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
        currentNode->left = leftNode;
        currentNode->right = rightNode;
        // childreen push
        if (currentNode->left)
            nodeQueue.push(currentNode->left);
        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }
    return root;
};
void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        // bar kora anta hoba
        Node *currentNode = nodeQueue.front();
        nodeQueue.pop();
        // kag kora hoba
        cout << currentNode->value << " ";
        // children push
        if (currentNode->left)
            nodeQueue.push(currentNode->left);
        if (currentNode->right)
            nodeQueue.push(currentNode->right);
    }
};
// যে Node এর কোনো left child এবং right child নেই, তাকে Leaf Node বলে।
/*
            10
           /  \
         20    30
        /      /  \
      40      50   60

এখানে Leaf Node গুলো হলো: 40, 50, 60
মোট Leaf = 3
 */
int count_leaf_nodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    // যদি বর্তমান node এর left এবং right child দুটোই NULL হয়
    // তাহলে এটা একটি Leaf Node
    // তাই 1 return করবে
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    int leaf = count_leaf_nodes(root->left);
    int right = count_leaf_nodes(root->right);
    return leaf + right;
};
int main()
{
    Node *root = input_tree();
    // printLevelOrder(root);
    int totalLeafNode = count_leaf_nodes(root);
    cout << totalLeafNode;
    return 0;
}