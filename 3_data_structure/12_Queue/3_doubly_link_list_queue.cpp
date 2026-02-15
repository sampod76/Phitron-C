#include <bits/stdc++.h>
using namespace std;

class myQueue
{
private:
    list<int> l;

public:
    void push(int val)
    {
        l.push_back(val);
    }

    void pop()
    {
        if (!l.empty())
            l.pop_front();
    }

    int front()
    {
        if (l.empty())
            return -1;
        return l.front();
    }

    int back()
    {
        if (l.empty())
            return -1;
        return l.back();
    }

    bool empty()
    {
        return l.empty();
    }

    int size()
    {
        return l.size();
    }
};

int main()
{
    myQueue dq;

    int n;
    cin >> n;

    while (n--)
    {
        int val;
        cin >> val;
        dq.push(val);
    }
    cout << "Size: " << dq.size() << endl;
    dq.pop();

    while (!dq.empty())
    {
        cout << dq.front() << " ";
        dq.pop();
    }

    cout << endl;
}
