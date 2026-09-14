#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int number;
    cin >> number;

    // 📦 DP array declare (size = number + 1)
    // এখানে প্রতিটি index এ Fibonacci value store হবে
    ll fibonacciCache[number + 1];

    // 🧱 Base cases:
    fibonacciCache[0] = 0; // Base cases: Fibonacci(0) = 0
    fibonacciCache[1] = 1; // Fibonacci(1) = 1

    // 🔁 Iterative calculation (Bottom-Up DP)
    // প্রতিটি সংখ্যা = আগের দুইটি সংখ্যার যোগফল
    for (int i = 2; i <= number; i++)
    {
        fibonacciCache[i] =
            fibonacciCache[i - 1] + fibonacciCache[i - 2];
    }

    cout << fibonacciCache[number];

    return 0;
}