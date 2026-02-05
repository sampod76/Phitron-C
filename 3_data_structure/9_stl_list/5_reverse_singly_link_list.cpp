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
    tail->next = newNode;
    tail = newNode;
}
void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
}
// https://phitron.io/ph048/video/ph048-9_8-reverse-singly-linked-list-implementation
// batter-understand:  https://www.notion.so/sampod/reverse-link-list-2fd7a1bce8f580fd8f73f9a381104818?source=copy_link
void reverse_link_list(Node *&head, Node *&tail, Node *currentNode)
{
    if (currentNode->next == NULL)
    {
        head = currentNode;
        return;
    }
    reverse_link_list(head, tail, currentNode->next);
    currentNode->next->next = currentNode;
    currentNode->next = NULL;
    tail = currentNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        insert_into_tail(head, tail, value);
    }
    Node *currentNode = head;
    reverse_link_list(head, tail, currentNode);
    cout << head->value << endl;
    cout << tail->value << endl;

    return 0;
}