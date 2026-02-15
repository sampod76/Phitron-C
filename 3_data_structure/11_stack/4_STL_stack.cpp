#include <bits/stdc++.h>

using namespace std;
int main()
{
    stack<int> st;
    // st.push(80);
    // st.push(55);
    // cout << st.top();
    int n;
    cin >> n;
    int value;
    while (n--)
    {
        cin >> value;
        st.push(value);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}