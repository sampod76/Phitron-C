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
int main()
{
    Node *head = new Node(10);
    Node *a = new Node(20);
    Node *b = new Node(30);

    head->next = a; // not &a --> a is also pointer/address
    a->next = b;
    cout << head->value << endl;
    cout << a->value << endl;
    cout << b->value << endl;

    return 0;
}