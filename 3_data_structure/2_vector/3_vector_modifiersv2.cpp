#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 2, 5, 6, 2, 50, 2};
    // replace(start_iterator, end_iterator, old_value, new_value);
    replace(v.begin(), v.end(), 2, 99); // output : 1 99 3 99 5 6 99
    for (int item : v)
    {
        cout << item << " ";
    }
    cout << endl;

    // vector<int>::iterator it = find(v.begin(), v.end(), 50);
    // short
    auto it = find(v.begin(), v.end(), 3); // begin → (end-2) পর্যন্ত 3 খোঁজা
    // auto it = find(v.begin(), v.end() - 2, 3);
    if (it == v.end()) // v.end() - 2
    {
        cout << "Not Found";
    }
    else
    {
        cout << "Found " << *it;
    }

    return 0;
}