#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    Node *prev;
    int value;
    Node *next;
    Node(int val)
    {
        this->prev = NULL;
        this->value = val;
        this->next = NULL;
    }
};
void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
};
void print_backward(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->prev;
    }
    cout << endl;
};
void insert_into_head(Node *&head, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
};
void insert_into_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    // যদি লিস্ট ফাঁকা হয়
    if (tail == NULL || head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insert_into_any_pos_advance(Node *&head, Node *&tail, int idx, int value)
{
    if (idx < 0)
        return;
    // ❌ নেগেটিভ index হলে কিছুই করবো না

    Node *newNode = new Node(value);

    // 🟡 Case 1: লিস্ট ফাঁকা
    if (head == NULL)
    {
        if (idx == 0)
            head = tail = newNode;
        // ✔ ফাঁকা লিস্টে প্রথম নোড ইনসার্ট
        else
            delete newNode;
        // ❌ ফাঁকা লিস্টে 0 ছাড়া অন্য index invalid
        return;
    }

    // 🟢 Case 2: Head এ ইনসার্ট (idx = 0)
    if (idx == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        // ✔ নতুন নোডটাই এখন head
        return;
    }

    // 🔵 Case 3: (idx - 1) পজিশন পর্যন্ত যাওয়া
    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        if (temp->next == NULL)
        {
            delete newNode;
            // ❌ লিস্টের length এর বাইরে index
            return;
        }
        temp = temp->next;
    }

    // 🟣 Case 4: Tail এ ইনসার্ট (idx == length)
    if (temp->next == NULL)
    {
        newNode->prev = temp;
        temp->next = newNode;
        tail = newNode;
        // ✔ নতুন নোডটাই এখন tail
    }
    // 🟠 Case 5: মাঝখানে ইনসার্ট
    else
    {
        newNode->prev = temp;
        newNode->next = temp->next;

        temp->next->prev = newNode;
        temp->next = newNode;
        // ✔ আগের ও পরের দুই দিকেই link ঠিক করা
    }
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *tail = new Node(50);
    head->next = a;
    a->prev = head;
    //
    a->next = tail;
    tail->prev = a;
    insert_into_head(head, 44);
    insert_into_tail(head, tail, 99);
    print_forward(head);
    print_backward(tail);
    return 0;
}