#include <bits/stdc++.h>

using namespace std;
int val[1005], weight[1005];
int dp[1005][1005]; // row = i / col = mx_weight = (2,8) => 2 index , 8 max
int knapsack(int i, int mx_weight)
{
    if (i < 0 || mx_weight <= 0)
    {
        return 0;
    }
    if (dp[i][mx_weight] != -1)
    {
        return dp[i][mx_weight];
    }

    if (weight[i] <= mx_weight)
    {
        // 1) bag a rakhbo
        int op1 = knapsack(i - 1, mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i - 1, mx_weight);
        return max(op1, op2);
    }
    else
    {
        // 2
        // bag a raktha parbo na
        return knapsack(i - 1, mx_weight);
    }
};
int main()
{
    int n, mx_weight;
    cin >> n;

    // input values
    for (int i = 0; i < n; i++)
        cin >> val[i];

    // input weights
    for (int i = 0; i < n; i++)
        cin >> weight[i];

    cin >> mx_weight;
    // memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= mx_weight; j++)
        {
            dp[i][j] = -1;
        }
    }

    int result = knapsack(n - 1, mx_weight);

    cout << result << endl;

    return 0;
}

/*
input:

4
10 4 7 5
4 3 2 5
8

output: 17
*/