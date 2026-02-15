#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    long long value;
    Node *next;
    Node(long long val)
    {
        this->value = val;
        this->next = NULL;
    }
};
void insert_into_tail(Node *&head, Node *&tail, long long value)
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
void insert_into_tail_max_min(Node *&head, Node *&tail, long long *&maxRef, long long *&minRef, long long value)
{
    Node *newNode = new Node(value);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        *maxRef = newNode->value;
        *minRef = newNode->value;
        return;
    }
    long long maxValue = *maxRef;
    long long minValue = *minRef;
    if (maxValue < newNode->value)
    {
        *maxRef = newNode->value;
    }
    if (minValue > newNode->value)
    {
        *minRef = newNode->value;
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
int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    long long max = 0;
    long long min = 0;

    long long *maxRef = &max;
    long long *minRef = &min;

    long long tempValue;
    while (true)
    {
        cin >> tempValue;
        if (tempValue == -1)
        {
            break;
        }
        insert_into_tail_max_min(head, tail, maxRef, minRef, tempValue);
    }
    // print_linked_list(head);
    cout << max - min;

    return 0;
}