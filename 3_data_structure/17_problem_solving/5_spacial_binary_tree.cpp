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
/*
প্রশ্নে বলা হয়েছে, একটি Binary Tree “Special” হবে যদি প্রতিটি নোডের ক্ষেত্রে এই শর্তটি মানা হয়—

1) নোডটির কোনো চাইল্ড থাকবে না (০টি চাইল্ড)
অথবা
2) নোডটির দুটি চাইল্ড থাকবে (একটি left এবং একটি right)
অর্থাৎ, কোনো নোডের যদি শুধু একটি চাইল্ড থাকে (শুধু left আছে কিন্তু right নেই, অথবা শুধু right আছে কিন্তু left নেই), তাহলে সেই ট্রি “Special Tree” হবে না।

সুতরাং, যদি ট্রির প্রতিটি নোড এই নিয়ম মেনে চলে, তাহলে সেটি Special Tree — নাহলে Special নয়।
*/
bool isSpecialBinaryTree(Node *root)
{
    if (root == NULL)
        return true;
    //  if ((root->left != NULL && root->right == NULL) ||(root->left == NULL && root->right != NULL))
    if (root->left != NULL && root->right == NULL) //
    {
        return false;
    }
    if (root->left == NULL && root->right != NULL)
    {
        return false;
    }
    bool left = isSpecialBinaryTree(root->left);
    bool right = isSpecialBinaryTree(root->right);

    if (left == false || right == false)
    {
        return false;
    }
    else
    {
        return true;
    }

    // sortcut
};

int main()
{
    Node *root = NULL;

    return 0;
}