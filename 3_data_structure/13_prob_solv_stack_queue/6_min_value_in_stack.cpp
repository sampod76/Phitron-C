#include <bits/stdc++.h>

// LeetCode Problem: Min Stack
// https://leetcode.com/problems/min-stack/description/
// https://phitron.io/ph048/video/ph048-13_6-min-stack

using namespace std;

// এই ক্লাসটি একটি Min Stack ইমপ্লিমেন্ট করে
// যেখানে push, pop, top এবং getMin সবগুলো O(1) টাইমে কাজ করে
class MyStack
{
private:
    stack<int> stk;            // মূল স্ট্যাক (ডেটা রাখার জন্য)
    stack<int> min_values_stk; // বর্তমান পর্যন্ত মিনিমাম ভ্যালুগুলো ট্র্যাক করার জন্য আলাদা স্ট্যাক

public:
    void push(int value)
    {
        stk.push(value);

        // যদি min স্ট্যাক খালি হয়, তাহলে এই মানই প্রথম মিনিমাম
        if (min_values_stk.empty())
        {
            min_values_stk.push(value);
        }
        // যদি নতুন মান বর্তমান মিনিমামের সমান বা ছোট হয়
        // তাহলে এটাকে min স্ট্যাকেও রাখবো
        else if (value <= min_values_stk.top())
        {
            min_values_stk.push(value);
        }
    }

    void pop()
    {

        if (stk.empty())
            return;

        int topMinValue = min_values_stk.top(); // বর্তমান মিনিমাম মান
        int stkRemovableValue = stk.top();      // যে মানটি রিমুভ হবে

        // যদি রিমুভ হওয়া মান বর্তমান মিনিমাম হয়
        // তাহলে min স্ট্যাক থেকেও সেটাকে রিমুভ করতে হবে
        if (topMinValue == stkRemovableValue)
        {
            min_values_stk.pop();
        }

        stk.pop();
    }

    int top()
    {

        return stk.empty() ? -1 : stk.top();
    }

    int getMin()
    {
        // যদি min স্ট্যাক খালি হয় তাহলে -1 রিটার্ন করবে
        return min_values_stk.empty() ? -1 : min_values_stk.top();
    }
};

int main()
{
    MyStack stk;

    int temp;

    // ইনপুট নেওয়া (EOF পর্যন্ত)
    while (cin >> temp)
    {
        stk.push(temp); // প্রতিটি মান স্ট্যাকে যোগ করা
    }

    // স্ট্যাকের সর্বনিম্ন মান প্রিন্ট করা
    cout << stk.getMin();

    return 0;
}
