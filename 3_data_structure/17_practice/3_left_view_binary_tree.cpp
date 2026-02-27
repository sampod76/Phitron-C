#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph048/video/ph048-19_4-left-view-of-a-binary-tree
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
// 2 8 7 -1 5 -1 -1 1 -1 -1 -1
// https://phitron.io/ph048/video/ph048-19_4-left-view-of-a-binary-tree
vector<int> getLeftView(Node *root)
{

    // এই vector এ আমরা final Left View এর node গুলো রাখবো
    vector<int> ans;
    // freArray[level] = এই level আগে visited হয়েছে কিনা সেটা track করবে
    // শুরুতে সব false (মানে কোনো level এখনো visited হয়নি)
    int freArray[3001] = {false};
    if (root == NULL)
        return ans;
    //
    queue<pair<Node *, int>> pairQueue;
    pairQueue.push({root, 1});
    //

    while (!pairQueue.empty())
    {
        // bar kora anta hoba
        pair<Node *, int> currentPair = pairQueue.front();
        pairQueue.pop();
        Node *currentNode = currentPair.first;
        int currentLevel = currentPair.second;
        // kag korta hoba
        // যদি এই level আগে কখনো visit না করা হয়ে থাকে
        if (freArray[currentLevel] == false)
        {
            // তাহলে এই node হবে ওই level এর প্রথম node | তাই এটাকে ans এ push করবো (Left View)
            ans.push_back(currentNode->value);
            // এই level এখন visited হিসেবে mark করে দিলাম
            freArray[currentLevel] = true;
        }
        //
        if (currentNode->left)
            pairQueue.push({currentNode->left, currentLevel + 1});
        if (currentNode->right)
            pairQueue.push({currentNode->right, currentLevel + 1});
    }
    return ans;
};
int main()
{
    Node *root = input_tree();
    vector findAns = getLeftView(root);
    for (int val : findAns)
    {
        cout << val << " ";
    }
    return 0;
}