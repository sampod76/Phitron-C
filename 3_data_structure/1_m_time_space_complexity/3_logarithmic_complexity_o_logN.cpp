#include <bits/stdc++.h>

using namespace std;
/*
যদি i মান গুণ(*) করে বারে , অথবা ভাগ(/) করে কমে | সেক্ষেত্রে এটাকে আমরা logarithmic_complexity বলব
*/
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i = i * 2)
    {
        cout << i << " ";
    }
    // output: 1 2 4 8 16 32 = 6 number of loop
    for (int i = n; i >= n; i = i / 2)
    {
        cout << i << " ";
    }
    // output: 1 2 4 8 16 32 36  = 7 number of loop
    return 0;
}