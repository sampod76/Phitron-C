#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    stack<int> s1, s2;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        s1.push(x);
    }

    // s1 → s2
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    // Print original order
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }

    return 0;
}
