#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};
void insert_into_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode; // old tail in add next = newNode address
    tail = newNode;       // old tail to replace newNode
}
void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << endl;
        temp = temp->next;
    }
}
void delete_at_head(Node *&head)
{
    Node *deleteNode = head;
    head = head->next;
    delete deleteNode;
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1) // bec
        {
            break;
        }
        insert_into_tail(head, tail, value);
    }
    delete_at_head(head);
    delete_at_head(head);
    delete_at_head(head);
    print_linked_list(head);

    return 0;
}