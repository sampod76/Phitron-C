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
void insert_into_tail(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->prev = tail;
    tail->next = newnode;
    tail = newnode;
};
void insert_into_head(Node *&head, Node *&tail, int value)
{
    Node *newnode = new Node(value);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
};
void print_forward(Node *head)
{
    Node *traversalNode = head;
    cout << "L -> ";
    while (traversalNode != NULL)
    {
        cout << traversalNode->value << " ";
        traversalNode = traversalNode->next;
    }
    cout << endl;
}
void print_backward(Node *tail)
{
    Node *traversalNode = tail;
    cout << "R -> ";
    while (traversalNode != NULL)
    {
        cout << traversalNode->value << " ";
        traversalNode = traversalNode->prev;
    }
    cout << endl;
}
void insert_at_any_mid_position(Node *&head, int idx, int value)
{
    Node *traversalNode = head;
    for (int i = 0; i < idx - 1; i++)
    {
        traversalNode = traversalNode->next;
    }
    Node *newnode = new Node(value);
    newnode->prev = traversalNode;
    newnode->next = traversalNode->next;
    //
    traversalNode->next->prev = newnode;
    traversalNode->next = newnode;
};
int main()
{
    int q;
    cin >> q;
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    while (q--)
    {
        int idx, value;
        cin >> idx >> value;
        if (idx == 0)
        {
            insert_into_head(head, tail, value);
            sz++;
            print_forward(head);
            print_backward(tail);
        }
        else if (idx == sz)
        {
            insert_into_tail(head, tail, value);
            sz++;
            print_forward(head);
            print_backward(tail);
        }
        else if (idx > sz)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            insert_at_any_mid_position(head, idx, value);
            sz++;
            print_forward(head);
            print_backward(tail);
        }
    }

    return 0;
}