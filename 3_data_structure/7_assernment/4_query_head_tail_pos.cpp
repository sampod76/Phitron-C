#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    long long value;
    Node *next;
    Node(long long val)
    {
        value = val;
        next = NULL;
    }
};

void print_link_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void insert_at_tail(Node *&head, Node *&tail, long long value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

void insert_at_head(Node *&head, Node *&tail, long long value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void delete_at_any_pos(Node *&head, Node *&tail, int idx)
{
    // যদি লিস্ট খালি থাকে, তাহলে কিছুই করার নেই
    if (head == NULL)
        return;

    // যদি idx = 0 হয়, অর্থাৎ head নোড ডিলিট করতে হবে
    if (idx == 0)
    {
        // যেই নোডটা ডিলিট করবো সেটাকে ধরে রাখলাম
        Node *deleteNode = head;

        // head কে পরের নোডে সরিয়ে দিলাম
        head = head->next;

        // যদি এখন head NULL হয়ে যায়, তার মানে লিস্ট একদম খালি
        // তাই tail-কেও NULL করতে হবে
        if (head == NULL)
            tail = NULL;

        // মেমোরি থেকে নোড ডিলিট করা
        delete deleteNode;
        return;
    }

    // head বাদে অন্য কোনো position ডিলিট করার জন্য
    // traversalNode দিয়ে traversal শুরু করলাম
    Node *traversalNode = head;

    // traversalNode কে (idx-1) তম নোড পর্যন্ত নিয়ে যাবো
    for (int i = 0; i < idx - 1; i++)
    {
        // যদি মাঝপথেই traversalNode->next NULL হয়ে যায়,
        // তাহলে index invalid, তাই কিছুই করবো না
        if (traversalNode->next == NULL)
            return;

        traversalNode = traversalNode->next;
    }

    // আবার চেক করছি, কারণ idx যদি লিস্টের বাইরে হয়
    // তাহলে traversalNode->next NULL হতে পারে | তুমি যেটা ডিলিট করতে চাও, সেটা যদি একদম last index-এর পরের নোড হয়, তাহলে তার কোনো ঠিকানা থাকে না (NULL)। for Loop এর ভিতরে সেটা ধরা পড়ে না, কারণ আমরা traversal করি idx-1 পর্যন্ত। তাই traversalNode ঠিক থাকে, কিন্তু traversalNode->next NULL হয় , not possible delete। এই NULL address ব্যবহার হওয়া থেকে বাঁচানোর জন্যই এই extra check দরকার। যদি লাস্ট ইনডেক্সের পরের ইনডেক্স না হয়ে অন্য যেকোনো ভুল index হতো, তাহলে সেটা for loop-এর ভিতরেই ধরা পড়ে যেত
    if (traversalNode->next == NULL)
        return;

    // যেই নোডটা ডিলিট করবো, সেটাকে ধরলাম
    Node *deleteNode = traversalNode->next;

    // deleteNode কে লিস্ট থেকে বিচ্ছিন্ন করলাম
    traversalNode->next = deleteNode->next;

    // যদি deleteNode-টাই tail হয়,
    // তাহলে tail কে এক ধাপ পিছিয়ে temp এ সেট করতে হবে
    if (deleteNode == tail)
    {

        tail = traversalNode;
    }

    // অবশেষে মেমোরি থেকে নোড ডিলিট
    delete deleteNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int t;
    cin >> t;

    int idx;
    long long value;
    while (t--)
    {
        cin >> idx >> value;

        if (idx == 0)
        {
            insert_at_head(head, tail, value);
        }
        else if (idx == 1)
        {
            insert_at_tail(head, tail, value);
        }
        else if (idx == 2)
        {
            delete_at_any_pos(head, tail, value);
        }

        print_link_list(head);
        cout << endl;
    }

    return 0;
}
