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
void insert_at_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insert_into_head(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}
void print_back_forward(Node *tail)
{
    Node *tempTail = tail;
    while (tempTail != NULL)
    {
        cout << tempTail->value << " ";
        tempTail = tempTail->prev;
    }
    cout << endl;
}
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(50);
    Node *tail = new Node(30);
    head->next = a;
    a->prev = head;
    //
    a->next = tail;
    tail->prev = a;
    insert_at_tail(head, tail, 100);
    print_forward(head);
    print_back_forward(tail);
    insert_into_head(head, tail, 321);
    print_forward(head);
    return 0;
}