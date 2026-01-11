#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        next = NULL;
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
};
void insert_at_tail(Node *head, int value)

{
    // 3. নতুন node তৈরি করা
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    // 1. temp pointer দিয়ে head থেকে traversal শুরু
    Node *temp = head;
    // 2. যতক্ষণ পর্যন্ত শেষ node না পাওয়া যায়, ততক্ষণ সামনে এগোবে
    // শেষ node মানে যার next == NULL
    while (temp->next != NULL)
    {
        temp = temp->next; // পরের node এ যাওয়া
    }
    // 4. শেষ node এর next এ নতুন node এর address বসানো
    temp->next = newNode;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(50);
    Node *b = new Node(20);
    head->next = a; // 10 → 50
    a->next = b;    // 50 → 20

    insert_at_tail(head, 100);
    insert_at_tail(head, 500);

    // পুরো linked list প্রিন্ট
    print_linked_list(head);
    return 0;
}