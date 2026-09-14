#include <bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<ll, ll> mp;
    for (int i = 1; i <= n; i++)
    {
        ll val;
        cin >> val;
        if (mp.find(val) != mp.end())
        {
            // fount
            mp[val] += i;
        }
        else
        {
            mp[val] = i;
        }
    }
    for (auto val : mp)
    {
        cout << val.first << " " << val.second << endl;
    }

    return 0;
}