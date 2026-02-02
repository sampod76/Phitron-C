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
    cout << endl;
}

void remove_duplicate(Node *head, Node *&tail)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *runner = current;
        while (runner->next != NULL)
        {
            if (runner->next->value == current->value)
            {
                Node *deleteNode = runner->next;
                runner->next = runner->next->next;
                if (deleteNode == tail) 
                {
                    tail = runner;
                }
                delete deleteNode;
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
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
        if (value == -1)
        {
            break;
        }
        insert_into_tail(head, tail, value);
    }
    remove_duplicate(head, tail);
    print_linked_list(head);

    return 0;
}