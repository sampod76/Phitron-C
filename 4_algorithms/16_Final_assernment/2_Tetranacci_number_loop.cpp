#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{

    int number;
    cin >> number;

    ll dp[number + 1];
    for (int i = 0; i <= number; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    for (int i = 4; i <= number; i++)
    {
        dp[i] =
            dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
    }

    cout << dp[number];

    return 0;
}