// https://phitron.io/ph048/video/ph048-18_1-level-order-traversal-theory
/*
STEP:
1️⃣ প্রতিটি লেয়ারের সব Node গুলোকে Queue তে রাখবো (শুরুতে Root থাকবে)।
2️⃣ Queue থেকে একটি Node বের করবো (Front থেকে) এবং সেই Node নিয়ে কাজ করবো (যেমন: print)।
3️⃣ কাজ শেষ হলে সেই Node কে Queue থেকে remove করবো, তারপর ওই Node এর যদি left ও right child থাকে তাহলে সেগুলোকে আবার Queue তে push করবো।
4️⃣ এভাবে Queue খালি না হওয়া পর্যন্ত process চলতে থাকবে।

TREE:

                    (10)
                   /    \
                (20)    (30)
                /       /   \
              (40)    (50)  (60)


TERMINAL:
✓ 10
✓ 20
✓ 30
✓ 40
✓ 50
✓ 60


VISITED BOX (Queue):
[10] [20] [30] [40] [50] [60]
*/
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
void level_order(Node *root)
{
    if (root != NULL)
    {
        cout << "No Tree" << endl;
        return;
    }
    // ১️⃣ একটি Queue তৈরি করলাম (Node pointer রাখবে)
    queue<Node *> q;
    // ২️⃣ প্রথমে Root Node কে Queue তে push করলাম
    q.push(root);

    // ৩️⃣ যতক্ষণ পর্যন্ত Queue খালি না হয়
    while (!q.empty())
    {
        //  Queue এর সামনে (front) থাকা Node নিলাম
        Node *f = q.front();
        // ৫️⃣ Node টি Queue থেকে remove করলাম
        q.pop();
        // Node এর value print করলাম (এখানেই কাজ করছি)
        cout << f->value << " ";
        //  যদি left child থাকে তাহলে Queue তে push করবো
        if (f->left)
        {
            q.push(f->left);
        }
        //  যদি right child থাকে তাহলে Queue তে push করবো
        if (f->right)
        {
            q.push(f->right);
        }
    }
}
int main()
{

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
    level_order(root);
    return 0;
}