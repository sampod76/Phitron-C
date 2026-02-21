
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int totalDivided2 = 0;
    int totalDivided3 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0 && a[i] % 3 == 0)
        {
            totalDivided2++;
        }
        else if (a[i] % 2 == 0)
        {
            totalDivided2++;
        }
        else if (a[i] % 3 == 0)
        {
            totalDivided3++;
        }
    }
    printf("%d %d", totalDivided2, totalDivided3);

    return 0;
}