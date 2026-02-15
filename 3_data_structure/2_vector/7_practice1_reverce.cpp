#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> totalV;

    for (int i = 1; i <= n; i++)
    {
        vector<int> vA(n);
        for (int j = 0; j < n; j++)
        {
            cin >> vA[j];
        }

        totalV.insert(totalV.begin(), vA.begin(), vA.end());
    }
    sort(totalV.begin(), totalV.end());
    for (int i = 0; i < totalV.size(); i++)
    {
        cout << totalV[i];
    }

    return 0;
}