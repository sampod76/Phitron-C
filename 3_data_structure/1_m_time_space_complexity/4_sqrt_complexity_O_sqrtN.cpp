#include <bits/stdc++.h>

using namespace std;
/* question
কোন একটা সংখ্যার যতগুলো ভাজক/divisor  আছে সব বের করে
*/
int main()
{
    int n; // 100
    cin >> n;
    // normal use
    for (int i = 1; i <= n; i = i * 2)
    {
        if (n % i == 0)
        {
            // cout << i << " ";
        }
    }
    // cout << sqrt(n);
    // 100 = এর রুট / বর্গ = 10 | sqrt(100) =10 -> অর্থাৎ loop সর্বোচ্চ ১০ বার চলবে | তাহলে এক হাজার বার না চলে মাত্র দশ বার চলবে এতে করে আমাদের টাইম অনেক কমে যাবে
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " " << n / i << " ";
            // cout << i << " ";
        }
    }
    // output: 1 100 2 50 4 25 5 20 10 10
    return 0;
}