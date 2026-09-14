
// https://prnt.sc/Zh2SDN8DCz4O

#include <bits/stdc++.h>
using namespace std;

//! Do not use => this is unoptimized => complexity => O(2^N)
//  Function name should be descriptive (verb/action based)
int calculateFibonacci(int n) // example : 7
{
    // Base case
    if (n < 2)
        return n;

    // Use meaningful variable names
    int previousNoOne = calculateFibonacci(n - 1); // 6
    int previousNoTwo = calculateFibonacci(n - 2); // 5

    return previousNoOne + previousNoTwo;
}

int main()
{
    int inputNumber = 7;

    cout << "Fibonacci of " << inputNumber
         << " = " << calculateFibonacci(inputNumber) << endl;

    return 0;
}
/*
📘 Fibonacci কী? (সহজ ভাষায়)

Fibonacci হলো একটা সিরিজ যেখানে:

👉 প্রতিটা সংখ্যা = আগের ২টা সংখ্যার যোগফল

0, 1,
1 (0+1) = 2 no
2 (1+1) = 3 no
3 (1+2) = 4 no
5 (2+3) = 5 no
8 (3+5) = 6 no
13 (8+5) = 7 no
==========================================================
                Fibonacci Function (Recursive)
==========================================================

Definition:
Fibonacci series is a sequence where:
F(n) = F(n-1) + F(n-2)

Base Cases:
F(0) = 0
F(1) = 1

Example:
0, 1, 1, 2, 3, 5, 8, 13...

Time Complexity:
O(2^n)  --> খুব স্লো (exponential)

Space Complexity:
O(n) --> recursion stack

==========================================================
*/