#include <bits/stdc++.h>

using namespace std;
bool backspaceCompare(string s, string t)
{
    stack<char> st1;
    for (char c : s)
    {
        if (c == '#')
        {
            if (!st1.empty())
            {
                st1.pop();
            }
        }
        else
        {
            st1.push(c);
        }
    }
    stack<char> st2;

    for (char c : t)
    {
        if (c == '#')
        {
            if (!st2.empty())
            {
                st2.pop();
            }
        }
        else
        {
            st2.push(c);
        }
    }
    /*
      if (st1 == st2)
     {
         return true;
     }
     else
     {
         return false;
     }
     */
    return st1 == st2;
};
int main()
{
    string s, t;
    cin >> s >> t;
    cout << s << " " << t;
    bool isEqual = backspaceCompare(s, t);

    return 0;
}