#include <bits/stdc++.h>

using namespace std;

int main()
{
    list<int> l;
    int value;
    while (true)
    {
        cin >> value;
        if (value == -1)
        {
            break;
        }
        l.push_back(value);
    }
    l.reverse();

    for (int value : l)
    {
        cout << value << " ";
    }

    return 0;
}