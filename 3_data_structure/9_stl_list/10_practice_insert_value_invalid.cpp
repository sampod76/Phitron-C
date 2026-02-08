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
bool valid_insert(Node *&head, Node *&tail, int idx, int value)
{
    Node *newNode = new Node(value);
    // when head is null and index is 0 then ok
    if (head == NULL)
    {
        if (idx == 0)
        {
            head = newNode;
            tail = newNode;
            return true;
        }
        else
        {
            return false;
        }
    }
    // head is not null many node exist but insert only 0 index
    if (idx == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return true;
    }
    // any middle position insert first get secound last index
    Node *tempLastPreviousNode = head;
    for (int i = 0; i < idx - 1; i++)
    {
        if (tempLastPreviousNode->next == NULL)
        {
            return false;
        }
        tempLastPreviousNode = tempLastPreviousNode->next;
    }
    // solve last index in insert condition
    if (tempLastPreviousNode->next == NULL)
    {
        newNode->prev = tempLastPreviousNode;
        tempLastPreviousNode->next = newNode;
        tail = newNode;
    }
    else
    {

        //
        newNode->prev = tempLastPreviousNode;
        newNode->next = tempLastPreviousNode->next;
        //
        tempLastPreviousNode->next->prev = newNode; // newNode->next->prev= newNode
        tempLastPreviousNode->next = newNode;
    }

    return true;
}
int main()
{
    int q;
    cin >> q;
    Node *head = NULL;
    Node *tail = NULL;

    while (q--)
    {
        int idx, value;
        cin >> idx >> value;
        bool isValidAndInsert = valid_insert(head, tail, idx, value);
        if (isValidAndInsert)
        {
            print_forward(head);
            print_backward(tail);
        }
        else
        {
            cout << "Invalid" << endl;
        }
    }

    return 0;
}