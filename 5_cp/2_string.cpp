#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        if (mp.find(c) != mp.end())
        {
            // fount
            mp[c]++;
        }
        else
        {
            mp[c] = 1;
        }
    }
    map<char, int> mpOdd;
    // string oddS;
    map<char, int> mpEven;
    // string evenS;

    for (auto val : mp)
    {
        if (val.second % 2 == 0)
        {
            // cout << val.first << " " << val.second << endl;
            mpEven[val.first] = val.second;
        }
        else
        {
            // cout << val.first << " " << val.second << endl;
            mpOdd[val.first] = val.second;
        }
    }
    vector<char> odda[100005];
    vector<char> evenb[100005];

    for (auto val : mpOdd)
    {
        cout << val.first << " " << val.second << " ";
        odda[val.second].push_back(val.first);
    }
    for (auto val : mpEven)
    {
        cout << val.first << " " << val.second << " ";
        evenb[val.second].push_back(val.first);
    }

    for (int i = 0; i < 100005; i++)
    {
        if (odda[i].size() > 0)
        {
        }
    }

    return 0;
}