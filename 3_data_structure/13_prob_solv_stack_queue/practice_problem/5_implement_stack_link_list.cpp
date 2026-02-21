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
class MyStack
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

public:
    void push(int value)
    {
        size++;
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
    void pop()
    {
    }
};
int main()
{
    int a, b;

    cout << " " << endl;
    return 0;
}