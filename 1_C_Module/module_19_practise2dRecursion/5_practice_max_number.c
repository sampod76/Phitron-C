
#include <stdio.h>
#include <limits.h>
int maxFun(int a[], int n, int max)
{
    // printf("%d ", a[n]);
    if (n == -1)
    {
        return 0;
    }
    int maxNumber = max;
    if (a[n] > maxNumber)
    {
        maxNumber = a[n];
    }
    printf("%d \n", maxNumber);
    maxFun(a, n - 1, maxNumber);
    return 0;
}
int main()
{

    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", a[i]);
    // }
    int maxNum = maxFun(a, n - 1, 0);
    printf("%d ", maxNum);
    return 0;
}