#include <bits/stdc++.h>

using namespace std;
int main()
{
    // pair<string, int> p;
    // // p=make_pair("sampod",500);
    // // or
    // p = {"sampod", 500};
    // cout << p.first << " " << p.second << endl;

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second;
    }
    return 0;
}