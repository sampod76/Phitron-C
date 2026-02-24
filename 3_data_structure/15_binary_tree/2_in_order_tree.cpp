// https://phitron.io/ph048/video/ph048-17_11-inorder-traversal
// Inorder Traversal (Left → Root → Right)

#include <bits/stdc++.h>
using namespace std;

// =====================================================
// Node Class → Binary Tree এর প্রতিটি নোডকে represent করে
// =====================================================
class Node
{
public:
    int value;   // নোডের ভিতরে যে ডাটা থাকবে
    Node *left;  // বাম চাইল্ডের pointer
    Node *right; // ডান চাইল্ডের pointer

    // Constructor → নতুন নোড তৈরি করার সময় কল হবে
    Node(int val)
    {
        value = val;  // ডাটা সেট করা
        left = NULL;  // শুরুতে কোনো left child নেই
        right = NULL; // শুরুতে কোনো right child নেই
    }
};

// =====================================================
// Inorder Traversal Function
// Rule: Left → Root → Right
// =====================================================
void inorder(Node *root)
{
    // Base case:
    // যদি root NULL হয় তাহলে কিছুই করবে না (recursion stop condition)
    if (root == NULL)
        return;

    // 1️⃣ প্রথমে বাম সাবট্রি তে যাবে
    inorder(root->left);

    // 2️⃣ তারপর বর্তমান root print করবে
    cout << root->value << " ";

    // 3️⃣ তারপর ডান সাবট্রি তে যাবে
    inorder(root->right);
}

int main()
{
    // =============================
    // Manually Tree তৈরি করছি
    // =============================

    Node *root = new Node(10); // Root

    Node *a = new Node(20);
    Node *b = new Node(30);
    Node *c = new Node(40);
    Node *d = new Node(50);
    Node *e = new Node(60);

    // Linking (Tree structure তৈরি)
    root->left = a;  // 10 → left = 20
    root->right = b; // 10 → right = 30

    a->left = c; // 20 → left = 40

    b->left = d;  // 30 → left = 50
    b->right = e; // 30 → right = 60

    /*
                10
              /    \
            20      30
           /       /  \
         40      50    60
    */

    // Inorder Traversal শুরু
    inorder(root);

    return 0;
}