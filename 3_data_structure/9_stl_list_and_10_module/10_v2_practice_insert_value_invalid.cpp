/*
6
0 10
1 20
4 30
0 30
1 40
5 50

--- output ---
10
10
10 20
20 10
Invalid
30 10 20
20 10 30
30 40 10 20
20 10 40 30
Invalid

*/

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

void insert_into_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

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
void insert_at_any_position(Node *&head, int idx, int value)
{
    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(value);
    // cout << temp->value;
    // new node full fillup
    newNode->prev = temp;
    newNode->next = temp->next;
    // temp->next ===> it is new node ar next
    temp->next->prev = newNode; // or newNode.next.prev = newNode
    temp->next = newNode;
};
int main()
{
    int q;
    cin >> q;
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

    while (q--)
    {
        int idx, value;
        cin >> idx >> value;
        if (idx == 0)
        {
            insert_into_head(head, tail, value);
            size++;
            print_forward(head);
            print_backward(tail);
        }
        else if (idx == size)
        {
            insert_into_tail(head, tail, value);
            size++;
            print_forward(head);
            print_backward(tail);
        }
        else if (idx > size)
        {
            cout << "Invalid" << endl;
        }
        else
        {
            insert_at_any_position(head, idx, value);
            size++;
            print_forward(head);
            print_backward(tail);
        }
    }

    return 0;
}