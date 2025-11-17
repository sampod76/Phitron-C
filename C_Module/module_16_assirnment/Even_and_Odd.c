
#include <stdio.h>
void odd_even(int a[], int n)
{
    int totaleven = 0;
    int totalodd = 0;
    for (int i = 0; i < n; i++)
    {

        if (a[i] % 2 == 0)
        {
            totaleven++;
        }
        else
        {
            totalodd++;
        }
    }
    printf("%d %d", totaleven, totalodd);
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

    odd_even(a, n);

    return 0;
}