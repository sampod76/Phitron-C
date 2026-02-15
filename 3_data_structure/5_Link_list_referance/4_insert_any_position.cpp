#include <bits/stdc++.h>

using namespace std;
// https://phitron.io/ph048/video/ph048-5_6-insert-at-any-position
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
void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}
// নির্দিষ্ট position (idx) এ নতুন node ঢোকানোর ফাংশন
void insert_at_pos(Node *head, int idx, int value)
{
    // temp pointer দিয়ে আমরা list traverse করবো
    Node *temp = head;
    // নতুন node তৈরি করা হলো
    Node *newNode = new Node(value);
    // যদি list ফাঁকা হয়
    if (head == NULL)
    {
        head = newNode; // নতুন node কে head বানানো
        return;         // কাজ শেষ
        // ⚠️ কিন্তু এখানে সমস্যা আছে:
        // head pass হয়েছে by value, তাই বাইরে head পরিবর্তন হবে না
    }
    // temp কে idx-1 position এ নিয়ে যাওয়ার জন্য loop
    // কারণ আমরা temp এর পরে নতুন node বসাবো
    for (int i = 0; i < idx - 1; i++)
    {
        temp = temp->next; // পরের node এ যাওয়া
    }
    // নতুন node এর next কে temp এর next এর সাথে যুক্ত করা
    newNode->next = temp->next;
    // temp এর next কে newNode বানানো
    temp->next = newNode;
}
int main()
{
    Node *head = new Node(39);
    Node *a = new Node(47);
    Node *b = new Node(65);
    Node *c = new Node(77);
    head->next = a;
    a->next = b;
    b->next = c;

    insert_at_pos(head, 1, 90);
    insert_at_pos(head, 1, 41);
    insert_at_pos(head, 2, 63);
    insert_at_pos(head, 1, 45);
    insert_at_pos(head, 3, 58);
    print_linked_list(head);

    return 0;
}