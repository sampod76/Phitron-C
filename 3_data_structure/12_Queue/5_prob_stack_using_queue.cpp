#include <bits/stdc++.h>

using namespace std;
// https://leetcode.com/problems/implement-queue-using-stacks/description/
class MyStack
{
private:
    queue<int> q;

public:
    void push(int value)
    {
        q.push(value);
    }
    int pop()
    {
        queue<int> q2;
        int tempValue;
        while (!q.empty())
        {
            tempValue = q.front();
            q.pop();
            if (q.empty())
            {
                break;
            }
            q2.push(tempValue);
        }
        // copy / replace main q use p2
        q = q2;
        return tempValue;
    }
    int top()
    {
        return q.back();
    }
    bool empty()
    {
        return q.empty();
    }
    int size()
    {
        return q.size();
    }
};
int main()
{
    MyStack s;
    int n;
    cin >> n;

    while (n--)
    {
        int val;
        cin >> val;
        s.push(val);
    }
    cout << "Size: " << s.size() << endl;
    s.pop();

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}