#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    long long int value;
    Node *next;
    Node(long long int val)
    {
        this->value = val;
        this->next = NULL;
    }
};
void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
void insert_into_head(Node *&head, Node *&tail, long long int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head; // new head in next address set old head
    head = newNode;       // replace old head to new head
}
void insert_into_tail(Node *&head, Node *&tail, long long int value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void insert_into_any_position(Node *&head, Node *&tail, int idx, long long int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    for (int i = 0; i < idx - 1; i++)
    {
        }
}
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    return 0;
}