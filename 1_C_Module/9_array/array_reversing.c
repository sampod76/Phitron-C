
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", a[i]);
    }
    int i = 0;              // first index
    int j = n - 1;          // last index
    while (i != j && i < j) // or only i < j ok | because when i ==j then brack i < j because i need to allwair small j
    {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        // or ->

        i++;
        j++;
    }
    // reverse করা array প্রিন্ট
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}