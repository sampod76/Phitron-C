#include <bits/stdc++.h>
// https://codeforces.com/group/MWSDmqGsZm/contest/329103/problem/D
// একটি integer array দেওয়া থাকে। কাজ হলো—অ্যারেতে থাকা কতগুলো element x এর জন্য একই array-তে x + 1 মানটি আছে তা গোনা। একই সংখ্যা একাধিকবার থাকলে প্রতিটিকে আলাদাভাবে গণনা করতে হবে।
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int>::iterator endIt = find(v.begin(), v.end(), v[i] + 1); // auto -> sortout
        // cout << *endIt;
        if (endIt != v.end())
        {
            count++;
        }
    }
    cout << count;

    return 0;
}