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

    if (head != NULL)
    {
        head = newNode;

        tail = newNode;
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
    print_forward(head);
    print_backward(tail);
    return 0;
}