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
        cout << temp->value << " ";
        temp = temp->next;
    }
}

void remove_duplicate(Node *&head, Node *&tail)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *temp2 = temp->next;

        while (temp2 != NULL)
        {

            if (temp->value == temp2->value)
            {
                        }
            else
            {

                temp2 = temp2->next;
            }
        }

        temp = temp2;
    }
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
    remove_duplicate(head, tail);
    print_linked_list(head);

    return 0;
}