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
// see after 58 min => https://phitron.io/conceptual-session/693d56dc43d01294b342f8a3
// 1 2 3 4 -1 2 5 -1 -1 3 -1 -1 -1 -1 -1
/* // output
1 3 5
1 2 4
 */
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
void leftOuterView(Node *root)
{
    if (root == NULL)
    {
        cout << "No tree";
        return;
    };
    cout << root->value << " ";
    if (root->left)
    {
        leftOuterView(root->left);
    }
    else if (root->right)
    {
        leftOuterView(root->right);
    }
};
int main()
{
    Node *root = input_tree();
    rightOuterView(root);
    cout << endl;
    leftOuterView(root);

    return 0;
}

/*
              1
           /     \
          2       3
         /       /   \
        4       2     5
               /
              3
*/
