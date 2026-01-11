#include <bits/stdc++.h>
// https://phitron.io/ph048/video/ph048-3_10-binary-search-implementation
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int matchValue;
    cin >> matchValue;
    bool isFind = false;
    int l = 0;     // left index
    int r = n - 1; // last/right index
    while (l <= r)
    {
        int midIndex = (l + r) / 2; // mid index
        if (a[midIndex] == matchValue)
        {
            isFind = true;
            break;
        }
        else if (a[midIndex] > matchValue)
        {
            r = midIndex - 1;
        }
        else
        {
            l = midIndex + 1;
        }
    }
    if (isFind)
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}