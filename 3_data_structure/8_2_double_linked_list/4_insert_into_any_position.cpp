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
// https://phitron.io/ph048/video/ph048-8_9-insert-at-any-position
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
    Node *head = new Node(10);
    Node *a = new Node(50);
    Node *tail = new Node(30);
    head->next = a;
    a->prev = head;
    //
    a->next = tail;
    tail->prev = a;

    insert_at_any_position(head, 2, 100);
    print_forward(head);

    return 0;
}