#include <bits/stdc++.h>
// https://codeforces.com/group/MWSDmqGsZm/contest/219856/problem/J
using namespace std;
int main()
{
    vector<int> v(26);
    char temp;
    while (cin >> temp)
    {
        int index = temp - 'a';
        v[index]++;
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {

            char alp = i + 'a';
            cout << alp << " : " << v[i] << endl;
        }
    }

    return 0;
}