#include <bits/stdc++.h>

using namespace std;
int main()
{
    // 1
    // string s = "hello";
    // string s("Hello");
    // cout << s << endl;

    // string s("Hello World", 4);
    // cout << s << endl; // Hell --> only first to slice 4 char

    // string t = "Hello World";
    // string s(t, 4);
    // cout << s << endl; // But output: "o World"  --> only first to del 4 char then return

    string s(5, 'A');
    cout << s << endl; // Output AAAAA
    return 0;
}