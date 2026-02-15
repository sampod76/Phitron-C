
#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    // small to big
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
    // big to small
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
// output
/*
 *
 **
 ***
 ****
 *****
 */