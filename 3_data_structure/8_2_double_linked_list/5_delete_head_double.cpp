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
// https://phitron.io/ph048/video/ph048-9_11-delete-at-head
void delete_head(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    Node *deleteNode = head;

    head = head->next;
    delete deleteNode;
    if (head == NULL)
    {
        tail = NULL;
        return;
    }
    head->prev = NULL;
}
void delete_tail(Node *&head, Node *tail)
{
    Node *deleteNode = tail;
    tail = tail->prev;
    delete deleteNode;
    if (tail == NULL)
    {
        head = NULL;
        return;
    }

    tail->next = NULL;
};
void delete_any_position(Node *&head, int idx)
{
    Node *temp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = deleteNode->next;

    if (deleteNode->next != NULL)
    {

        deleteNode->next->prev = temp;
    }

    delete deleteNode;
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
    delete_head(head, tail);
    print_forward(head);
    //
    delete_head(head, tail);
    print_forward(head);
    //
    delete_head(head, tail);
    print_forward(head);

    return 0;
}