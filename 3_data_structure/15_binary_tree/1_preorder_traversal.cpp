#include <bits/stdc++.h>
using namespace std;

// ==========================================
// Binary Tree Node Class
// ==========================================
class Node
{
public:
    int value;   // নোডের ভিতরের ডাটা
    Node *left;  // বাম চাইল্ড
    Node *right; // ডান চাইল্ড

    // Constructor → নোড তৈরি হলে এই ফাংশন রান হবে
    Node(int val)
    {
        this->value = val;  // নোডে ডাটা সেট করা
        this->left = NULL;  // শুরুতে কোনো left child নেই
        this->right = NULL; // শুরুতে কোনো right child নেই
    }
};

// ==========================================
// Inorder Traversal Function
// নিয়ম:Root →  Left → Right
// ==========================================
void preorder(Node *root)
{
    // Base Case:
    if (root == NULL)
        return;

    // Step 1: আগে Root প্রিন্ট করবে
    cout << root->value << " ";

    // Step 2: তারপর বাম সাবট্রি ট্রাভার্স করবে
    preorder(root->left);

    // Step 3: তারপর ডান সাবট্রি ট্রাভার্স করবে
    preorder(root->right);
}

int main()
{
    // ==========================================
    // Manual Tree তৈরি করছি
    // ==========================================

    Node *root = new Node(10); // Root Node

    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);

    // Tree Link তৈরি করা হচ্ছে
    root->left = a;  // 10 এর বাম পাশে 20
    root->right = b; // 10 এর ডান পাশে 30

    a->left = c; // 20 এর বাম পাশে 40

    b->left = d;  // 30 এর বাম পাশে 50
    b->right = e; // 30 এর ডান পাশে 60

    /*
            Final Tree Structure:

                 10
               /    \
             20      30
            /       /  \
          40      50    60
    */

    // preorder Traversal কল করা হচ্ছে
    preorder(root);

    /*
        Expected Output:
        40 20 10 50 30 60

        কারণ:
        Left → Root → Right
    */

    return 0;
}