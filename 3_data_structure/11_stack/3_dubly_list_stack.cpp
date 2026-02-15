#include <bits/stdc++.h>

using namespace std;
class myStack
{
private:
    list<int> l;

public:
    void push(int value)
    {
        l.push_back(value);
    }
    void pop()
    {
        l.pop_back();
    }
    int top()
    { // access last element
        return l.back();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
        return l.empty();
    }
};
/* input
5
1 2 3 4 5
*/
// https://phitron.io/ph048/video/ph048-13_7-stack-implementation-using-list
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