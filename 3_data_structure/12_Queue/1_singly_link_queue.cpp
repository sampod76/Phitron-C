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

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;
    void push(int value)
    {
        sz++;
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

        if (head == NULL)
            return;

        Node *tempNode = head;
        head = head->next;

        if (head == NULL)
        {
            tail == NULL;
        }
        delete tempNode;
        sz--;
    }
    int front()
    {
        return head->value;
    }
    int back()
    {
        return tail->value;
    }
    int size()
    {
        return sz;
    }
    bool empty()
    {
        // return head ==NULL ? true : false;
        return head == NULL;
    }
};
int main()
{
    myQueue sq;
    int n;
    cin >> n;
    int val;
    while (n--)
    {
        cin >> val;
        sq.push(val);
    }

    while (!sq.empty())
    {
        cout << sq.front() << " ";
        sq.pop();
    }

    return 0;
}