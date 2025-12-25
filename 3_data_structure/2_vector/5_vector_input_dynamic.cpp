#include <bits/stdc++.h>

using namespace std;
int main()
{
    vector<int> v; // default size 0
    int temp;
    while (cin >> temp) // 1 2 3 4 5 6 7
    {
        v.push_back(temp); //
    }
    cout << "Total size " << v.size() << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}