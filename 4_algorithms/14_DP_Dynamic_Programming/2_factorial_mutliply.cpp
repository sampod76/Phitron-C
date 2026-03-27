#include <bits/stdc++.h>

using namespace std;
int fact(int number) // first time 5
{
    if (number == 1)
    {
        return 1;
    }
    int previousNumber = number - 1; // example : 5-1 = 4
    int mul = fact(previousNumber);
    return number * mul;
}
int main()
{

    cout << fact(5) << endl; // 120
    return 0;
}