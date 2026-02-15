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

void insert_into_tail(Node *&head, Node *&tail, int value)
{
    Node *newNode = new Node(value);

    // যদি লিস্ট ফাঁকা হয়
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

bool checkPalindrome(Node *head, Node *tail)
{
    bool isPalindrome = true;
    Node *tempHead = head;
    Node *tempTail = tail;

    while (tempHead != tail && tempHead->prev != tempTail)
    {
        if (tempHead->value != tempTail->value)
        {
            isPalindrome = false;
            break;
        }
        tempHead = tempHead->next;
        tempTail = tempTail->prev;
    }
    return isPalindrome;
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

    // insert_into_tail(head, tail, 99);
    // print_forward(head);
    bool palindrome = checkPalindrome(head, tail);
    if (palindrome)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}