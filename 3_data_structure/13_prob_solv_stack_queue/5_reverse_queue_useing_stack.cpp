/*
-----------------------------------------
    এই প্রোগ্রামটি একটি queue কে stack ব্যবহার করে reverse করে।

    মূল ধারণা:
    Queue → FIFO (First In First Out)
    Stack → LIFO (Last In First Out)

    যেহেতু stack উল্টোভাবে element বের করে,
    তাই queue → stack → queue করলে
    পুরো queue reverse হয়ে যায়।

    Time Complexity: O(n)
-----------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// একটি queue কে reverse করার ফাংশন
queue<int> reverseQueue(queue<int> q)
{
    stack<int> stk; // অস্থায়ী stack

    // queue এর সব element stack এ পাঠানো
    while (!q.empty())
    {
        stk.push(q.front());
        q.pop();
    }

    queue<int> rq; // নতুন reversed queue

    // stack থেকে আবার queue তে পাঠানো
    while (!stk.empty())
    {
        rq.push(stk.top());
        stk.pop();
    }

    return rq;
}

int main()
{
    queue<int> que;

    int temVal;

    // ইনপুট নেওয়া (EOF পর্যন্ত)
    while (cin >> temVal)
    {
        que.push(temVal);
    }

    queue<int> rq = reverseQueue(que);

    // reversed queue প্রিন্ট
    while (!rq.empty())
    {
        cout << rq.front() << " ";
        rq.pop();
    }

    return 0;
}
