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
class MyQueue
{
private:
    Node *head = NULL;
    Node *tail = NULL;

public:
    void enqueue(int data)
    {
        Node *newnode = new Node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }
    void dequeue()
    {
    }
};
int main()
{

    return 0;
}