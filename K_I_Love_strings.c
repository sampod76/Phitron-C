
#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        char a[51];
        char b[51];
        scanf("%s %s", &a, &b);
        int aLen = strlen(a);
        int bLen = strlen(b);
        int mx;
        if (aLen > bLen)
            mx = aLen;
        else
            mx = bLen;

        // printf("%s %s", a, b);
        for (int i = 0; i < mx; i++)
        {
            if (i < aLen)
            {

                printf("%c", a[i]);
            }
            if (i < bLen)
            {

                printf("%c", b[i]);
            }
        }
        printf("\n");
    }
}