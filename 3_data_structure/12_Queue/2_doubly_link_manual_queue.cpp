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
        prev = NULL;
        value = val;
        next = NULL;
    }
};

class myQueue
{
private:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

public:
    void push(int value)
    {
        Node *newNode = new Node(value);
        sz++;

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void pop()
    {
        if (head == NULL)
            return;

        Node *deletedNode = head;
        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }
        else
        {
            head->prev = NULL;
        }

        delete deletedNode;
        sz--;
    }

    int front()
    {
        if (empty())
            return -1;
        return head->value;
    }

    int back()
    {
        if (empty())
            return -1;
        return tail->value;
    }

    bool empty()
    {
        return head == NULL;
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    myQueue dq;

    int n;
    cin >> n;

    while (n--)
    {
        int val;
        cin >> val;
        dq.push(val);
    }
    cout << "Size: " << dq.size() << endl;
    dq.pop();

    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop();
    }

    cout << endl;
}
