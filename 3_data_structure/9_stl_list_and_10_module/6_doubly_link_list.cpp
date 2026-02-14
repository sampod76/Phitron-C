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
// https://phitron.io/ph048/video/ph048-9_10-reverse-doubly-linked-list
void reverse_doubly_link_list(Node *head, Node *tail)
{
    // two pointer tachnick
    Node *i = head;
    Node *j = tail;
    while (i != j && i->prev != j) // or -> j->next != i
    {
        swap(i->value, j->value);
        i = i->next;
        j = j->prev;
    }

    /* // or sortcut
    for (Node *i = head, *j = tail; i != j &&i->prev = !j; i = i->next, j = j->prev)
     {
         swap(i->value, j->value);
     }
    */
}
int main()
{
    Node *head = NULL;

    Node *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_into_tail(head, tail, value);
    }

    // insert_into_tail(head, tail, 99);
    print_forward(head);
    reverse_doubly_link_list(head, tail);
    print_forward(head);

    return 0;
}