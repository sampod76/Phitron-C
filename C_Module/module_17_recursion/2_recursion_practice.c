
#include <stdio.h>
void hello(int i, int n)
{
    if (i == n)
    {
        return;
    }
    printf("I love Recursion \n");
    hello(i + 1, n);
}
int main()
{

    int n;
    scanf("%d", &n);
    hello(1, n + 1);
    return 0;
}