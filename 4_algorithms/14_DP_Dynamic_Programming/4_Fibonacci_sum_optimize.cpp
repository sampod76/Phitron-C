
// https://prnt.sc/m6pu6WHNDIPj

// https://phitron.io/ph068/video/ph068-14_7-fibonacci-with-dp
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

// dp array → আগের calculated Fibonacci store করবে
ll fibonacciCache[1005];

// Function: Fibonacci calculate করা
int calculateFibonacci(int n)
{
    // Base case: n যদি 0 বা 1 হয়
    if (n < 2)
        return fibonacciCache[n];

    // যদি আগে থেকেই calculate করা থাকে
    if (fibonacciCache[n] != -1)
    {
        return fibonacciCache[n];
    }

    // Recursive call
    ll previousOne = calculateFibonacci(n - 1); //
    ll previousTwo = calculateFibonacci(n - 2);

    // Result cache এ store করা
    fibonacciCache[n] = previousOne + previousTwo;

    return fibonacciCache[n];
}

int main()
{
    int inputNumber;

    // User input নেওয়া
    cin >> inputNumber;
    memset(fibonacciCache, -1, sizeof(fibonacciCache));
    fibonacciCache[0] = 0;
    fibonacciCache[1] = 1;

    // Result print
    cout << "Fibonacci of " << inputNumber
         << " = " << calculateFibonacci(inputNumber) << endl;

    return 0;
}
/*
==========================================================
                Fibonacci (Memoization / DP)
==========================================================

📘 Fibonacci কী?

Fibonacci হলো একটি সংখ্যা সিরিজ যেখানে:
👉 প্রতিটি সংখ্যা = আগের দুইটি সংখ্যার যোগফল

উদাহরণ:
0, 1,
1 (0+1)
2 (1+1)
3 (1+2)
5 (2+3)
8 (3+5)
13 (5+8)

----------------------------------------------------------

📌 Formula:
F(n) = F(n-1) + F(n-2)

Base Case:
F(0) = 0
F(1) = 1

----------------------------------------------------------

⚡ Optimization (Memoization):
আমরা আগের calculated result store করি
যাতে একই calculation বারবার না করতে হয়

Time Complexity:
O(n)  ✅ (fast)

Space Complexity:
O(n)

==========================================================
*/