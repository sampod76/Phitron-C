#include <bits/stdc++.h>

using namespace std;
//! https://leetcode.com/problems/valid-parentheses/
/**
 * @brief Checks if a string of parentheses is valid.
 * @param s A string of parentheses.
 * @return true if the string is valid, false otherwise.
 * @details A string of parentheses is valid if every opening parenthesis has a corresponding closing parenthesis of the same type.
 * @example isValid("()") returns true.
 * @example isValid("()[]{}") returns true.
 * @example isValid("(]") returns false.
 * @example isValid("([)]") returns true.
 * @example isValid("([)]") returns true.
 */
bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            else
            {

                if (c == ')' && st.top() == '(')
                { // valid and remove
                    st.pop();
                }
                else if (c == '}' && st.top() == '{')
                {
                    st.pop();
                }
                else if (c == ']' && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }
    }
    // return st.empty();
    if (st.empty())
        return true;
    else
        return false;
}
int main()
{
    string s;
    cin >> s;
    // cout << s << endl;
    bool valid = isValid(s);
    if (valid)
    {
        cout << "Valid";
    }
    else
    {
        cout << "Not valid";
    }
    return 0;
}