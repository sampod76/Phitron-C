#include <bits/stdc++.h>

using namespace std;
class Node
{
public:
    Node *prev;
    string value;
    Node *next;
    Node(string val)
    {
        this->prev = NULL;
        this->value = val;
        this->next = NULL;
    }
};
void print_forward(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
};

void insert_into_tail(Node *&head, Node *&tail, string value)
{
    Node *newNode = new Node(value);

    if (tail == NULL || head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    string temp;
    while (true)
    {
        cin >> temp;
        if (temp == "end")
        {
            break;
        }
        insert_into_tail(head, tail, temp);
    }
    int q;
    cin >> q;
    Node *tracker = NULL;
    while (q--)
    {
        string commend;
        cin >> commend;
        if (commend == "visit")
        {
            string value;
            cin >> value;
            Node *traversalNode = head;
            string findvalue = "";
            while (traversalNode != NULL)
            {
                if (traversalNode->value == value)
                {
                    findvalue = traversalNode->value;
                    tracker = traversalNode;
                    break;
                }
                traversalNode = traversalNode->next;
            }
            if (findvalue != "")
            {
                cout << findvalue << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (commend == "prev")
        {
            if (tracker != NULL && tracker->prev != NULL)
            {
                cout << tracker->prev->value << endl;
                tracker = tracker->prev;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (commend == "next")
        {
            if (tracker != NULL && tracker->next != NULL)
            {
                cout << tracker->next->value << endl;
                tracker = tracker->next;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}