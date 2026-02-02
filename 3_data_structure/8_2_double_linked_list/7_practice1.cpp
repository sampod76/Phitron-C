#include <bits/stdc++.h>
// https://phitron.io/ph048/video/ph048-8_9-insert-at-any-position
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
}
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
void compair(Node *head, Node *head2)
{
    Node *temp1 = head;
    Node *temp2 = head2;
    bool isSame = true;
    while (temp1 != NULL)
    {
        if (temp2 == NULL)
        {
            isSame = false;
            break;
        }
        if (temp1->value != temp2->value)
        {
            isSame = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1 = head;
    temp2 = head2;
    while (temp2 != NULL)
    {
        if (temp1 == NULL)
        {
            isSame = false;
            break;
        }
        if (temp2->value != temp1->value)
        {
            isSame = false;
            break;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    if (isSame)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_at_tail(head, tail, value);
    }
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, value);
    }
    compair(head, head2);
    // print_forward(head);
    // print_forward(head2);

    return 0;
}