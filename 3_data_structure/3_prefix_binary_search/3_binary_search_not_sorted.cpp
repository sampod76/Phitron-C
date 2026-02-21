#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < q; i++)
    {
        int findValue;
        cin >> findValue;
        bool isFind = false;
        int l = 0;
        int r = n - 1;
        while (l <= r)
        {
            int midIndex = (l + r) / 2;
            if (a[midIndex] == findValue)
            {
                isFind = true;
                break;
            }
            else if (a[midIndex] < findValue)
            {
                l = midIndex + 1;
            }
            else if (a[midIndex] > findValue)
            {
                r = midIndex - 1;
            }
            else
            { // sefty parpase
                break;
            }
        }
        if (isFind)
        {
            cout << "found" << endl;
        }
        else
        {
            cout << "not found" << endl;
        }
    }
    return 0;
}