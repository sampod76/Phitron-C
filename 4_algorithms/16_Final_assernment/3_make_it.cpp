#include <bits/stdc++.h>
using namespace std;

bool rec(int n)
{

    if (n == 1)
        return true;

    if (n <= 0)
        return false;

    if (n % 2 == 0)
        return rec(n / 2);

    return rec(n - 3);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        if (rec(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}