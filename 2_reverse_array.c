
#include <stdio.h>

int main()
{

    int n; // 5
    scanf("%d", &n);

    int a[n]; // 1 2 3 4 5
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        // printf("%d ", a[i]);
    }
    printf("\n");

    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", a[i]); // 5 4 3 2 1
    }

    return 0;
}