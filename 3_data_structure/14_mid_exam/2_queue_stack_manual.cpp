#include <bits/stdc++.h>

using namespace std;
class MyQueue
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
        if (!l.empty())
        {
            l.pop_front();
        }
    }
    int front()
    {
        return l.empty() ? -1 : l.front();
    }
    int back()
    {
        return l.empty() ? -1 : l.back();
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
class MyStack
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
        if (!l.empty())
        {

            l.pop_back();
        }
    }
    int top()
    {
        return l.empty() ? -1 : l.back();
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
int main()
{
    int n, m;
    cin >> n >> m;
    if (n != m)
    {
        cout << "NO";
        return 0;
    }
    MyStack s;
    MyQueue q;
    for (int i = 1; i <= n; i++)
    {
        int value;
        cin >> value;
        s.push(value);
    }

    for (int i = 1; i <= m; i++)
    {
        int value;
        cin >> value;
        q.push(value);
    }
    bool isValid = true;
    for (int i = 1; i <= m; i++)
    {
        int sTop = s.top();
        int qFront = q.front();
        if (sTop != qFront)
        {
            isValid = false;
            break;
        }
        s.pop();
        q.pop();
    }
    if (isValid)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}