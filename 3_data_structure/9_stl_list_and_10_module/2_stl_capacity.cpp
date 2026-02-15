#include <bits/stdc++.h>

using namespace std;
int main()
{
    list<int> a = {1, 2, 3, 6, 5};
    list<int> a2copy(a);
    // a2copy.clear();        // full clean value;
    cout << a2copy.size() << " size" << endl; // ans: 0
    if (a.empty())
    {
        cout << "Empty";
    }
    a2copy.resize(2); // remove another
    for (int value : a2copy)
    {
        cout << value << " ";
    }
    cout << endl;
    a2copy.resize(9); // 1 2 0 0 0 0 0 0 0
    for (int value : a2copy)
    {
        cout << value << " ";
    }
    cout << endl;
    a2copy.resize(15, 50); // 1 2 0 0 0 0 0 0 0 50 50 50 50 50 50
    for (int value : a2copy)
    {
        cout << value << " ";
    }
    cout << endl;

    // for (int value : a2copy)
    // {
    //     cout << value << " ";
    // }
    return 0;
}