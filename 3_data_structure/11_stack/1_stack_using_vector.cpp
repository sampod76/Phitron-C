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
int main()
{
    myStack st;
    st.push(90);
    st.push(20);
    st.push(80);
    if (!st.empty()) // or st.empty() ==false
    {

        st.pop();
    }
    if (!st.empty())
    {

        cout << "top/last " << st.top() << " total size " << st.size() << endl;
    }

    //? Real time use
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}