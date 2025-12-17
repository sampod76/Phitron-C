#include <bits/stdc++.h>

using namespace std;
int main()
{
    string s = "Hello";
    for (char c : s)
    {
        cout << c << endl;
    }
    // or
    for (auto c : s)
    {
        cout << c << endl;
    }
    return 0;
}

/* output
H
e
l
l
o
*/