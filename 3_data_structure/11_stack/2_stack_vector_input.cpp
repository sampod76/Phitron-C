#include <bits/stdc++.h>

using namespace std;
class myStack
{
private:
    vector<int> v;

public:
    void push(int value)
    {
        v.push_back(value);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    { // access last element
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        return v.empty();
    }
};
/* input
5
1 2 3 4 5
*/
// https://phitron.io/ph048/video/ph048-11_6-stack-input-and-output
int main()
{
    myStack st;
    int n;
    cin >> n;
    int temValue;
    while (n--)
    { // int temValue;
        cin >> temValue;
        st.push(temValue);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    // output: 5 4 3 2 1

    return 0;
}