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
    Node *head = NULL; // front
    Node *tail = NULL; // rear

public:
    // Constructor
    MyQueue()
    {
        head = NULL;
        tail = NULL;
    }

    // isEmpty()
    bool isEmpty()
    {
        return head == NULL;
    }

    // enqueue()
    // 10<-20<-50<-36  | tail<-head
    void enqueue(int val) // push
    {
        Node *newnode = new Node(val);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            return;
        }

        tail->next = newnode;
        tail = newnode;
    }

    // dequeue()
    int dequeue() // pop
    {
        if (head == NULL)
        {
            return -1;
        }

        Node *deletenode = head;
        int returnValue = deletenode->value;

        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }

        delete deletenode;
        return returnValue;
    }

    // front()
    int front()
    {
        if (head == NULL)
        {
            return -1;
        }

        return head->value;
    }
};

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int q;
        cin >> q;

        MyQueue queue;

        while (q--)
        {
            int type;
            cin >> type;

            if (type == 1)
            {
                int data;
                cin >> data;
                queue.enqueue(data);
            }
            else if (type == 2)
            {
                cout << queue.dequeue() << endl;
            }
            else if (type == 3)
            {
                cout << queue.front() << endl;
            }
            else if (type == 4)
            {
                cout << (queue.isEmpty() ? "true" : "false") << endl;
            }
        }
    }

    return 0;
}