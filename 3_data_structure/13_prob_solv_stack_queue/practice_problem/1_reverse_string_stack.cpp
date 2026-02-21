#include <bits/stdc++.h>
using namespace std;

string reverseString(string s)
{
    stack<char> st;

    // Step 1: Push all characters into stack
    for (char c : s)
    {
        st.push(c);
    }

    // Step 2: Pop from stack and build reversed string
    string reversed = "";

    while (!st.empty())
    {
        reversed += st.top();
        st.pop();
    }

    return reversed;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        cout << reverseString(s) << endl;
    }

    return 0;
}
