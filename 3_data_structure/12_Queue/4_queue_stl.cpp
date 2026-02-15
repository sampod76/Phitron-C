#include <bits/stdc++.h>

using namespace std;
int main()
{
    queue<int> q;
    q.push(50);
    q.push(90);

    if (!q.empty())
    {
        q.pop();
    }

    int n;
    cin >> n;

    while (n--)
    {
        int val;
        cin >> val;
        q.push(val);
    }
    cout << "Size: " << q.size() << endl;
    q.pop();

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}