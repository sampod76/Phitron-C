#include <bits/stdc++.h>
using namespace std;
//? https://phitron.io/ph048/video/ph048-2_3-vector-modifiers-i
int main()
{
    // একটি vector তৈরি করা এবং initial value দেওয়া
    vector<int> v = {1, 2, 3, 4, 5};

    // খালি vector
    vector<int> v2;

    // v এর সব element v2 তে কপি করা (সবচেয়ে সহজ ও safe)
    v2 = v;
    // alternative:
    // v2.assign(v.begin(), v.end()); // iterator দিয়ে কপি
    // v.assign(3, 9); // v = {9,9,9}

    // v2 এর element প্রিন্ট
    for (int element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    // শেষ element মুছে ফেলা
    v2.pop_back();

    // শেষে নতুন element যোগ করা
    v2.push_back(99);

    // নির্দিষ্ট index এ element insert করা
    v2.insert(v2.begin() + 2, 55); // index 2 এ 55

    // শেষ থেকে ২ নম্বর পজিশনে insert
    v2.insert(v2.end() - 2, 66);

    // নতুন vector
    vector<int> inV = {100, 200, 300};

    // inV এর সব element v2 এর মাঝখানে insert
    v2.insert(v2.begin() + 2, inV.begin(), inV.end());

    // আপডেটেড v2 প্রিন্ট
    for (int element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    // নির্দিষ্ট index এর একটি element remove
    v2.erase(v2.begin() + 2);

    // index 1 থেকে index 4 পর্যন্ত (1 inclusive, 5 exclusive) remove
    v2.erase(v2.begin() + 1, v2.begin() + 5);

    // ফাইনাল v2 প্রিন্ট
    for (int element : v2)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}
