// https://www.hackerrank.com/contests/final-exam-a-introduction-to-c-programming-a-batch-08/challenges/find-the-missing-number-11-3/problem
/*
4  -- test case
20 1 2 2
10 2 2 1
1 1 2 3
0 3 10 15

-- output --
5
-1
-1
0

*/
#include <stdio.h>

int main()
{

    int t; // testcase
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        // int mul;
        // scanf("%lld", &mul);
        // printf("%lld   - multpe \n", mul);
        long long a[4];
        for (int j = 0; j < 4; j++)
        {
            scanf("%lld", &a[j]);
        }
        long long mul = a[0];
        // printf("%lld", mul);
        long long remingTotal = 1;
        for (int j = 1; j < 4; j++)
        {
            remingTotal = remingTotal * a[j];
            // printf("%lld ", a[j]);
        }

        if (mul % remingTotal == 0)
        {
            long long ans = mul / remingTotal;
            printf("%lld\n", ans);
        }
        else
        {
            printf("%d\n", -1);
        }

        // printf("%lld ", remingTotal);
        // printf("\n------------\n");
    }

    return 0;
}
