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

// Reference:
// https://phitron.io/ph048/video/ph048-9_13-detect-cycle-implementation

int main()
{
    Node *head = new Node(50);
    Node *a = new Node(30);
    Node *b = new Node(60);
    Node *c = new Node(55);
    Node *d = new Node(40);
    /*
    =========================
      Linked List তৈরি
    =========================
    50 -> 30 -> 60 -> 55 -> 40
                    ↑      |
                    |______|
    */
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    // 🔴 এখানে cycle তৈরি করা হয়েছে
    // d এর next আবার b কে point করছে
    d->next = b;
    bool isCycle = false;

    // slow pointer → এক ধাপ করে যাবে
    Node *slow = head;
    // fast pointer → দুই ধাপ করে যাবে
    Node *fast = head;

    /*
    while লুপ কেন এমন?
    -------------------
    fast != NULL
    fast->next != NULL

    ✔️ Odd length হলে:
       fast সরাসরি NULL হয়ে যেতে পারে

    ✔️ Even length হলে:
       fast->next->next NULL হতে পারে

    তাই দুইটাই চেক করা বাধ্যতামূলক
    */
    while (fast != NULL && fast->next != NULL)
    {
        // slow এক ধাপ এগোয় : যেমন: i = i + 1
        slow = slow->next;
        // fast দুই ধাপ এগোয় : যেমন: i = i + 2
        fast = fast->next->next;
        /*
        যদি slow আর fast একই নোডে আসে, তাহলে বুঝবো:
        👉 লিস্টে cycle আছে
        */
        if (slow == fast)
        {
            isCycle = true;
            break;
        }
    }

    /*
    =========================
      Result Print
    =========================
    */
    if (isCycle)
    {
        cout << "Cycle Detected";
    }
    else
    {
        cout << "No cycle";
    }

    return 0;
}
