#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n; // 100
    cin >> n;
    int sum = 0;
    // basic
    for (int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    cout << sum << endl;

    // useing formula
    int fsum = (n * (n + 1)) / 2;
    cout << fsum << endl; // 5050

    return 0;
}