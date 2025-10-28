
#include <stdio.h>

int main()
{

    // int fistarray[] = {14, 15, 18};
    // printf("%d", fistarray[0]);

    // whe not de
    int withGarray[5] = {};

    //
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        // printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}