/*
6
5 5 5 5 5 5

output : 30
*/
/* // solution number 1

#include <stdio.h>
int gTotal = 0;
void sum(int a[], int i)
{

    if (i == -1)
    {
        return;
    }
    gTotal += a[i];
    sum(a, i - 1);
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
    sum(a, n - 1);
    printf("%d", gTotal);
    return 0;
}
    */

#include <stdio.h>

void sum(int a[], int i, int *p)
{

    if (i == -1)
    {
        return;
    }
    int total = *p; // pointer value
    total += a[i];
    // printf("%d ", total);
    *p = total;
    sum(a, i - 1, p);
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
    int total = 0;
    // int *prt = &total; // store pointer address
    sum(a, n - 1, &total);
    printf("%d", total);
    return 0;
}