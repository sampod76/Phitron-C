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
    Node a(10), b(20), c(20);
    // a.value = 10;
    // b.value = 20;
    // c.value = 30;
    a.next = &b;
    b.next = &c;
    c.next = NULL;
    cout << a.value << b.value << c.value << endl;
    cout << (*a.next).value << endl;
    // or
    cout << a.next->value << endl;
    //
    cout << a.next->next->value << endl;
    return 0;
}