#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n); // 0 index to sort last meain last ar por mani 5 index
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    sort(a, a + n, greater<int>());
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}