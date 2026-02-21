#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    if (n != m)
    {
        cout << "NO";
        return 0;
    }
    stack<int> s;
    queue<int> q;
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