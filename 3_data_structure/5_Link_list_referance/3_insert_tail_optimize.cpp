#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};
void print_link_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}
// https://phitron.io/ph048/video/ph048-5_9-insert-at-tail-optimized
/*
    insert_at_tail ফাংশন (Optimized):
    এখানে আমরা tail ব্যবহার করছি, তাই O(1) টাইমে insert হয়।

    Node *head  → list এর প্রথম Node
    Node *&tail → list এর শেষ Node (reference হিসেবে নেওয়া হয়েছে, যাতে main এও update হয়)
    int value   → নতুন Node এর মান
*/
void insert_at_tail(Node *head, Node *&tail, int value)
{
    Node *newNode = new Node(value); // নতুন Node তৈরি

    // যদি Linked List খালি হয়
    if (head == NULL)
    {
        head = newNode; // head এখন newNode হবে
        tail = newNode; // tail ও newNode হবে
        return;
    }

    // সাধারণ অবস্থায়:
    tail->next = newNode; // বর্তমান tail এর next এ নতুন Node বসানো
    tail = newNode;       // tail কে নতুন Node এ update করা
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(50);
    Node *tail = new Node(600); // c is last i will be name tail
    head->next = a;
    a->next = b;
    b->next = tail;
    insert_at_tail(head, tail, 100);
    insert_at_tail(head, tail, 5070);
    print_link_list(head);
    cout << "Main tail->" << tail->value;
    return 0;
}