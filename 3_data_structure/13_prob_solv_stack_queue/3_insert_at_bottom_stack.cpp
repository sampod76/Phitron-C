#include <bits/stdc++.h>
using namespace std;

stack<int> pushAtBottom(stack<int> st, int x)
{
    stack<int> new_st;

    while (!st.empty())
    {
        new_st.push(st.top());
        st.pop();
    }

    st.push(x);

    while (!new_st.empty())
    {
        st.push(new_st.top());
        new_st.pop();
    }

    return st;
}

int main()
{
    stack<int> s;
    s.push(9);
    s.push(5);
    s.push(4);

    s = pushAtBottom(s, 88);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
