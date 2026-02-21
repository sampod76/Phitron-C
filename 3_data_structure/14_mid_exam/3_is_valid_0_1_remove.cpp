#include <bits/stdc++.h>

using namespace std;
int main()
{
    int t;
    cin >> t;
    // cout << t;
    while (t--)
    {
        string s;
        cin >> s;
        // cout << s << " ";
        stack<char> stk;
        for (char c : s)
        {
            // cout << c << " ";
            if (stk.empty())
            {
                stk.push(c);
            }
            else
            {

                int sTop = stk.top();
                if (c == '0' && sTop == '1')
                {
                    stk.pop();
                }
                else if (c == '1' && sTop == '0')
                {
                    stk.pop();
                }
                else
                {
                    stk.push(c);
                }
            }
        }
        if (stk.empty())
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}