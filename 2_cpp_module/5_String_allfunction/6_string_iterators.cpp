#include <bits/stdc++.h>
using namespace std;

int main()
{
    // একটি সাধারণ স্ট্রিং
    string s = "Hello world";

    // ------------------------------------------------------
    // 1. সাধারণ for loop → index ব্যবহার করে access করা
    // ------------------------------------------------------
    // এখানে আমরা s[i] দিয়ে অক্ষর বের করছি।
    // s.size() = স্ট্রিং-এর দৈর্ঘ্য.
    cout << "Index ব্যবহার করে loop:" << endl;
    for (int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " ";
    }
    cout << endl;

    // ------------------------------------------------------
    // 2. Iterator ব্যবহার করে loop চালানো
    // ------------------------------------------------------
    // Iterator হলো pointer-এর মতো — স্ট্রিং-এর ভিতর চলাচল করে।
    // s.begin() = প্রথম অক্ষর
    // s.end()   = শেষের পরের অবস্থান
    cout << "Iterator ব্যবহার করে loop:" << endl;
    for (string::iterator it = s.begin(); it < s.end(); it++)
    {
        cout << *it << " "; // iterator dereference করে ভ্যালু পাওয়া যায়
    }
    cout << endl;

    // ------------------------------------------------------
    // 3. Modern C++ (C++11) → auto দিয়ে iterator
    // ------------------------------------------------------
    // auto → নিজে থেকেই টাইপ বুঝে নেয়।
    // মানে iterator-এর টাইপ বড় লিখতে হয় না।
    cout << "auto iterator ব্যবহার করে loop:" << endl;
    for (auto it = s.begin(); it < s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}
