#include <bits/stdc++.h>

using namespace std;
int dp[31];
int fib(int n)
{
    // cout << n << " ";
    if (n < 4)
    {
        return dp[n];
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1) + fib(n - 2) + fib(n - 3) + fib(n - 4);
    return dp[n];
}
int main()
{
    int number;
    cin >> number;
    // memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 31; i++)
    {
        dp[i] = -1;
    }
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;

    cout << fib(number);
    // fib(5);
    return 0;
}