
/*
✅ Factorial (ফ্যাক্টোরিয়াল) কী?
কোনো সংখ্যা n এর ফ্যাক্টোরিয়াল মানে হলো:
উদাহরণ:

5! = 5 × 4 × 3 × 2 × 1 = 120
4! = 4 × 3 × 2 × 1 = 24
 */
#include <stdio.h>
long long fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    long long mul = fact(n - 1);
    return n * mul;
}
int main()
{

    int n; // example:  5
    scanf("%d", &n);
    long long totalMul = fact(n);
    printf("%lld", totalMul);
    return 0;
}