#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/implement-queue-using-stacks/

class MyQueue
{
private:
    stack<int> sta; // মূল stack যেখানে সব data থাকবে

public:
    // Queue এর push operation (FIFO এর enqueue)
    void push(int x)
    {
        // সরাসরি stack এ push করছি
        sta.push(x);
    }

    // Queue এর pop operation (FIFO অনুযায়ী প্রথম element remove করবে)
    int pop()
    {
        stack<int> sta2; // temporary stack order reverse করার জন্য

        // Step 1: সব element sta থেকে sta2 তে নেওয়া
        // এতে order reverse হবে
        while (!sta.empty())
        {
            int stackTopValue = sta.top(); // means -> stack last item
            sta2.push(stackTopValue);
            sta.pop();
        }

        // এখন sta2 এর top = queue এর front
        int frontValue = sta2.top(); // front value store
        sta2.pop();                  // front remove

        // Step 2: বাকি element আবার sta তে ফেরত দেওয়া
        while (!sta2.empty())
        {
            sta.push(sta2.top());
            sta2.pop();
        }

        // remove করা value return
        return frontValue;
    }

    // Queue এর front দেখার জন্য (remove করবে না)
    int peek()
    {
        stack<int> sta2;

        // সব element reverse করছি
        while (!sta.empty())
        {
            sta2.push(sta.top());
            sta.pop();
        }

        // এখন top হচ্ছে queue এর front
        int frontValue = sta2.top();

        // আবার আগের order এ ফিরিয়ে নিচ্ছি
        while (!sta2.empty())
        {
            sta.push(sta2.top());
            sta2.pop();
        }

        return frontValue;
    }

    // Queue খালি কিনা চেক
    bool empty()
    {
        return sta.empty();
    }
};

int main()
{
    MyQueue q;

    // Queue এ data যোগ করছি
    q.push(90);
    q.push(30);
    q.push(40);

    // প্রথম element remove হবে (90)
    cout << q.pop() << endl;

    // এখন front হবে 30 (remove হবে না)
    cout << q.peek() << endl;

    return 0;
}
